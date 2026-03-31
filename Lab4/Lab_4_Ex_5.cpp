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
    // Количество строк в массиве
    const int N = 4;

    // Выделяем память для массива указателей на строки
    char** strings = (char**)calloc(N, sizeof(char*));

    // Выделяем память для каждой строки и инициализируем
    strings[0] = (char*)calloc(50, sizeof(char));
    copy(strings[0], (char*)"Banana");
    
    strings[1] = (char*)calloc(50, sizeof(char));
    copy(strings[1], (char*)"Water");
    
    strings[2] = (char*)calloc(50, sizeof(char));
    copy(strings[2], (char*)"Cherry");
    
    strings[3] = (char*)calloc(50, sizeof(char));
    copy(strings[3], (char*)"Frog");

    // Поиск длины разными способами
    for(int i = 0; i < N; i++)
    {
        cout << "strings[" << i << "] = \"" << strings[i] << "\": ";
        cout << "len1=" << len1(strings[i]) << ", ";
        cout << "len2=" << len2(strings[i]) << ", ";
        cout << "len3=" << len3(strings[i]) << endl;
    }
    cout << endl;

    // Копирование строк
    char* copy_str = (char*)calloc(50, sizeof(char));
    copy(copy_str, strings[0]);
    cout << "Копия strings[0] (\"" << strings[0] << "\"): \"" << copy_str << "\"" << endl;
    free(copy_str);
    cout << endl;

    // Сравнение строк
    for(int i = 0; i < N - 1; i++)
    {
        int cmp = compare(strings[i], strings[i + 1]);
        cout << "Сравнение \"" << strings[i] << "\" и \"" << strings[i + 1] << "\": ";
        if(cmp == 0) cout << "Равны" << endl;
        else if(cmp < 0) cout << "Первая меньше" << endl;
        else cout << "Первая больше" << endl;
        }
    cout << endl;

    // Конкатенация строк
    char* concat_str = (char*)calloc(200, sizeof(char));
    copy(concat_str, strings[0]);
    concat(concat_str, (char*)" ");
    concat(concat_str, strings[1]);
    concat(concat_str, (char*)" ");
    concat(concat_str, strings[2]);
    cout << "Результат конкатенации strings[0] + strings[1] + strings[2]: ";
    cout << "\"" << concat_str << "\"" << endl;
    free(concat_str);

    // Освобождаем память
    for(int i = 0; i < N; i++)
        free(strings[i]);
    free(strings);

    return 0;
}