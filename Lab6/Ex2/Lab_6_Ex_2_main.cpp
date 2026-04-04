#include "string.h"
#include <iostream>
using namespace std;

void main(void)
{
    // Создание объектов
    Stroka s1("qwert");    // конструктор с параметром
    Stroka s3;             // конструктор по умолчанию
    Stroka s4(s1);         // конструктор копирования
    Stroka s5;             // конструктор по умолчанию
    
    // Ввод строки s3
    cout << "Введите строку для s3: ";
    s3.vvod();
    
    // Присваивание строки
    s3 = "asdfg";
    cout << "s3 после присваивания: ";
    s3.vyvod();
    cout << endl;
    
    // Сцепление строк
    s5 = s1 + s3 + s4;
    cout << "s5 = s1 + s3 + s4 = ";
    s5.vyvod();
    cout << endl;
    
    // Вывод длины строки s5
    cout << "Длина s5 = " << s5.dlena() << endl;
    
    // Сравнение строк
    if (s1 == s5)
        cout << "строки s1 и s5 равны" << endl;
    else if (s1 == s4)
        cout << "строки s1 и s4 равны" << endl;
    else
        cout << "строки не равны" << endl;
}
