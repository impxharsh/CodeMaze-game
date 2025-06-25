
#include <iostream>
#include <vector>
#include <cstdlib>
#include "game.h"
using namespace std;

const int size = 5;
vector<vector<cell>> maze(size, vector<cell>(size));
int playerX = 4, playerY = 0;
vector<Question> levelQuestions[6];

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void initMaze() {
    int count = 1;
    for (int i = size - 1; i >= 0; i--) {
        if ((size - 1 - i) % 2 == 0) {
            for (int j = 0; j < size; j++) {
                maze[i][j].num = count++;
                maze[i][j].penaltyTo = max(1, count - 5);
                maze[i][j].display = '.';
            }
        } else {
            for (int j = size - 1; j >= 0; j--) {
                maze[i][j].num = count++;
                maze[i][j].penaltyTo = max(1, count - 5);
                maze[i][j].display = '.';
            }
        }
    }
    maze[playerX][playerY].display = 'P';
}

void drawMaze() {
    cout << BLUE << "\n=== CODE MAZE BOARD ===" << RESET << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j].display == 'P')
                cout << GREEN << "[P]" << RESET << " ";
            else
                cout << "[" << maze[i][j].display << "] ";
        }
        cout << endl;
    }
}

void movePlayer(int steps) {
    int curr = maze[playerX][playerY].num;
    int newPos = curr + steps;

    if (newPos > size * size) {
        cout << YELLOW << "Roll too big! Try again!" << RESET << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j].num == newPos) {
                maze[playerX][playerY].display = '.';
                playerX = i;
                playerY = j;
                maze[playerX][playerY].display = 'P';
                return;
            }
        }
    }
}

void initQuestions() {
    levelQuestions[1] = {
        {"Time complexity of binary search?", {"O(n)", "O(log n)", "O(n log n)", "O(1)"}, 'B'},
        {"Which DS is FIFO?", {"Stack", "Queue", "Heap", "Graph"}, 'B'},
        {"Operator for pointer access?", {"*", "->", ".", "&"}, 'B'},
        {"Loop that runs at least once?", {"for", "while", "do-while", "none"}, 'C'},
        {"Size of int in C++?", {"2", "4", "6", "8"}, 'B'},
        {"Header for vectors?", {"#include<vector>", "#include<set>", "#include<map>", "#include<array>"}, 'A'}
    };

    levelQuestions[2] = {
        {"Worst case of quicksort?", {"n^2", "n log n", "log n", "n"}, 'A'},
        {"What is stack overflow?", {"Low memory", "Rec limit", "Syntax", "Compile error"}, 'B'},
        {"Which is LIFO?", {"Stack", "Queue", "Set", "Heap"}, 'A'},
        {"Merge sort time complexity?", {"O(n)", "O(n^2)", "O(n log n)", "O(log n)"}, 'C'},
        {"Not linear DS?", {"Array", "Linked List", "Graph", "Stack"}, 'C'},
        {"Which sorting is stable?", {"Quick sort", "Merge sort", "Heap sort", "Selection sort"}, 'B'}
    };

    levelQuestions[3] = {
        {"Balanced binary tree height?", {"O(n)", "O(log n)", "O(1)", "O(n log n)"}, 'B'},
        {"DS used in DFS?", {"Queue", "Stack", "Priority Queue", "HashMap"}, 'B'},
        {"Graph with all nodes connected?", {"Tree", "Connected graph", "Complete graph", "Cyclic graph"}, 'C'},
        {"Heap insertion time?", {"O(1)", "O(n)", "O(log n)", "O(n log n)"}, 'C'},
        {"Which DS is used in BFS?", {"Stack", "Queue", "Tree", "Deque"}, 'B'}
    };

    levelQuestions[4] = {
        {"Binary search tree property?", {"Left < Root < Right", "Left > Root > Right", "All same", "None"}, 'A'},
        {"Graph cycles detection?", {"Stack", "Queue", "DFS", "Set"}, 'C'},
        {"Time for inserting into hash table?", {"O(1)", "O(n)", "O(log n)", "O(n^2)"}, 'A'},
        {"Tree traversal order?", {"Inorder", "Preorder", "Postorder", "All of these"}, 'D'},
        {"Max number of edges in complete graph (n nodes)?", {"n(n-1)", "n(n-1)/2", "n^2", "n"}, 'B'}
    };

    levelQuestions[5] = {
        {"Dynamic Programming used for?", {"Greedy", "Overlapping Subproblems", "Divide & Conquer", "Backtracking"}, 'B'},
        {"Dijkstra’s algorithm finds?", {"Shortest Path", "Longest Path", "MST", "Cycles"}, 'A'},
        {"Which is not NP-complete?", {"SAT", "3-SAT", "TSP", "Binary Search"}, 'D'},
        {"Segment Tree used for?", {"Sorting", "Range queries", "Searching", "Graphs"}, 'B'},
        {"Which graph algo uses Union-Find?", {"Prim’s", "Kruskal’s", "Dijkstra", "Bellman-Ford"}, 'B'}
    };
}

bool askRandomQuestionFromLevel(int level) {
    int idx = rand() % levelQuestions[level].size();
    Question &q = levelQuestions[level][idx];

    cout << BLUE << "\nLevel " << level << " Question:\n" << RESET;
    cout << q.text << endl;
    cout << "A. " << q.options[0] << endl;
    cout << "B. " << q.options[1] << endl;
    cout << "C. " << q.options[2] << endl;
    cout << "D. " << q.options[3] << endl;
    cout << YELLOW << "Your answer: " << RESET;
    char ans;
    cin >> ans;

    bool isCorrect = (toupper(ans) == q.correctOption);
    if (isCorrect) cout << GREEN << "\nCorrect!" << RESET << endl;
    else cout << RED << "\nWrong Answer!" << RESET << endl;

    return isCorrect;
}
