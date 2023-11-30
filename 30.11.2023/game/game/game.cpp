#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Character {
    string name;
    int health;
    int attack;
    int level;
    int experience;
};

void Attack(Character& attacker, Character& target) {
    int damage = attacker.attack * attacker.level;
    target.health -= damage;
    cout << attacker.name << " наніс " << damage << " одиниць шкоди " << target.name << endl;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Character player1 = { "Гравець 1", 100, 10, 1, 0 };
    Character player2 = { "Гравець 2", 100, 10, 1, 0 };

    while (player1.health > 0 && player2.health > 0) {
        cout << "Гравець 1, виберіть дію:\n";
        cout << "1. Атакувати\n";
        cout << "2. Використати вміння\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Attack(player1, player2);
        }
        else {
            cout << "Невірний вибір дії. Спробуйте ще раз.\n";
            continue;
        }
        cout << "Гравець 2, виберіть дію:\n";
        cout << "1. Атакувати\n";
        cout << "2. Використати вміння\n";
        cin >> choice;

        if (choice == 1) {
            Attack(player2, player1);
        }
        else {
            cout << "Невірний вибір дії. Спробуйте ще раз.\n";
            continue;
        }
        cout << "Стан гравця 1: Здоров'я - " << player1.health << ", Рівень - " << player1.level << endl;
        cout << "Стан гравця 2: Здоров'я - " << player2.health << ", Рівень - " << player2.level << endl;
    }
    if (player1.health <= 0 && player2.health <= 0) {
        cout << "Нічия!" << endl;
    }
    else if (player1.health <= 0) {
        cout << "Переміг Гравець 2!" << endl;
    }
    else {
        cout << "Переміг Гравець 1!" << endl;
    }

    return 0;
}