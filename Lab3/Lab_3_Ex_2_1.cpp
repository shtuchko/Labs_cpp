#include <iostream>

// Функция сортировки методом пузырька
void bubbleSort(int arr[], int n)
{
    // Внешний цикл - количество проходов
    for(int i = 0; i < n - 1; i++)
    {
        // Внутренний цикл - сравнение соседних элементов
        for(int j = 0; j < n - i - 1; j++)
        {
            // Если текущий элемент больше следующего - меняем местами
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция вывода массива на экран
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
    
    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    printArray(mas, n);
    
    // Сортировка методом пузырька
    bubbleSort(mas, n);
    
    // Вывод отсортированного массива
    std::cout << "Отсортированный массив: ";
    printArray(mas, n);
    
    return 0;
}
