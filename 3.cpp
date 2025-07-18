#include <iostream>
#include <clocale>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

int computeGCD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    char choice;
    do {
        int a, b;

        cout << "Введите два натуральных числа: ";
        cin >> a >> b;

        if (a <= 0 || b <= 0) {
            cout << "Числа должны быть натуральными!" << endl;
        }
        else {
            int gcd = computeGCD(a, b);
            cout << "НОД: " << gcd << endl;
        }

        cout << "Продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}