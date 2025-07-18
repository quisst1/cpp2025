#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#ifdef _WIN32
#include <Windows.h>
#endif
using namespace std;

double calculateSeries(double x, double epsilon) {
    double sum = 0.0;
    double term = x;
    int n = 1;

    while (fabs(term) >= epsilon) {
        sum += term;
        n++;
        term = pow(-1, n + 1) * x / n;
    }
    return sum;
}

int main() {
    // Настройка русской локали и кодировки
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    double epsilon;
    cout << "Введите точность вычислений (ε): ";
    cin >> epsilon;

    cout << "\n  x   |  Сумма ряда S(x) |  Точное значение ln(1+x)\n";
    cout << "------|------------------|-------------------------\n";

    cout << fixed << setprecision(5);

    for (double x = -0.5; x <= 0.5; x += 0.1) {
        double sum = calculateSeries(x, epsilon);
        double exactValue = log(1 + x);

        cout << setw(5) << x << " | " << setw(16) << sum << " | " << setw(16) << exactValue << endl;
    }

    return 0;
}