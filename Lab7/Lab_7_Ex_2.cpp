#include <graphics.h>   
#include <conio.h>     
#include <stdlib.h>    
#include <math.h>  

class Point {
protected:
    int X, Y;          
    int Cvet;           

public:
    void Init(int XN, int YN, int Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }

    virtual void Show() { }
    virtual void Hide() { }

    void Locat(int &XL, int &YL) {
        XL = X;
        YL = Y;
    }

    void Fly(int Cost) {
        Show();
        randomize();

        int XX, YY;
        while (!kbhit()) {
            Locat(XX, YY);

            do {
                double r = (double)rand() / RAND_MAX;
                XX = XX + round((r - 0.5) * Cost);
            } while (XX <= 0 || XX >= getmaxx());

            do {
                double r = (double)rand() / RAND_MAX;
                YY = YY + round((r - 0.5) * Cost);
            } while (YY <= 0 || YY >= getmaxy());

            Hide();
            X = XX;
            Y = YY;
            Show();

            delay(300);
        }
        getch();
    }
};

class Krug : public Point {
protected:
    int Radius;         
    int StartAngle;      // начальный угол сектора (для сужения/расширения)
    int EndAngle;        // конечный угол сектора

public:
    void Init(int XN, int YN, int R, int Color) {
        Point::Init(XN, YN, Color);
        Radius = R;
        StartAngle = 0;      // по умолчанию полный круг
        EndAngle = 360;
        Show();
    }

    void Show() override {
        setcolor(Cvet);
        setfillstyle(1, Cvet);
        pieslice(X, Y, StartAngle, EndAngle, Radius);
    }

    void Hide() override {
        setcolor(getbkcolor());
        setfillstyle(1, getbkcolor());
        pieslice(X, Y, StartAngle, EndAngle, Radius);
    }
    
    // Сужение сектора (уменьшение угла)
    void NarrowSector(int delta) {
        // Сужаем с обеих сторон
        StartAngle += delta;
        EndAngle -= delta;
        
        // Проверка границ (чтобы сектор не исчез полностью)
        if (StartAngle >= EndAngle) {
            StartAngle = 0;
            EndAngle = 360;
        }
        
        // Перерисовка
        Hide();
        Show();
    }
    
    // Расширение сектора (увеличение угла)
    void ExpandSector(int delta) {
        // Расширяем с обеих сторон
        StartAngle -= delta;
        EndAngle += delta;
        
        // Проверка границ (максимум полный круг)
        if (StartAngle < 0) StartAngle = 0;
        if (EndAngle > 360) EndAngle = 360;
        
        // Перерисовка
        Hide();
        Show();
    }
    
    // Смена цвета
    void ChangeColor(int NewColor) {
        Cvet = NewColor;
        Hide();
        Show();
    }
    
    // Перемещение с одновременным сужением сектора и сменой цвета
    void FlyWithNarrowing(int Cost, int NarrowStep, int ColorInterval) {
        Show();
        randomize();
        
        int XX, YY;
        int step = 0;
        
        while (!kbhit()) {
            Locat(XX, YY);
            
            // Перемещение
            do {
                double r = (double)rand() / RAND_MAX;
                XX = XX + round((r - 0.5) * Cost);
            } while (XX <= 0 || XX >= getmaxx());
            
            do {
                double r = (double)rand() / RAND_MAX;
                YY = YY + round((r - 0.5) * Cost);
            } while (YY <= 0 || YY >= getmaxy());
            
            Hide();
            X = XX;
            Y = YY;
            
            // Сужение сектора
            NarrowSector(NarrowStep);
            
            // Смена цвета 
            step++;
            if (step % ColorInterval == 0) {
                int newColor = (Cvet % 15) + 1;  
                ChangeColor(newColor);
            }
            
            Show();
            delay(300);
        }
        getch();
    }
    
    // Перемещение с одновременным расширением сектора и сменой цвета
    void FlyWithExpanding(int Cost, int ExpandStep, int ColorInterval) {
        Show();
        randomize();
        
        int XX, YY;
        int step = 0;
        
        while (!kbhit()) {
            Locat(XX, YY);
            
            do {
                double r = (double)rand() / RAND_MAX;
                XX = XX + round((r - 0.5) * Cost);
            } while (XX <= 0 || XX >= getmaxx());
            
            do {
                double r = (double)rand() / RAND_MAX;
                YY = YY + round((r - 0.5) * Cost);
            } while (YY <= 0 || YY >= getmaxy());
            
            Hide();
            X = XX;
            Y = YY;
            
            // Расширение сектора
            ExpandSector(ExpandStep);
            
            // Смена цвета
            step++;
            if (step % ColorInterval == 0) {
                int newColor = (Cvet % 15) + 1;
                ChangeColor(newColor);
            }
            
            Show();
            delay(300);
        }
        getch();
    }
};

class Ring : public Krug {
private:
    int Width;          

public:
    Ring() { }
    
    void Init(int XN, int YN, int R, int Color, int Wid) {
        Width = Wid;
        Krug::Init(XN, YN, R, Color);
    }
    
    void Show() override {
        Krug::Show();
        setfillstyle(10, getbkcolor());
        pieslice(X, Y, 90, 360, Radius - Width);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    setbkcolor(80);
    cleardevice();
    
    Krug TestKrug;
    Ring TestRing;
    
    TestKrug.Init(150, 40, 50, 1);
    TestRing.Init(450, 80, 90, 50, 10);
    
    // Демонстрация новых методов для круга
    TestKrug.FlyWithNarrowing(100, 5, 10);
    
    cleardevice();
    TestKrug.FlyWithExpanding(60, 3, 8);
    
    // Стандартное перемещение для кольца
    TestRing.Fly(60);
    
    getch();
    TestKrug.Hide();
    TestRing.Hide();
    
    getch();
    closegraph();
    return 0;
}