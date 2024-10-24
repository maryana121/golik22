//Golik Mariana 123:1
//Variant 6

#include <iostream>
#include <string>

using namespace std;

bool isValidString(const string& word) {
    // Перевірка чи ланцюжок починається на "//"
    if (word.size() < 2 || word[0] != '/' || word[1] != '/') {
        return false;
    }

    // Перевірка решти символів
    for (int i = 2; i < word.size(); ++i) {
        char ch = word[i];
        // Перевіряємо, чи символ є в стандартній таблиці ASCII, і чи не є він '/'
        if (ch == '/') {
            return false;
        }
        if (!(ch >= 32 && ch <= 126)) {
            return false;
        }
    }

    return true;
}

int main() {
    // Приклад ланцюжків для перевірки
    string test1 = "//SCDF:$567";
    string test2 = "//%W";
    string test3 = "//SC/F:$567";

    // Виконання перевірки
    cout << test1 << " є " << (isValidString(test1) ? "коректним" : "некоректним") << " ланцюжком." << endl;
    cout << test2 << " є " << (isValidString(test2) ? "коректним" : "некоректним") << " ланцюжком." << endl;
    cout << test3 << " є " << (isValidString(test3) ? "коректним" : "некоректним") << " ланцюжком." << endl;

    return 0;
}