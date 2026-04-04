#include <stdio.h>
#include <string.h>

// Функция поиска подстроки в файле
// Параметры: имя_файла, искомая_подстрока, имя_выходного_файла
void findSubstring(const char* filename, const char* substring, const char* outputFile)
{
    FILE *in, *out;
    char line[1000];  // буфер для хранения строки
    int lineNum = 0;
    int foundCount = 0;
    
    // Открываем исходный файл для чтения
    in = fopen(filename, "r");
    if (in == NULL)
    {
        printf("Ошибка: файл %s не открыт\n", filename);
        return;
    }
    
    // Открываем выходной файл для записи результатов
    out = fopen(outputFile, "w");
    if (out == NULL)
    {
        printf("Ошибка: невозможно создать файл %s\n", outputFile);
        fclose(in);
        return;
    }
    
    // Записываем заголовок в выходной файл
    fprintf(out, "Искомая строка: \"%s\"\n", substring);
    fprintf(out, "Файл: %s\n\n", filename);
    
    // Поиск подстроки в каждой строке файла
    while (fgets(line, sizeof(line), in) != NULL)
    {
        lineNum++;
        
        // Проверяем, содержится ли подстрока в текущей строке
        if (strstr(line, substring) != NULL)
        {
            foundCount++;
            
            // Записываем результат в выходной файл
            fprintf(out, "Строка %d: %s", lineNum, line);
            
            // Если строка не заканчивается на \n, добавляем его
            if (line[strlen(line) - 1] != '\n')
                fprintf(out, "\n");
        }
    }
    
    // Записываем итоговую информацию
    fprintf(out, "Найдено вхождений: %d\n", foundCount);
        
    // Закрываем файлы
    fclose(in);
    fclose(out);
}

int main()
{
    char filename[100];
    char substring[100];
    char outputFile[100];
    FILE *in;
    int ch;
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", filename);
    
    if ((in = fopen(filename, "r")) == NULL)
    {
        printf("Файл %s не открыт\n", filename);
        return 1;
    }
    else
    {
        while ((ch = getc(in)) != EOF)
            putchar(ch);
        fclose(in);
    }
    
    printf("Введите искомую подстроку: ");
    scanf("%s", substring);
    
    printf("Введите имя файла для сохранения результатов: ");
    scanf("%s", outputFile);
    
    findSubstring(filename, substring, outputFile);
    
    return 0;
}