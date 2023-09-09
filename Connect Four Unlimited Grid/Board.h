#ifndef __BOARD_H
#define __BOARD_H

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class Board {
public:
	Board(string first, string second, string spaces);
	int numRows();
	int numColumns();
	int numTokensInRow(int row);
	int numTokensInColumn(int column);
	string insert(int num, bool condition);
	friend ostream& operator<<(ostream& out, Board& b);

	string WinCondition();

	


private:
string space;
string p1;
string p2;
int height;
int width;
string** m_data;
};

#endif

