#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char str[80];  // массив для хранения строки

public:
    // Конструкторы
    Stroka();                    // конструктор по умолчанию
    Stroka(char* string);        // конструктор из C-строки
    Stroka(const Stroka& s);     // конструктор копирования
        
    // Перегруженные операции
    Stroka& operator=(const Stroka& s);   // присваивание
    Stroka& operator+(const Stroka& s);   // сцепление
    int operator==(const Stroka& s);      // сравнение
    
    // Методы
    int dlena();                 // определение длины строки
    void vvod();                 // ввод строки
    void vyvod();                // вывод строки
};

#endif