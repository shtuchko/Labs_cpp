#include <stdio.h>

int main()
{
    char name[50];
    FILE *in;
    int ch;          
    int empty = 0;    // счётчик пустых символов
    int not_empty = 0; // счётчик непустых символов
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    
    if ((in = fopen(name, "r")) == NULL)
    {
        printf("Файл %s не открыт\n", name);
        return 1;
    }
    else
    {
        while ((ch = getc(in)) != EOF)
        {
            // Подсчитываем пустые и непустые символы
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || 
                ch == '\f' || ch == '\v' || ch < 32 || ch == 127)
            {
                empty++;  
            }
            else
            {
                not_empty++; 
            }
        }
    }
    
    fclose(in);
    
    // Вывод результатов подсчёта
    printf("Пустых символов:   %d\n", empty);
    printf("Непустых символов: %d\n", not_empty);
    
    return 0;
}