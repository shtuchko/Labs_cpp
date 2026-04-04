#include <graphics.h>   
#include <conio.h>     
#include <stdlib.h>    
#include <math.h>       

// Базовый класс Point (Точка)
class Point {
protected:
    int X, Y;           // координаты
    int Cvet;           // цвет

public:
    // Инициализация точки
    void Init(int XN, int YN, int Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }

    // Виртуальные методы
    virtual void Show() { }
    virtual void Hide() { }

    // Получить текущие координаты
    void Locat(int &XL, int &YL) {
        XL = X;
        YL = Y;
    }

    // Метод Fly (перемещение по экрану с отскоками)
    void Fly(int Cost) {
        Show();
        randomize();                 // инициализация ГСЧ

        int XX, YY;
        // Ждём нажатия клавиши для выхода
        while (!kbhit()) {
            Locat(XX, YY);

            // случайное смещение по X с проверкой границ
            do {
                double r = (double)rand() / RAND_MAX;  
                XX = XX + round((r - 0.5) * Cost);
            } while (XX <= 0 || XX >= getmaxx());

            // случайное смещение по Y с проверкой границ
            do {
                double r = (double)rand() / RAND_MAX;
                YY = YY + round((r - 0.5) * Cost);
            } while (YY <= 0 || YY >= getmaxy());

            Hide();         // стираем старый объект
            X = XX;
            Y = YY;
            Show();         // рисуем на новом месте

            delay(300);     // задержка для мерцания
        }
        getch();            // сброс нажатой клавиши (как Readln в Паскале)
    }
};

// Класс Krug (Круг), наследник Point
class Krug : public Point {
protected:
    int Radius;            // радиус

public:
    // Конструктор
    void Init(int XN, int YN, int R, int Color) {
        Point::Init(XN, YN, Color);
        Radius = R;
        Show();            
    }

    // Переопределённый Show – рисуем закрашенный круг
    void Show() override {
        setcolor(Cvet);
        setfillstyle(1, Cvet);
        pieslice(X, Y, 0, 360, Radius);   
    }

    // Переопределённый Hide – стираем цветом фона
    void Hide() override {
        setcolor(getbkcolor());
        setfillstyle(1, getbkcolor());
        pieslice(X, Y, 0, 360, Radius);
    }
};

// Класс Ring (Кольцо), наследник Krug
class Ring : public Krug {
private:
    int Width;             // толщина кольца

public:
    // Пустой конструктор 
    Ring() { }

    // Инициализация кольца
    void Init(int XN, int YN, int R, int Color, int Wid) {
        Width = Wid;
        Krug::Init(XN, YN, R, Color);
    }

    // Переопределённый Show – сначала рисуем круг, потом вырезаем центр цветом фона
    void Show() override {
        Krug::Show();       // рисуем полный круг
        setfillstyle(10, getbkcolor());   
        pieslice(X, Y, 90, 360, Radius - Width);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TС\\BGI");   

    setbkcolor(80);      
    cleardevice();

    Krug TestKrug;
    Ring TestRing;

    TestKrug.Init(150, 40, 50, 1);        
    TestRing.Init(450, 80, 90, 50, 10);   

    TestKrug.Fly(100);
    TestKrug.Fly(100);
    TestRing.Fly(60);
    TestKrug.Fly(60);

    getch();              

    TestKrug.Hide();
    TestRing.Hide();

    getch();
    closegraph();
    return 0;
}
