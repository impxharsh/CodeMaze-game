#include <iostream>
#include <ctime>
#include "game.h"
using namespace std;

void show() {
    cout << BLUE;
    cout << "==================================" << endl;
    cout << "         WELCOME TO CODE MAZE     " << endl;
    cout << "=================================="<< endl;
    cout << endl;
    cout << RESET;

    cout << "1. Start Game\n";
    cout << "2. Exit Game\n";
    cout << YELLOW << "Enter choice: " << RESET;
}

void printTrophy() {
    cout << GREEN;
    cout << R"(
     ___________
    '._==_==_=_.'
    .-\:      /-.
   | (|:.     |) |
    '-|:.     |-'
      \::.    /
       '::. .'
         ) (
       _.' '._
      `"""""""`
Congratulations!
)" << RESET << endl;
}

int main() {
    srand(time(0));
    int choice;
    do {
        show();
        cin >> choice;

        switch (choice) {
        case 1: {
            clearScreen();
            cout << YELLOW << "Starting the Game...\n" << RESET;
            initMaze();
            initQuestions();
            int lives = 3;

            while (true) {
                drawMaze();
                cout << GREEN << "Lives Remaining: " << lives << RESET << endl;
                cout << "\nRolling the dice..." << endl;
                int dice = rand() % 6 + 1;
                cout << YELLOW << "You got: " << dice << "!" << RESET << endl;

                int curr = maze[playerX][playerY].num;
                int level = min(5, 1 + (curr - 1) / 5);

                bool correct = askRandomQuestionFromLevel(level);
                if (correct)
                    movePlayer(dice);
                else {
                    lives--;
                    if (lives == 0) {
                        cout << RED << "\nYou are out of lives! Game Over!" << RESET << endl;
                        break;
                    }
                }

                if (maze[playerX][playerY].num == size * size) {
                    printTrophy();
                    break;
                }

                cout << YELLOW << "\nPress Enter to continue..." << RESET;
                cin.ignore();
                cin.get();
                clearScreen();
            }
            break;
        }

        case 2:
            cout << GREEN << "Exiting the Game. Thanks for Playing!" << RESET << endl;
            break;

        default:
            cout << RED << "Invalid option. Try again!" << RESET << endl;
        }
    } while (choice != 2);

    return 0;
}
