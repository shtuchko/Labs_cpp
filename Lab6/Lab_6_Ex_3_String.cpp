#include "string.h"
using namespace std;

// Длина строки с использованием счетчика и индекса
int my_strlen(char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

// Копирование строки 
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

// Сравнение строк 
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

// Конкатенация строк 
void my_strcat(char* dest, char* src)
{
    // Находим конец первой строки
    while (*dest != '\0')
        dest++;
    // Копируем вторую строку в конец первой
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
    str[0] = '\0';
}

// Конструктор из C-строки (используем my_strcpy)
Stroka::Stroka(char* string)
{
    my_strcpy(str, string);
}

// Конструктор копирования (используем my_strcpy)
Stroka::Stroka(const Stroka& s)
{
    // Приводим const к неконстантному указателю
    my_strcpy(str, const_cast<char*>(s.str));
}

// Перегрузка оператора присваивания (используем my_strcpy)
Stroka& Stroka::operator=(const Stroka& s)
{
    if (this != &s) {
        my_strcpy(str, const_cast<char*>(s.str));
    }
    return *this;
}

// Перегрузка оператора сцепления (используем my_strcat)
Stroka& Stroka::operator+(const Stroka& s)
{
    my_strcat(str, const_cast<char*>(s.str));
    return *this;
}

// Перегрузка оператора сравнения (используем my_strcmp)
int Stroka::operator==(const Stroka& s)
{
    if (my_strcmp(str, const_cast<char*>(s.str)) == 0)
        return 1;
    else
        return 0;
}

// Определение длины строки (используем my_strlen)
int Stroka::dlena()
{
    return my_strlen(str);
}

// Ввод строки с клавиатуры
void Stroka::vvod()
{
    cin >> str;
}

// Вывод строки на экран
void Stroka::vyvod()
{
    cout << str;
}
