#include <iostream>
#include <vector>
#include <clocale>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

// Функция проверки симметричности матрицы
bool являетсяСимметричной(const vector<vector<int>>& матрица) {
    int n = матрица.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (матрица[i][j] != матрица[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Настройка русской локали
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    int размер;
    cout << "Введите размер квадратной матрицы (n x n): ";
    cin >> размер;

    vector<vector<int>> матрица(размер, vector<int>(размер));

    cout << "\nВведите элементы матрицы построчно:\n";
    for (int i = 0; i < размер; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < размер; ++j) {
            cin >> матрица[i][j];
        }
    }

    cout << "\nВведённая матрица:\n";
    for (const auto& строка : матрица) {
        for (int элемент : строка) {
            cout << элемент << "\t";
        }
        cout << "\n";
    }

    if (являетсяСимметричной(матрица)) {
        cout << "\nМатрица СИММЕТРИЧНА относительно главной диагонали\n";
    }
    else {
        cout << "\nМатрица НЕ симметрична относительно главной диагонали\n";
    }

    // Дополнительная проверка для наглядности
    cout << "\nПроверка симметричных элементов:\n";
    for (int i = 0; i < размер; ++i) {
        for (int j = 0; j < размер; ++j) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = " << матрица[i][j];
            if (i != j) {
                cout << (матрица[i][j] == матрица[j][i] ? " == " : " != ");
                cout << "a[" << j + 1 << "][" << i + 1 << "] = " << матрица[j][i];
            }
            cout << "\n";
        }
    }

    return 0;
}