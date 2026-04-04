#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;        // указатель на динамический массив символов
    int length;        // длина строки
    
public:
    // Конструкторы

    // Конструктор по умолчанию
    String() : str(nullptr), length(0) {
        str = new char[1];
        str[0] = '\0';
    }
    
    // Конструктор из C-строки
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    
    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    
    // Деструктор
    ~String() {
        delete[] str;
    }
    
    // Оператор присваивания
    String& operator=(const String& other) {
        if (this != &other) {           // проверка на самоприсваивание
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    
    // Оператор сцепления
    String operator+(const String& other) const {
        String result;
        delete[] result.str;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }
    
    // Оператор сравнения
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    
    // Длина строки
    int getLength() const {
        return length;
    }
    
    // Вывод
    void print() const {
        cout << str;
    }
    
    // Ввод
    void input() {
        char buffer[1000];
        cin.getline(buffer, 1000);
        *this = buffer;
    }
    
    // Дружественные операторы
    friend ostream& operator<<(ostream& os, const String& s);
    friend istream& operator>>(istream& is, String& s);
};

ostream& operator<<(ostream& os, const String& s) {
    os << s.str;
    return os;
}

istream& operator>>(istream& is, String& s) {
    char buffer[1000];
    is >> buffer;
    s = buffer;
    return is;
}

// Пример использования
int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + " " + s2;
    
    cout << "s3 = " << s3 << endl;
    cout << "Длина s3: " << s3.getLength() << endl;
    cout << "s1 == s2? " << (s1 == s2 ? "да" : "нет") << endl;
    
    return 0;
}
