#include <iostream>
using namespace std;

// Передача по значению
void obmen1(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Передача по указателю
void obmen2(int* a, int* b) {
    int tmp = *a;          
    *a = *b;                
    *b = tmp;
}

// Передача по ссылке
void obmen3(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 2, b = 5;
    cout << "до обмена: a=" << a << " b=" << b << endl;
    
    // Вызов obmen1 - передача по значению
    obmen1(a, b);
    cout << "после обмена 1: a=" << a << " b=" << b << endl;   
    
    // Вызов obmen2 - передача по указателю
    obmen2(&a, &b);
    cout << "после обмена 2: a=" << a << " b=" << b << endl;
    
    // Вызов obmen3 - передача по ссылке
    obmen3(a, b);
    cout << "после обмена 3: a=" << a << " b=" << b << endl;

    return 0;

}