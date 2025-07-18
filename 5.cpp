#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#ifdef _WIN32
#include <Windows.h>
#endif
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    const double INTEREST_RATE = 0.06;
    const double INFLATION_RATE = 0.035;
    const int YEARS = 10;

    double initialAmount;
    cout << "Введите начальную сумму вклада (руб.): ";
    cin >> initialAmount;

    cout << "\nГод | Сумма на вкладе | Реальная стоимость (с учетом инфляции)\n";
    cout << "----|-----------------|----------------------------------------\n";

    double currentAmount = initialAmount;
    for (int year = 1; year <= YEARS; ++year) {
        currentAmount *= (1 + INTEREST_RATE);
        double realValue = currentAmount / pow(1 + INFLATION_RATE, year);

        cout << setw(3) << year << " | "
            << fixed << setprecision(2) << setw(15) << currentAmount << " | "
            << setw(15) << realValue << endl;
    }

    return 0;
}