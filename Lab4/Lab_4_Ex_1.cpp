#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
    // Объявление строк
    char str1[50] = "Cat";
    char str2[50] = "Apple";
    char str3[50];

    // strlen() - определение длины строки
    cout << "Строка \"" << str1 << "\" имеет длину: " << strlen(str1) << " символов" << endl;
    cout << "Строка \"" << str2 << "\" имеет длину: " << strlen(str2) << " символов" << endl;
    cout << endl;

    // strcat() - конкатенация строк
    cout << "До объединения: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << endl;
    strcat(str1, " ");
    strcat(str1, str2);
    cout << "После strcat(str1, \" \") и strcat(str1, str2):" << endl;
    cout << "str1 = \"" << str1 << "\"" << endl;
    cout << endl;

    // strcpy() - копирование строк
    cout << "До копирования: str3 = \"" << str3 << "\"" << endl;
    strcpy(str3, str2);
    cout << "После strcpy(str3, str2): str3 = \"" << str3 << "\"" << endl;
    cout << endl;

    // strcmp() - сравнение строк
    int result1 = strcmp(str2, "Apple");
    cout << "strcmp(\"" << str2 << "\", \"Apple\") = " << result1;
    if(result1 == 0)
        cout << " (строки равны)" << endl;
    else if(result1 < 0)
        cout << " (первая строка меньше)" << endl;
    else
        cout << " (первая строка больше)" << endl;
    cout << endl;

    return 0;
}
