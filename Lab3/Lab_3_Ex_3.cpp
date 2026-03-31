#include <iostream>

// Функция сортировки чётных по возрастанию, нечётных по убыванию
void sortEvenOdd(int arr[], int n)
{
    // Создаём временные массивы для чётных и нечётных элементов
    int* evenArr = new int[n];  // массив для чётных
    int* oddArr = new int[n];   // массив для нечётных
    int evenCount = 0;
    int oddCount = 0;
    
    // Разделяем элементы на чётные и нечётные
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)  // чётное
        {
            evenArr[evenCount] = arr[i];
            evenCount++;
        }
        else  // нечётное
        {
            oddArr[oddCount] = arr[i];
            oddCount++;
        }
    }
    
    // Сортируем чётные по возрастанию
    for(int i = 0; i < evenCount - 1; i++)
    {
        for(int j = 0; j < evenCount - i - 1; j++)
        {
            if(evenArr[j] > evenArr[j + 1])
            {
                int temp = evenArr[j];
                evenArr[j] = evenArr[j + 1];
                evenArr[j + 1] = temp;
            }
        }
    }
    
    // Сортируем нечётные по убыванию
    for(int i = 0; i < oddCount - 1; i++)
    {
        for(int j = 0; j < oddCount - i - 1; j++)
        {
            if(oddArr[j] < oddArr[j + 1])  // по убыванию
            {
                int temp = oddArr[j];
                oddArr[j] = oddArr[j + 1];
                oddArr[j + 1] = temp;
            }
        }
    }
    
    // Собираем результат: сначала чётные, затем нечётные
    int index = 0;
    for(int i = 0; i < evenCount; i++)
    {
        arr[index] = evenArr[i];
        index++;
    }
    for(int i = 0; i < oddCount; i++)
    {
        arr[index] = oddArr[i];
        index++;
    }
    
    // Освобождаем память
    delete[] evenArr;
    delete[] oddArr;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    
    std::cout << "Исходный массив: ";
    printArray(mas, n);
    
    // Сортировка
    sortEvenOdd(mas, n);
    
    std::cout << "После сортировки: ";
    printArray(mas, n);
    
    return 0;
}
