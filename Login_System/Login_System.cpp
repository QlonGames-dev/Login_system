#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void Register();
void Login();
void Exit();

static bool isLoggedIn = false;

int main() {
    setlocale(LC_ALL, "rus");

    char choice = 0;

    std::cout << "Регистрация: 1\n"
        << "Войти: 2\n"
        << "Выйти: 3\n"
        << "<< ";

    while (std::cin >> choice) {
        int ch = atoi(&choice); // перевод строки в число

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
            std::cout << "Вы ввели неверное значение. Повторите снова.\n";
        }
        cout << "<< ";
    }
    return 0;
}

void Register() {
    if (isLoggedIn) {                                    //Проверка для регистрации
        std::cout << "Выйдите из системы для регистрации.\n"; //если пользователь в системе
        return;
    }
    std::string username, password;

    std::cout << "Введите имя для регистрации: ";
    std::cin >> username;

    std::cout << "Введите пароль для регистрации: ";
    std::cin >> password;

    ofstream file;
    file.open("c:\\" + username + ".txt");
    file << username << endl << password;
    file.close();

    std::cout << "Регистрация выполнена успешно.\n";
}

void Login() {
    std::string username, password, un, pw;

    if (isLoggedIn) {
        std::cout << "Вы уже авторизованы.\n";
    } else {
        std::cout << "Введите имя для входа: ";
        std::cin >> username;

        std::cout << "Введите пароль для входа: ";
        std::cin >> password;

        ifstream read("c:\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password) {
            std::cout << "Вы вошли в систему.\n";
            isLoggedIn = true;
        } else {
            std::cout << "Вы ввели неправильный логин или пароль.\n";
        }
    }
}

void Exit() {
    if (isLoggedIn) {
        std::cout << "Вы вышли из системы.\n";
        isLoggedIn = false;
    } else {
        std::cout << "Вы не авторизованы.\n";
    }
}
