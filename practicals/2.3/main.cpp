// Golik Maryana 123-1
#include <iostream>
#include <vector>

using namespace std;

//task 1 Сформувати нову послідовність B[m] з від’ємних значень послідовності A[n] та відсортувати її за спаданням алгоритмом вибірки.
cout << endl;
cout << "Task 1" << endl;

// Функція для заповнення масиву користувачем
void populateArray(int* arr, int size) {
    cout << "Введіть " << size << " елементів: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Функція для виведення одномірного масиву
void coutArray1D(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Алгоритм сортування вставкою
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout << "Довжина масиву?" << endl;
    int n;
    cin >> n;

    // Створюємо масив A
    int* arr = new int[n];
    populateArray(arr, n);

    // Виводимо масив A
    cout << "Масив A:" << endl;
    coutArray1D(arr, n);

    // Створюємо масив для від'ємних чисел (B)
    int* arrB;
    int n2 = 0; // Кількість від'ємних елементів

    // Обчислюємо кількість від'ємних елементів
    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            n2++;
        }
    }

    // Перевіряємо, чи є від'ємні числа
    if (n2 == 0) {
        cout << "Немає від'ємних чисел, не можна заповнити масив B" << endl;
    }
    else {
        // Створюємо та заповнюємо масив B від'ємними числами з A
        arrB = new int[n2];
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] < 0) {
                arrB[k] = arr[j];
                k++;
            }
        }

        // Виводимо масив B до сортування
        cout << "Масив B (Від'ємне значення):" << endl;
        coutArray1D(arrB, n2);

        // Сортуємо масив B за допомогою сортування вставкою
        insertionSort(arrB, n2);

        // Виводимо відсортований масив B
        cout << " Відсортований масив B:" << endl;
        coutArray1D(arrB, n2);

        // Видаляємо масив B після використання
        delete[] arrB;
    }

    // Видаляємо масив A після використання
    delete[] arr;

    return 0;
}



//task 2 Відсортувати кожну послідовність за зростанням алгоритмом бульбашки.
#include <iostream>
using namespace std;

// Функція для заповнення масиву користувачем
void populateArray(int* arr, int size) {
    cout << "Введіть " << size << " елементів: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Функція для виведення двовимірного масиву
void coutArray2D(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Алгоритм бульбашкового сортування для одномірного масиву
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    cout << "Введіть рядки та стовпці масиву: ";
    int rows, cols;
    cin >> rows >> cols;

    // Створюємо динамічний двовимірний масив
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Заповнюємо кожний рядок масиву
    for (int i = 0; i < rows; i++) {
        populateArray(arr[i], cols);
    }

    // Виводимо початковий масив
    cout << "Початковий масив:" << endl;
    coutArray2D(arr, rows, cols);

    // Сортуємо кожен рядок масиву за допомогою бульбашкового сортування
    for (int i = 0; i < rows; i++) {
        bubbleSort(arr[i], cols);
    }

    // Виводимо відсортований масив
    cout << "Відсортований масив:" << endl;
    coutArray2D(arr, rows, cols);

    // Очищуємо пам'ять
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
