#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 1. Функции для работы с интервалами
int countInIntervals(const int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((arr[i] >= -5 && arr[i] <= -2) || (arr[i] >= 2 && arr[i] <= 5)) {
            count++;
        }
    }
    return count;
}

int sumOutsideIntervals(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (!((arr[i] >= -5 && arr[i] <= -2) || (arr[i] >= 2 && arr[i] <= 5))) {
            sum += arr[i];
        }
    }
    return sum;
}

// 2. Функции ввода/вывода и работы с упорядоченными массивами
void inputArray(int* arr, int size) {
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(const int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void insertToSorted(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];
    int pos = 0;

    while (pos < size && arr[pos] < value) {
        newArr[pos] = arr[pos];
        pos++;
    }

    newArr[pos] = value;

    for (int i = pos; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size++;
}

// 3. Функции генерации и фильтрации
void generateRandomArray(int* arr, int size, int min, int max) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int* filterByIntervals(const int* arr, int size, int& newSize) {
    vector<int> temp;
    for (int i = 0; i < size; i++) {
        if ((arr[i] >= -5 && arr[i] <= -2) || (arr[i] >= 2 && arr[i] <= 5)) {
            temp.push_back(arr[i]);
        }
    }

    newSize = temp.size();
    int* result = new int[newSize];
    copy(temp.begin(), temp.end(), result);
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size];

    // 1. Работа с интервалами
    inputArray(arr, size);
    cout << "Количество элементов в интервалах [-5,-2] и [2,5]: "
        << countInIntervals(arr, size) << endl;
    cout << "Сумма элементов вне интервалов: "
        << sumOutsideIntervals(arr, size) << endl;

    // 2. Проверка на упорядоченность и вставка
    if (isSorted(arr, size)) {
        cout << "Массив упорядочен по возрастанию\n";
        int value;
        cout << "Введите значение для вставки: ";
        cin >> value;
        insertToSorted(arr, size, value);
        cout << "Массив после вставки: ";
        printArray(arr, size);
    }
    else {
        cout << "Массив не упорядочен по возрастанию\n";
    }

    // 3. Генерация и фильтрация
    generateRandomArray(arr, size, -10, 10);
    cout << "Сгенерированный массив: ";
    printArray(arr, size);

    int filteredSize;
    int* filteredArr = filterByIntervals(arr, size, filteredSize);
    cout << "Отфильтрованный массив: ";
    printArray(filteredArr, filteredSize);

    delete[] arr;
    delete[] filteredArr;

    return 0;
}