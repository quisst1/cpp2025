#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale> 
#include <Windows.h> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251); 

    double number;
    cout << "Введите число: ";
    cin >> number;

    int integerPart = static_cast<int>(number);
    double fractionalPart = number - integerPart;
    double roundedValue = round(number);

    cout << "Целая часть: " << integerPart << endl;
    cout << "Дробная часть: " << fixed << setprecision(6) << fractionalPart << endl;
    cout << "Округлённое значение: " << roundedValue << endl;

    return 0;
}