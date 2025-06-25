#ifndef GAME_H
#define GAME_H
#include <vector>
#include "quiz.h"
using namespace std;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class cell {
public:
    int num;
    int penaltyTo;
    char display;

    cell() {
        num = 0;
        penaltyTo = 0;
        display = '.';
    }
};

extern vector<vector<cell>> maze;
extern int playerX;
extern int playerY;
extern const int size;
extern vector<Question> levelQuestions[6];

void initMaze();
void drawMaze();
void movePlayer(int steps);
void initQuestions();
bool askRandomQuestionFromLevel(int level);
void clearScreen();

#endif
