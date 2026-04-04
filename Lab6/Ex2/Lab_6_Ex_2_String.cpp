#include "string.h"
#include <cstring>  
using namespace std;

// Конструктор по умолчанию
Stroka::Stroka()
{
    str[0] = '\0';  // пустая строка
}

// Конструктор из C-строки
Stroka::Stroka(char* string)
{
    strcpy(str, string);
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s)
{
    strcpy(str, s.str);
}

// Перегрузка оператора присваивания (=)
Stroka& Stroka::operator=(const Stroka& s)
{
    if (this != &s) {  // проверка на самоприсваивание
        strcpy(str, s.str);
    }
    return *this;
}

// Перегрузка оператора сцепления (+)
Stroka& Stroka::operator+(const Stroka& s)
{
    strcat(str, s.str);  // добавляем s.str в конец текущей строки
    return *this;
}

// Перегрузка оператора сравнения (==)
int Stroka::operator==(const Stroka& s)
{
    if (strcmp(str, s.str) == 0)
        return 1;   // строки равны
    else
        return 0;   // строки не равны
}

// Определение длины строки
int Stroka::dlena()
{
    return strlen(str);
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