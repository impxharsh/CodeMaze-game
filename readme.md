# 🎮 CodeMaze - Console Based C++ Quiz Game

CodeMaze is a fun, terminal-based quiz game built in C++ to reinforce DSA concepts through gameplay.

## 🚀 Features
- 5x5 maze board
- Levels with increasing difficulty
- Random DSA questions at each step
- 3-life system (game over on wrong answers)
- Color-coded console output for enhanced UX

## 🛠 Tech Stack
- C++
- STL (`vector`, `string`)
- Terminal escape sequences for colors

## 🧠 Gameplay
- Move forward by rolling a dice
- Answer a question to proceed
- Wrong answer? Lose a life.
- Reach the end to win the trophy 🏆

## ▶️ Run the Game

```bash
g++ main.cpp game.cpp -o codeMaze
./codeMaze
