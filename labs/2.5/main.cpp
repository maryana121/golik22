// Golik Maryana 123-1
#include <iostream>

// Заголовковий файл list.h

// список в зв’язному уявленні
// односпрямований список з цілими числами 
struct list {
    int data;   // Значення типу int
    list* next; // Вказівник на наступний елемент
};

// відкрита підпрограма, що перевіряє, чи є елемент парним
inline bool isEven(list* elem)
{
    return (elem->data % 2 == 0); // Повертає true, якщо елемент парний
}


// Функція для додавання елементів після першого елемента списку
void add(list*& top, int value) {
    list* newNode = new list;  // Створюємо новий елемент
    newNode->data = value;

    if (top == nullptr) {
        // Якщо список порожній, додаємо новий елемент на початок
        top = newNode;
        newNode->next = nullptr;
    }
    else {
        // Додаємо новий елемент після першого
        newNode->next = top->next;
        top->next = newNode;
    }
}

// Функція для формування другого списку з парних значень першого списку
void addNew(list*& secondList, list* firstList) {
    list* temp = firstList;
    list* last = nullptr;

    while (temp != nullptr) {
        if (isEven(temp)) {  // Використовуємо inline функцію для перевірки на парність
            list* cur = new list;
            cur->data = temp->data;
            cur->next = nullptr;

            if (secondList == nullptr) {
                secondList = cur;  // Якщо це перший елемент у другому списку
                last = cur;
            }
            else {
                last->next = cur;  // Додаємо новий елемент в кінець списку
                last = cur;
            }
        }
        temp = temp->next;  // Переходимо до наступного елемента першого списку
    }
}

// Головна програма
int main() {
    list* NewList = nullptr;   // Перший список
    list* NewList2 = nullptr;  // Другий список

    // Додаємо елементи до першого списку
    add(NewList, 5);
    add(NewList, 12);
    add(NewList, 7);
    add(NewList, 20);
    add(NewList, 34);

    // Формуємо другий список з парних значень
    addNew(NewList2, NewList);

    // Виводимо елементи другого списку
    std::cout << "Елементи другого списку (парні): ";
    list* temp = NewList2;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    return 0;
}