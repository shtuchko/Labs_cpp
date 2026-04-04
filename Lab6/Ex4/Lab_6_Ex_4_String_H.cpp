#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char* str;      // указатель на динамическую память
    int length;     // текущая длина строки
    int capacity;   // выделенная ёмкость памяти

public:
    // Конструкторы
    Stroka();                           // по умолчанию
    Stroka(char* string);               // из C-строки
    Stroka(const Stroka& s);            // копирования
    Stroka(int size);                   // НОВЫЙ: создание строки с заданным размером
    
    // Деструктор
    ~Stroka();
    
    // Перегруженные операции
    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s);
    int operator==(const Stroka& s);
    
    // Методы
    int dlena();
    void vvod();
    void vyvod();
    int getCapacity() { return capacity; }  // для демонстрации
};

#endif