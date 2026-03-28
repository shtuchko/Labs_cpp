#include <iostream>
using namespace std;

// Макрос для вывода информации об указателе
#define PR(x, type) cout << #x << "=" << reinterpret_cast<unsigned long>(x) \
                         << ", *" << #x << "=" << *x \
                         << ", &" << #x << "=" << reinterpret_cast<unsigned long>(&x) << endl

int main()
{
    // Для типа double
    cout << "Тип double" << endl;
    double mas_double[] = {100.5, 200.5, 300.5};
    double *ptr1_double, *ptr2_double;
    
    ptr1_double = mas_double;
    ptr2_double = &mas_double[2];
    
    PR(ptr1_double, double);
    ptr1_double++;
    PR(ptr1_double, double);
    PR(ptr2_double, double);
    ++ptr2_double;
    cout << "ptr2_double-ptr1_double=" << (ptr2_double - ptr1_double) << endl << endl;
    
    // Для типа char
    cout << "Тип char" << endl;
    char mas_char[] = {'A', 'B', 'C'};
    char *ptr1_char, *ptr2_char;
    
    ptr1_char = mas_char;
    ptr2_char = &mas_char[2];
    
    PR(ptr1_char, char);
    ptr1_char++;
    PR(ptr1_char, char);
    PR(ptr2_char, char);
    ++ptr2_char;
    cout << "ptr2_char-ptr1_char=" << (ptr2_char - ptr1_char) << endl;
    
    return 0;
}