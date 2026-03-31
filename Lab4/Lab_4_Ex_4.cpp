#include <iostream>
#include <cstdlib>
using namespace std;

// 1 способ: длина строки с использованием счетчика и индекса
int len1(char* str)
{
    int len = 0;
    // Пока не встретили нуль, увеличиваем счетчик
    while (str[len] != '\0')
        len++;
    return len;
}

// 2 способ: длина строки через указатель
int len2(char* str)
{
    int len = 0;
    // Идем по указателю, пока не достигнем конца строки
    while (*str != '\0')
    {
        len++;
        str++;  // перемещаем указатель на следующий символ (внутри цикла!)
    }
    return len;
}

// 3 способ: рекурсивный подсчет длины
int len3(char* str)
{
    // Базовый случай: если достигли конца строки
    if (*str == '\0')
        return 0;
    // Рекурсивный случай: 1 + длина оставшейся строки
    return 1 + len3(str + 1);
}

// Копирование строки
void copy(char* dest, char* src)
{
    // Копируем символы из src в dest, включая нуль
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    // добавляем нуль в конец
    *dest = '\0';  
}

// Сравнение строк
int compare(char* str1, char* str2)
{
    // Сравниваем символы, пока не найдем различия или не достигнем конца
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return *str1 - *str2;   // возвращаем разницу кодов символов
        str1++;
        str2++;
    }
    // Если одна строка закончилась, а другая нет
    return *str1 - *str2;
}

// Конкатенация строк
void concat(char* dest, char* src)
{
    // Сначала находим конец первой строки
    while (*dest != '\0')
        dest++;
    // Затем копируем вторую строку в конец первой
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';   // добавляем нуль
}

int main()
{
    // Выделяем динамическую память с помощью calloc()
    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));
    char* str3 = (char*)calloc(100, sizeof(char));
    char* str4 = (char*)calloc(100, sizeof(char));

    // Инициализация строк
    copy(str1, (char*)"Banana");
    copy(str2, (char*)"Water");
    // Очищаем str3 и str4 (устанавливаем пустую строку)
    copy(str3, (char*)"");
    copy(str4, (char*)"");

    cout << "Длина str1=" << len1(str1) << ", str2=" << len1(str2) << endl;
    cout << "Длина str1=" << len2(str1) << ", str2=" << len2(str2) << endl;
    cout << "Длина str1=" << len3(str1) << ", str2=" << len3(str2) << endl;

    copy(str3, str1);
    cout << "Результат копирования: str3=" << str3 << endl;

    cout << "Сравнение \"" << str1 << "\" и \"" << str2 << "\": ";
    int cmp = compare(str1, str2);
    if(cmp == 0) cout << "Равны" << endl;
    else if(cmp < 0) cout << "Первая меньше" << endl;
    else cout << "Первая больше" << endl;

    copy(str4, str1);
    concat(str4, str2);
    cout << "Результат конкатенации: str4=" << str4 << endl;

    // Освобождаем динамическую память
    free(str1);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}