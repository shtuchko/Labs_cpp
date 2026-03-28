#include <iostream>

// Функция сортировки пузырьком на интервале по возрастанию
void bubbleSortRange(int arr[], int start, int end)
{
    // Сортируем только элементы от start до end включительно
    for(int i = start; i < end; i++)
    {
        for(int j = start; j < end - (i - start); j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
    
    // Задаём границы интервала для сортировки
    int N1 = 2;  // начальный индекс
    int N2 = 6;  // конечный индекс
    
    // Проверка корректности границ
    if(N1 < 0) N1 = 0;
    if(N2 >= n) N2 = n - 1;
    if(N1 > N2)
    {
        std::cout << "Ошибка: N1 должен быть меньше N2" << std::endl;
        return 1;
    }
    
    std::cout << "Исходный массив: ";
    printArray(mas, n);
    
    // Вывод информации о сортируемом интервале
    std::cout << "Сортировка по возрастанию на интервале индексов [" 
              << N1 << ", " << N2 << "]" << std::endl;
    std::cout << "Элементы на интервале: ";
    for(int i = N1; i <= N2; i++)
        std::cout << mas[i] << " ";
    std::cout << std::endl;
    
    // Сортировка на заданном интервале по возрастанию
    bubbleSortRange(mas, N1, N2);
    
    std::cout << "Результат сортировки: ";
    printArray(mas, n);
    
    return 0;
}