#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *in, *out;
    char* inputFile;   
    char* outputFile;  
    char* key;         
    int keyLen, keyIndex = 0;
    int ch;            
        
    // Получаем параметры из командной строки
    key = argv[1];          // 1-й параметр: ключ шифрования
    inputFile = argv[2];    // 2-й параметр: имя входного файла
    outputFile = argv[3];   // 3-й параметр: имя выходного файла
    
    keyLen = strlen(key);   // вычисляем длину ключа
            
    // Открываем входной файл в бинарном режиме для чтения
    in = fopen(inputFile, "rb");
    if (in == NULL)
    {
        printf("Ошибка: не удалось открыть файл %s\n", inputFile);
        return 1;
    }
    
    // Открываем выходной файл в бинарном режиме для записи
    out = fopen(outputFile, "wb");
    if (out == NULL)
    {
        printf("Ошибка: не удалось создать файл %s\n", outputFile);
        fclose(in);
        return 1;
    }
    
    // Шифрование   
    while ((ch = fgetc(in)) != EOF)
    {
        fputc(ch ^ key[keyIndex], out);
        keyIndex = (keyIndex + 1) % keyLen;
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}