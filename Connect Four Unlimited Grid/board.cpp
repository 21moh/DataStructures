#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Board.h"

using namespace std;


Board::Board(string first, string second, string spaces) {
	width = 4;
	height = 5;
	p1 = first;
	p2 = second;
	space = spaces;
	m_data = new string*[width];
	for (int i = 0; i < width; i++) {
		m_data[i] = new string[height];
		for (int j = 0; j < height; j++) {
			m_data[i][j] = spaces;
		}
	}

}


ostream& operator<<(ostream& out, Board& b) {
	for (int i = 0; i < b.height; i++) {
		for (int j = 0; j < b.width; j++) {
			out << b.m_data[j][i];
			if (j != b.width) {
				out << " ";
			}
		}
		out << endl;
	}
	return out;
}	


int Board::numRows() {
	return height;
}

int Board::numColumns() {
	return width;

}

int Board::numTokensInRow(int row) {
	int TokensInRow = 0;
	if (row > (height - 1)) {
		return -1;
	}
	else {
		for (int i = 0; i < width; i++) {
			if (m_data[i][row] != space) {
				TokensInRow++;
			}
		}
		return TokensInRow;
	}
	return 0;

}

int Board::numTokensInColumn(int column) {
	int TokensInColumn = 0;
	if (column > (width-1)) {
		return -1;
	}
	else {
		for (int i = 0; i < height; i++) {
			if (m_data[column][i] != space) {
				TokensInColumn++;
			}
		}
		return TokensInColumn;
	}
	return 0;
}


string Board::WinCondition() {	//checks only horizontal and vertical
	
	//column checker tracker
	int p1check = 0;
	int p2check = 0;
	string checker;

	//row checker tracker
	int p1checkRow = 0;
	int p2checkRow = 0;
	string checker2;

	//checks columns
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			checker = m_data[i][j];
			if (checker == p1) {
				p1check++;
			}
			if (checker == p2) {
				p2check++;
			}
			if (m_data[i][j] != checker && (p1check != 4 || p2check != 4)) {
				p1check = 0;
				p2check = 0;
			}
			else if (p1check == 4 || p2check == 4 ){
				if (p1check == 4) {
					return p1;
				}
				if (p2check == 4) {
					return p2;
				}
			}
		}
	}
	//checks rows
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			checker2 = m_data[j][i];
			if (checker2 == p1) {
				p1checkRow++;
			}
			if (checker2 == p2) {
				p2checkRow++;
			}
			if (m_data[j][i] != checker2 && (p1checkRow != 4 || p2checkRow != 4)) {
				p1checkRow = 0;
				p2checkRow = 0;
			}
			
			else if (p1checkRow == 4 || p2checkRow == 4) {
				if (p1checkRow == 4) {
					return p1;
				}
				if (p2checkRow == 4) {
					return p2;
				}
			}
		}
	}
	return space;
}

string Board::insert(int num, bool condition) {
	//num is the column the item is placed in
	//true is first player, false is second player
	if (num > (width - 1)) {	//if placing outside width dimensions
		string** tmp = new string*[num];
		for (int i = 0; i < num; i++) {
			tmp[i] = new string[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				tmp[i][j] = m_data[i][j];
			}
		}
		for (int i = 0; i < width; i++) {
			delete [] m_data[i];
		}
		delete [] m_data;	
		width++;
		m_data = tmp;
		if (condition == true) {
			m_data[num][0] = p1;
		}
		else if (condition == false) {
			m_data[num][0] = p2;
		}
		return WinCondition();
	}
	else {
		for (int i = height-1; i >= 0; i--) {
			cout << "for loop entered" << endl;
			if (m_data[num][i] == space) {
				cout << "accessed" << endl;
				if (condition == true) {
					cout << "accessed p2" << endl;
					m_data[num][i] = p1;
					return WinCondition();
					break;
				}
				else if (condition == false) {
					m_data[num][i] = p2;
					return WinCondition();
					break;
				}
			}
			else if (m_data[num][i] != space && i == 0) {	//expands board height wise
				cout << "AWDOHAWDOIAWD" << endl;
				height++;
				string* tmp = new string[height];
				for (int j = 0; j < height-1; j++) {
					tmp[j] = m_data[num][j];
				}
				tmp[height-1] = space;
				delete [] m_data[num];	
				cout << "passed" << endl;
				m_data[num] = tmp;
				cout << "passed 2.0" << endl;
				for (int i = 0; i < height; i++) {
					cout << m_data[num][i] << endl;
				}
				return WinCondition();	
				break;	
			}
		}
	}
}
