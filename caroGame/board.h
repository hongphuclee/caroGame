#pragma once
#include <vector>
using namespace std;

class board {
private:
	int size;
	vector<vector<char>> grid;
	int cursorX = 0, cursorY = 0;
	int lastMarkX = -1, lastMarkY = -1;
public:
	board(int size);
	int getSize() const;
	vector<vector<char>>getGrid() const;
	int getCursorX() const;
	int getCursorY() const;
	void setCursorX(int x);
	void setCursorY(int y);
	char getCell(int x, int y);
	void setCell(int x, int y, char c);
	int getLastMarkX() const;
	int getLastMarkY() const;;
	void setLastMarkX(int x);
	void setLastMarkY(int y);
	void clearGrid();
};
