#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Извлечение номера страницы из строки
int getPageNumber(char* line)
{
    int num = 0;
    int i = 0;
    
    // Ищем первый дефис
    while (line[i] != '\0' && line[i] != '-')
        i++;
    
    if (line[i] == '-')
    {
        i++;
        // Пропускаем пробелы
        while (line[i] == ' ') i++;
        
        // Считываем число
        while (isdigit(line[i]))
        {
            num = num * 10 + (line[i] - '0');
            i++;
        }
    }
    return num;
}

// Очистка строки от номера страницы
void cleanLine(char* line)
{
    char result[1000];
    int i = 0, j = 0;
    int inPageNum = 0;
    
    while (line[i] != '\0')
    {
        // Обнаружили начало номера страницы
        if (line[i] == '-' && !inPageNum)
        {
            inPageNum = 1;
            i++;
            // Пропускаем пробелы
            while (line[i] == ' ') i++;
            // Пропускаем цифры
            while (isdigit(line[i])) i++;
            // Пропускаем пробелы
            while (line[i] == ' ') i++;
            // Проверяем закрывающий дефис
            if (line[i] == '-')
            {
                i++;
                inPageNum = 0;
                continue;
            }
        }
        result[j++] = line[i++];
    }
    result[j] = '\0';
    strcpy(line, result);
}

int main()
{
    char inputFile[100], outputFile[100];
    FILE *in, *out;
    char line[1000];
    char pageBuffer[1000] = "";  // буфер для строк страницы
    int pageNum = 0;
    int hasPage = 0;
    
    printf("Введите имя входного файла: ");
    scanf("%s", inputFile);
    
    printf("Введите имя выходного файла: ");
    scanf("%s", outputFile);
    
    in = fopen(inputFile, "r");
    if (in == NULL)
    {
        printf("Ошибка: не удалось открыть файл %s\n", inputFile);
        return 1;
    }
    
    out = fopen(outputFile, "w");
    if (out == NULL)
    {
        printf("Ошибка: не удалось создать файл %s\n", outputFile);
        fclose(in);
        return 1;
    }
    
    while (fgets(line, sizeof(line), in) != NULL)
    {
        // Проверяем, есть ли в строке символ перехода на новую страницу
        if (strchr(line, '\f') != NULL)
        {
            // Убираем символ '\f'
            char* ff = strchr(line, '\f');
            *ff = '\0';
            
            // Записываем последнюю строку страницы
            if (strlen(pageBuffer) > 0)
            {
                fprintf(out, "%s", pageBuffer);
            }
            
            // Записываем текущую строку
            if (strlen(line) > 0)
            {
                fprintf(out, "%s", line);
            }
            
            // Добавляем номер страницы
            if (hasPage && pageNum > 0)
            {
                fprintf(out, "%d\n", pageNum);
                hasPage = 0;
            }
            
            // Восстанавливаем разделитель страниц
            fprintf(out, "\f\n");
            
            // Сбрасываем буфер
            pageBuffer[0] = '\0';
        }
        else
        {
            // Проверяем, является ли строка первой на странице
            if (pageBuffer[0] == '\0' && strstr(line, "-") != NULL)
            {
                // Извлекаем номер страницы
                pageNum = getPageNumber(line);
                if (pageNum > 0)
                {
                    hasPage = 1;
                    // Очищаем строку от номера
                    cleanLine(line);
                }
            }
            
            // Сохраняем строку в буфер (это последняя строка страницы)
            strcpy(pageBuffer, line);
        }
    }
    
    // Обработка последней страницы
    if (strlen(pageBuffer) > 0)
    {
        fprintf(out, "%s", pageBuffer);
    }
    if (hasPage && pageNum > 0)
    {
        fprintf(out, "%d\n", pageNum);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}