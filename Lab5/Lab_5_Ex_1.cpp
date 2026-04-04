#include <stdio.h>

int main()
{
    char name[50];
    FILE *in;
    int ch;  // int, чтобы корректно обработать EOF
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    
    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт\n", name);
    else
        while ((ch = getc(in)) != EOF)  // более короткая проверка
            putchar(ch);
    
    fclose(in);  // закрываем файл
    return 0;
}
