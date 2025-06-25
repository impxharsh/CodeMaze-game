#ifndef QUESTION_H
#define QUESTION_H
#include <string>
using namespace std;

struct Question {
    string text;
    string options[4];
    char correctOption;
};

#endif