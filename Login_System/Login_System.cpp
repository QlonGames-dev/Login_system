#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void Register();
void Login();
void Exit();

static bool isLoggedIn = false;

int main() {
    setlocale(LC_ALL, "rus");

    char choice = 0;

    cout << "Регистрация: 1\n"
        << "Войти: 2\n"
        << "Выйти: 3\n"
        << "<< ";

    while (cin >> choice) {
        int ch = atoi(&choice);

        switch (ch) {
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        case 3:
            Exit();
            break;
        default:
            cout << "Вы ввели неверное значение. Повторите снова.\n";
        }
        cout << "<< ";
    }
    return 0;
}

void Register() {
    string username, password;

    cout << "Введите имя для регистрации: ";
    cin >> username;

    cout << "Введите пароль для регистрации: ";
    cin >> password;

    ofstream file;
    file.open("c:\\" + username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Регистрация выполнена успешно.\n";
}

void Login() {
    string username, password, un, pw;

    if (isLoggedIn) {
        cout << "Вы уже авторизованы.\n";
    } else {
        cout << "Введите имя для входа: ";
        cin >> username;

        cout << "Введите пароль для входа: ";
        cin >> password;

        ifstream read("c:\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password) {
            cout << "Вы вошли в систему.\n";
            isLoggedIn = true;
        } else {
            cout << "Вы ввели неправильный логин или пароль.\n";
        }
    }
}

void Exit() {
    if (isLoggedIn) {
        cout << "Вы вышли из системы.\n";
        isLoggedIn = false;
    } else {
        cout << "Вы не авторизованы.\n";
    }
}
