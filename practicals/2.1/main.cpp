// Golik Maryana 123-1
#include <iostream>
#include <vector>

using namespace std;

//task 1 Знайти індекси розміщення мінімального значення в множині.
cout << endl;
cout << "Task 1" << endl;

int main() {
    int M, N;

    cout << "Введіть кількість послідовностей (M): ";
    cin >> M;
    cout << "Введіть кількість елементів у кожній послідовності (N): ";
    cin >> N;

    // Ініціалізація двовимірного масиву
    vector<vector<int>> A(M, vector<int>(N));

    // Введення елементів масиву
    cout << "Введіть елементи масиву A[" << M << "][" << N << "]:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // Ініціалізація змінних для зберігання мінімального значення та його індексів
    int Min = A[0][0];
    int Min_i = 0, Min_j = 0;

    // Пошук мінімального елемента
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] < Min) {
                Min = A[i][j];
                Min_i = i;
                Min_j = j;
            }
        }
    }

    // Виведення результатів
    cout << "Мінімальне значення: " << Min << endl;
    cout << "Індекс мінімального значення: [" << Min_i << "][" << Min_j << "]" << endl;

    //task 2 Знайти максимальне від’ємне значення в множині.
    cout << endl;
    cout << "Task 2" << endl;

    // Пошук максимального від'ємного числа
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coll; j++) {
            if (arr[i][j] > maxNeg && arr[i][j] < 0) {
                maxNeg = arr[i][j];
                foundNegative = true;  // встановлюємо прапорець, якщо знайдено від'ємне число
            }
        }
    }

    // Виведення результату
    if (foundNegative) {
        cout << "Найбільше від'ємне число: " << maxNeg << endl;
    }
    else {
        cout << "Від'ємних чисел немає." << endl;
    }

    return 0;
}