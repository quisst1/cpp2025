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

    int intPart = static_cast<int>(number);
    double fractPart = number - integerPart;
    double roundedValue = round(number);

    cout << "Целая часть: " << intPart << endl;
    cout << "Дробная часть: " << fixed << setprecision(6) << fractPart << endl;
    cout << "Округлённое значение: " << roundedValue << endl;

    return 0;
}