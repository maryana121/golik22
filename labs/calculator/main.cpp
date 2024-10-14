#include <iostream>
#include <string>
#include <stack>


using namespace std;

// Функція для визначення пріоритету операторів
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

// Функція для перетворення інфіксного виразу на постфіксний
string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;  // Додаємо операнд до постфіксного виразу
        }
        else if (c == '(') {
            operators.push(c);  // Якщо відкриваюча дужка, додаємо в стек
        }
        else if (c == ')') {
            // Витягуємо оператори зі стеку до закриття дужки
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Видаляємо відкриваючу дужку з стеку
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);  // Додаємо поточний оператор в стек
        }
    }

    // Витягуємо всі залишкові оператори зі стеку
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Функція для виконання арифметичних операцій
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;

    }
}

// Функція для обчислення постфіксного виразу
int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');  // Перетворюємо символ на цифру і додаємо в стек
        }
        else {
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(c, operand1, operand2);
            operands.push(result);
        }
    }

    return operands.top();

}

int main() {
    string infixExpression;
    cout << "Введіть інфіксне вираз: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Постфіксне вираз: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Результат: " << result << endl;

    return 0;
}
