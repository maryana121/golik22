// Golik Maryana 123-1
#include <iostream>
#include <vector>

using namespace std;
//task 1 Замінити в кожній послідовності A[i] мінімальні значення на суму елементів цієї послідовності.
cout << endl;
cout << "Task 1" << endl;

int main() {
    int M, N;

    cout << "Введіть кількість послідовностей (M): ";
    cin >> M;
    cout << "Введіть кількість елементів у кожній послідовності (N): ";
    cin >> N;

    // Динамічне створення матриці
    int** A = new int* [M];
    for (int i = 0; i < M; ++i) {
        A[i] = new int[N];
    }

    // Введення елементів матриці
    cout << "Введіть елементи матриці A[m][n]:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // Основний алгоритм
    for (int i = 0; i < M; ++i) {
        int sum = 0;
        int min_val = numeric_limits<int>::max();  // Початкове мінімальне значення

        // Обчислення суми елементів ряду і знаходження мінімального значення
        for (int j = 0; j < N; ++j) {
            sum += A[i][j];
            if (A[i][j] < min_val) {
                min_val = A[i][j];
            }
        }

        // Заміняємо мінімальні значення на суму елементів ряду
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == min_val) {
                A[i][j] = sum;
            }
        }
    }

    // Виведення результату
    cout << "Оновлена матриця A:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < M; ++i) {
        delete[] A[i];
    }
    delete[] A;
}

        //task 2 Замінити в A[n] входження значень із B[m] на добуток елементів підпослідовності B[m].
        cout << endl;
        cout << "Task 2" << endl;

        int main() {
            cout << "Введіть розмір масивів" << endl;
            int coll;

            cin >> coll;
            cout << endl;

            int* a = new int[coll];
            int* b = new int[coll];

            // Заповнення масивів
            cout << "Введіть елементи для масива A: " << endl;
            populateArray(a, coll);

            cout << "Введіть елементи для масива B: " << endl;
            populateArray(b, coll);

            cout << "Масив A: " << endl;
            coutArray1D(a, coll);

            cout << "Масив B: " << endl;
            coutArray1D(b, coll);

            // Знаходимо добуток елементів B[m]
            int mult = 1;
            for (int i = 0; i < coll; i++) {
                mult *= b[i];
            }

            // Заміна елементів у A[n] на добуток, якщо вони є в B[m]
            for (int i = 0; i < coll; i++) {
                for (int j = 0; j < coll; j++) {
                    if (a[i] == b[j]) {
                        a[i] = mult; // Заміна на добуток
                        break;       // Переходимо до наступного елемента з A
                    }
                }
            }

            cout << endl;

            cout << "Змінений масив A: " << endl;
            coutArray1D(a, coll);

            cout << endl;

            // Звільнення пам'яті
            delete[] a;
            delete[] b;
            a = nullptr;
            b = nullptr;

            return 0;
        }
       
    