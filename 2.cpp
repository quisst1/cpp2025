#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>
using namespace std;


string getAgeSuffix(int age) {
    int lastDigit = age % 10;
    int lastTwoDigits = age % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 19) {
        return "лет";
    }
    if (lastDigit == 1) {
        return "год";
    }
    if (lastDigit >= 2 && lastDigit <= 4) {
        return "года";
    }
    return "лет";
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char choice;
    do {
        int age;
        cout << "Введите возраст человека: ";
        cin >> age;

        if (age <= 0) {
            cout << "Возраст должен быть положительным числом!" << endl;
        }
        else {
            string suffix = getAgeSuffix(age);
            cout << "Вам " << age << " " << suffix << "!" << endl;
        }

        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}