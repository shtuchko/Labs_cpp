#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *in, *out;
    char inputFile[100];
    char outputFile[100];
    char* key;
    int keyLen, keyIndex = 0;
    int ch;
    
    key = argv[1];          // 1-й параметр: ключ шифрования
    keyLen = strlen(key);   // вычисляем длину ключа
    
    // Ввод имён файлов с клавиатуры
    printf("Введите имя входного файла: ");
    scanf("%s", inputFile);
    
    printf("Введите имя выходного файла: ");
    scanf("%s", outputFile);

    // Открываем входной файл в бинарном режиме для чтения
    in = fopen(inputFile, "rb");
    if (in == NULL)
    {
        printf("Ошибка открытия файла %s\n", inputFile);
        return 1;
    }
    
    // Открываем выходной файл в бинарном режиме для записи
    out = fopen(outputFile, "wb");
    if (out == NULL)
    {
        printf("Ошибка создания файла %s\n", outputFile);
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