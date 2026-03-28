#include <iostream>

// Функция разделения массива
// Возвращает индекс опорного элемента после разделения
int partition(int arr[], int low, int high)
{
    // Выбираем опорный элемент (последний элемент)
    int pivot = arr[high];
    
    // Индекс для элементов, меньших опорного
    int i = low - 1;
    
    // Проходим по всем элементам от low до high-1
    for(int j = low; j < high; j++)
    {
        // Если текущий элемент меньше или равен опорному
        if(arr[j] <= pivot)
        {
            i++;  // Увеличиваем индекс меньших элементов
            // Меняем местами arr[i] и arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Ставим опорный элемент на правильное место
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    // Возвращаем индекс опорного элемента
    return i + 1;
}

// Рекурсивная функция быстрой сортировки
void quickSort(int arr[], int low, int high)
{
    // Если массив содержит более одного элемента
    if(low < high)
    {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);
        
        // Рекурсивно сортируем левую часть (элементы меньше опорного)
        quickSort(arr, low, pi - 1);
        
        // Рекурсивно сортируем правую часть (элементы больше опорного)
        quickSort(arr, pi + 1, high);
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
    
    std::cout << "Исходный массив: ";
    printArray(mas, n);
    
    // Сортировка методом быстрой сортировки
    quickSort(mas, 0, n - 1);
    
    std::cout << "Отсортированный массив: ";
    printArray(mas, n);
    
    return 0;
}