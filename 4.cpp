#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#ifdef _WIN32
#include <Windows.h>
#endif
using namespace std;

double calculateY(double x, int terms) {
    double result = 1.0;
    double term = 1.0;

    for (int n = 1; n <= terms; ++n) {
        term *= x / n;
        result += term;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    double x;
    cout << "Введите значение x: ";
    cin >> x;

    cout << fixed << setprecision(5);
    cout << "Точное значение e^x: " << exp(x) << endl << endl;

    int terms[] = { 5, 10, 15, 20, 25 };

    for (int n : terms) {
        double y = calculateY(x, n);
        cout << "Слагаемых: " << setw(2) << n << "  Y(x) = " << y << endl;
    }

    return 0;
}