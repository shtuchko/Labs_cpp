#include <iostream>
#include <iomanip>
#include <cstdlib>    
#include <cmath>      
#include <ctime>      

#define N 5

// Прототипы функций
float findMin(float m[N][N]);
float findMax(float m[N][N]);
float findMinLowerTriangle(float m[N][N]);
float findMaxLowerTriangle(float m[N][N]);
float findMinUpperTriangle(float m[N][N]);
float findMaxUpperTriangle(float m[N][N]);
float findMinMainDiagonal(float m[N][N]);
float findMaxMainDiagonal(float m[N][N]);
float findMinSecondaryDiagonal(float m[N][N]);
float findMaxSecondaryDiagonal(float m[N][N]);
float findAverage(float m[N][N]);
float findAverageLowerTriangle(float m[N][N]);
float findAverageUpperTriangle(float m[N][N]);
void findRowSums(float m[N][N], float rowSums[N]);
void findColumnSums(float m[N][N], float colSums[N]);
void findRowMins(float m[N][N], float rowMins[N]);
void findColumnMins(float m[N][N], float colMins[N]);
void findRowMaxs(float m[N][N], float rowMaxs[N]);
void findColumnMaxs(float m[N][N], float colMaxs[N]);
void findRowAverages(float m[N][N], float rowAvgs[N]);
void findColumnAverages(float m[N][N], float colAvgs[N]);
float findSumLowerTriangle(float m[N][N]);
float findSumUpperTriangle(float m[N][N]);
float findClosestToAverage(float m[N][N]);
void printMatrix(float m[N][N]);

int main()  
{
    float m[N][N];
    
    // Инициализация генератора случайных чисел
    srand(time(0));
    
    // Заполнение матрицы случайными числами
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            m[i][j] = rand() / 10.;
    
    // Вывод исходной матрицы
    std::cout << "Исходная матрица " << N << "x" << N << ":\n";
    printMatrix(m);
    std::cout << std::endl;
    
    // Массивы для хранения результатов
    float rowSums[N], colSums[N];
    float rowMins[N], colMins[N];
    float rowMaxs[N], colMaxs[N];
    float rowAvgs[N], colAvgs[N];
    
    std::cout << "Минимум матрицы: " << findMin(m) << std::endl;
    std::cout << "Максимум матрицы: " << findMax(m) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Максимум нижнетреугольной части: " << findMaxLowerTriangle(m) << std::endl;
    std::cout << "Максимум верхнетреугольной части: " << findMaxUpperTriangle(m) << std::endl;
    std::cout << "Минимум нижнетреугольной части: " << findMinLowerTriangle(m) << std::endl;
    std::cout << "Минимум верхнетреугольной части: " << findMinUpperTriangle(m) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Минимум главной диагонали: " << findMinMainDiagonal(m) << std::endl;
    std::cout << "Максимум главной диагонали: " << findMaxMainDiagonal(m) << std::endl;
    std::cout << "Минимум второстепенной диагонали: " << findMinSecondaryDiagonal(m) << std::endl;
    std::cout << "Максимум второстепенной диагонали: " << findMaxSecondaryDiagonal(m) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Среднеарифметическое матрицы: " << findAverage(m) << std::endl;
    std::cout << "Среднеарифметическое нижнетреугольной части: " << findAverageLowerTriangle(m) << std::endl;
    std::cout << "Среднеарифметическое верхнетреугольной части: " << findAverageUpperTriangle(m) << std::endl;
    std::cout << std::endl;
    
    // Суммы строк и столбцов
    findRowSums(m, rowSums);
    findColumnSums(m, colSums);
    
    std::cout << "Суммы строк матрицы:\n";
    for(int i = 0; i < N; i++)
        std::cout << "Строка " << i << ": " << rowSums[i] << std::endl;
    
    std::cout << "Суммы столбцов матрицы:\n";
    for(int j = 0; j < N; j++)
        std::cout << "Столбец " << j << ": " << colSums[j] << std::endl;
    std::cout << std::endl;
    
    // Минимальные значения строк и столбцов
    findRowMins(m, rowMins);
    findColumnMins(m, colMins);
    
    std::cout << "Минимальные значения строк:\n";
    for(int i = 0; i < N; i++)
        std::cout << "Строка " << i << ": " << rowMins[i] << std::endl;
    
    std::cout << "Минимальные значения столбцов:\n";
    for(int j = 0; j < N; j++)
        std::cout << "Столбец " << j << ": " << colMins[j] << std::endl;
    std::cout << std::endl;
    
    // Максимальные значения строк и столбцов
    findRowMaxs(m, rowMaxs);
    findColumnMaxs(m, colMaxs);
    
    std::cout << "Максимальные значения строк:\n";
    for(int i = 0; i < N; i++)
        std::cout << "Строка " << i << ": " << rowMaxs[i] << std::endl;
    
    std::cout << "Максимальные значения столбцов:\n";
    for(int j = 0; j < N; j++)
        std::cout << "Столбец " << j << ": " << colMaxs[j] << std::endl;
    std::cout << std::endl;
    
    // Среднеарифметические значения строк и столбцов
    findRowAverages(m, rowAvgs);
    findColumnAverages(m, colAvgs);
    
    std::cout << "Среднеарифметические значения строк:\n";
    for(int i = 0; i < N; i++)
        std::cout << "Строка " << i << ": " << rowAvgs[i] << std::endl;
    
    std::cout << "Среднеарифметические значения столбцов:\n";
    for(int j = 0; j < N; j++)
        std::cout << "Столбец " << j << ": " << colAvgs[j] << std::endl;
    std::cout << std::endl;
    
    // Суммы треугольных частей
    std::cout << "Сумма нижнетреугольной части: " << findSumLowerTriangle(m) << std::endl;
    std::cout << "Сумма верхнетреугольной части: " << findSumUpperTriangle(m) << std::endl;
    std::cout << std::endl;
    
    // Элемент, наиболее близкий к среднеарифметическому
    float avg = findAverage(m);
    float closest = findClosestToAverage(m);
    std::cout << "Среднеарифметическое матрицы: " << avg << std::endl;
    std::cout << "Элемент, наиболее близкий к среднеарифметическому: " << closest << std::endl;
    
    // Ожидание нажатия клавиши
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();
    
    return 0;  
}

// Печать матрицы
void printMatrix(float m[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            std::cout << std::setw(15) << std::fixed << std::setprecision(2) << m[i][j];
        std::cout << std::endl;
    }
}

// Минимум матрицы
float findMin(float m[N][N])
{
    float minVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] < minVal)
                minVal = m[i][j];
    return minVal;
}

// Максимум матрицы
float findMax(float m[N][N])
{
    float maxVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(m[i][j] > maxVal)
                maxVal = m[i][j];
    return maxVal;
}

// Максимум нижнетреугольной части
float findMaxLowerTriangle(float m[N][N])
{
    float maxVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(m[i][j] > maxVal)
                maxVal = m[i][j];
    return maxVal;
}

// Максимум верхнетреугольной части
float findMaxUpperTriangle(float m[N][N])
{
    float maxVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            if(m[i][j] > maxVal)
                maxVal = m[i][j];
    return maxVal;
}

// Минимум нижнетреугольной части
float findMinLowerTriangle(float m[N][N])
{
    float minVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(m[i][j] < minVal)
                minVal = m[i][j];
    return minVal;
}

// Минимум верхнетреугольной части
float findMinUpperTriangle(float m[N][N])
{
    float minVal = m[0][0];
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            if(m[i][j] < minVal)
                minVal = m[i][j];
    return minVal;
}

// Минимум главной диагонали
float findMinMainDiagonal(float m[N][N])
{
    float minVal = m[0][0];
    for(int i = 0; i < N; i++)
        if(m[i][i] < minVal)
            minVal = m[i][i];
    return minVal;
}

// Максимум главной диагонали
float findMaxMainDiagonal(float m[N][N])
{
    float maxVal = m[0][0];
    for(int i = 0; i < N; i++)
        if(m[i][i] > maxVal)
            maxVal = m[i][i];
    return maxVal;
}

// Минимум второстепенной диагонали
float findMinSecondaryDiagonal(float m[N][N])
{
    float minVal = m[0][N-1];
    for(int i = 0; i < N; i++)
        if(m[i][N-1-i] < minVal)
            minVal = m[i][N-1-i];
    return minVal;
}

// Максимум второстепенной диагонали
float findMaxSecondaryDiagonal(float m[N][N])
{
    float maxVal = m[0][N-1];
    for(int i = 0; i < N; i++)
        if(m[i][N-1-i] > maxVal)
            maxVal = m[i][N-1-i];
    return maxVal;
}

// Среднеарифметическое всей матрицы
float findAverage(float m[N][N])
{
    float sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sum += m[i][j];
    return sum / (N * N);
}

// Среднеарифметическое нижнетреугольной части
float findAverageLowerTriangle(float m[N][N])
{
    float sum = 0;
    int count = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
        {
            sum += m[i][j];
            count++;
        }
    return sum / count;
}

// Среднеарифметическое верхнетреугольной части
float findAverageUpperTriangle(float m[N][N])
{
    float sum = 0;
    int count = 0;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
        {
            sum += m[i][j];
            count++;
        }
    return sum / count;
}

// Суммы строк матрицы
void findRowSums(float m[N][N], float rowSums[N])
{
    for(int i = 0; i < N; i++)
    {
        rowSums[i] = 0;
        for(int j = 0; j < N; j++)
            rowSums[i] += m[i][j];
    }
}

// Суммы столбцов матрицы
void findColumnSums(float m[N][N], float colSums[N])
{
    for(int j = 0; j < N; j++)
    {
        colSums[j] = 0;
        for(int i = 0; i < N; i++)
            colSums[j] += m[i][j];
    }
}

// Минимальные значения строк
void findRowMins(float m[N][N], float rowMins[N])
{
    for(int i = 0; i < N; i++)
    {
        rowMins[i] = m[i][0];
        for(int j = 1; j < N; j++)
            if(m[i][j] < rowMins[i])
                rowMins[i] = m[i][j];
    }
}

// Минимальные значения столбцов
void findColumnMins(float m[N][N], float colMins[N])
{
    for(int j = 0; j < N; j++)
    {
        colMins[j] = m[0][j];
        for(int i = 1; i < N; i++)
            if(m[i][j] < colMins[j])
                colMins[j] = m[i][j];
    }
}

// Максимальные значения строк
void findRowMaxs(float m[N][N], float rowMaxs[N])
{
    for(int i = 0; i < N; i++)
    {
        rowMaxs[i] = m[i][0];
        for(int j = 1; j < N; j++)
            if(m[i][j] > rowMaxs[i])
                rowMaxs[i] = m[i][j];
    }
}

// Максимальные значения столбцов
void findColumnMaxs(float m[N][N], float colMaxs[N])
{
    for(int j = 0; j < N; j++)
    {
        colMaxs[j] = m[0][j];
        for(int i = 1; i < N; i++)
            if(m[i][j] > colMaxs[j])
                colMaxs[j] = m[i][j];
    }
}

// Среднеарифметические значения строк
void findRowAverages(float m[N][N], float rowAvgs[N])
{
    for(int i = 0; i < N; i++)
    {
        float sum = 0;
        for(int j = 0; j < N; j++)
            sum += m[i][j];
        rowAvgs[i] = sum / N;
    }
}

// Среднеарифметические значения столбцов
void findColumnAverages(float m[N][N], float colAvgs[N])
{
    for(int j = 0; j < N; j++)
    {
        float sum = 0;
        for(int i = 0; i < N; i++)
            sum += m[i][j];
        colAvgs[j] = sum / N;
    }
}

// Сумма нижнетреугольной части
float findSumLowerTriangle(float m[N][N])
{
    float sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            sum += m[i][j];
    return sum;
}

// Сумма верхнетреугольной части
float findSumUpperTriangle(float m[N][N])
{
    float sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            sum += m[i][j];
    return sum;
}

// Элемент, наиболее близкий к среднеарифметическому
float findClosestToAverage(float m[N][N])
{
    float avg = findAverage(m);
    float closest = m[0][0];
    float minDiff = std::fabs(m[0][0] - avg);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            float diff = std::fabs(m[i][j] - avg);
            if(diff < minDiff)
            {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}
