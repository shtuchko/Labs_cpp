#include "string.h"
#include <cstring>
using namespace std;

int my_strlen(char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void my_strcpy(char* dest, char* src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int my_strcmp(char* str1, char* str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

void my_strcat(char* dest, char* src)
{
    while (*dest != '\0')
        dest++;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Конструктор по умолчанию
Stroka::Stroka()
{
    length = 0;
    capacity = 1;
    str = new char[capacity];
    str[0] = '\0';
    cout << "Конструктор по умолчанию: capacity=" << capacity << endl;
}

// Конструктор из C-строки
Stroka::Stroka(char* string)
{
    length = my_strlen(string);
    capacity = length + 1;
    str = new char[capacity];
    my_strcpy(str, string);
    cout << "Конструктор из C-строки: \"" << str << "\", capacity=" << capacity << endl;
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s)
{
    length = s.length;
    capacity = s.capacity;
    str = new char[capacity];
    my_strcpy(str, const_cast<char*>(s.str));
    cout << "Конструктор копирования: \"" << str << "\", capacity=" << capacity << endl;
}

// Создание строки с заданным размером динамической памяти
Stroka::Stroka(int size)
{
    if (size < 1) size = 1;  // минимальный размер
    
    length = 0;               // строка пустая
    capacity = size;          // заданная ёмкость
    str = new char[capacity];
    str[0] = '\0';
    cout << "Конструктор с размером: capacity=" << capacity << " (пустая строка)" << endl;
}

// Деструктор
Stroka::~Stroka()
{
    cout << "Деструктор: удаляется строка \"" << str << "\"" << endl;
    delete[] str;  // освобождаем динамическую память
}

// Перегруженные операции

Stroka& Stroka::operator=(const Stroka& s)
{
    if (this != &s) {
        delete[] str;  // освобождаем старую память
        
        length = s.length;
        capacity = s.capacity;
        str = new char[capacity];
        my_strcpy(str, const_cast<char*>(s.str));
        cout << "Оператор присваивания: \"" << str << "\"" << endl;
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s)
{
    Stroka result;
    delete[] result.str;
    
    result.length = length + s.length;
    result.capacity = result.length + 1;
    result.str = new char[result.capacity];
    
    my_strcpy(result.str, str);
    my_strcat(result.str, const_cast<char*>(s.str));
    cout << "Оператор сцепления: \"" << result.str << "\"" << endl;
    
    return result;
}

int Stroka::operator==(const Stroka& s)
{
    return my_strcmp(str, const_cast<char*>(s.str)) == 0 ? 1 : 0;
}

int Stroka::dlena()
{
    return length;
}

void Stroka::vvod()
{
    char buffer[1000];
    cin >> buffer;
    
    // Пересчитываем длину и перевыделяем память при необходимости
    int newLen = my_strlen(buffer);
    if (newLen + 1 > capacity) {
        delete[] str;
        capacity = newLen + 1;
        str = new char[capacity];
    }
    
    my_strcpy(str, buffer);
    length = newLen;
}

void Stroka::vyvod()
{
    cout << str;
}