// Golik Maryana 123-1
#include <iostream>

using namespace std;

// task1 Знайти добуток від’ємних чисел усієї множини послідовностей.

void coutArray1D(int* arr, int& coll) {
    for (int i = 0; i < coll; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
}

void coutArray2D(int** arr, int& rows, int& coll) {
    for (int i = 0; i < rows; i++) {
        coutArray1D(arr[i], coll);
    }
    cout << endl;
}

void populateArray(int* arr, int& coll) {
    for (int i = 0; i < coll; i++) {
        arr[i] = rand() % 101 - 50;  // Генеруємо числа від -50 до 50
    }
}

int main() {
    srand(time(0));

    cout << "Введіть рядки та стовпці масиву" << endl;
    int rows, coll;
    cin >> rows >> coll;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[coll];
    }

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < rows; i++) {
        populateArray(arr[i], coll);
    }

    coutArray2D(arr, rows, coll);

    int mult = 1;
    bool hasNegatives = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coll; j++) {
            if (arr[i][j] < 0) {
                mult *= arr[i][j];
                hasNegatives = true;
            }
        }
    }

    if (hasNegatives) {
        cout << "Добуток від'ємних чисел: " << mult << endl;
    }
    else {
        cout << "Немає від'ємних чисел в матриці." << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    return 0;
}
//task 2 Знайти добуток елементів головної діагоналі.
cout << endl;
cout << "Task 2" << endl;

int main() {
    srand(time(0));

    cout << "Введіть рядки та стовпці масиву" << endl;
    int rows, coll;
    cin >> rows >> coll;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[coll];
    }

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < rows; i++) {
        populateArray(arr[i], coll);
    }

    coutArray2D(arr, rows, coll);

    int multTrace = 1;
    for (int i = 0; i < min(rows, coll); i++) {
        multTrace *= arr[i][i];
    }

    cout << "Добуток діагоналі: " << multTrace << endl;

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    return 0;
}


