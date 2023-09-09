#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


template<typename T>
std::vector<T> create_copy(std::vector<T> const &vec)
{
    std::vector<T> v(vec.size());
    std::copy(vec.begin(), vec.end(), v.begin());
    return v;
}

class loc {
public:
	loc(int r=0, int c=0) : row(r), col(c) {}
  	int row, col;
};

bool rowcolcheck(const vector<vector<string>>& grid, loc position, int maxstars, string star){
	int row = position.row;
	int col = position.col;
	int rc = 0;
	int cc = 0;
	int diagonal = 0;
	for (unsigned int i = 0; i < grid.size(); i++) {
		if (grid[i][col] == star) {
			cc++;
		}
	}
	for (unsigned int i = 0; i < grid[row].size(); i++) {
		if (grid[row][i] == star) {
			rc++;
		}
	}
	if (row > 0 && col > 0 && row < grid.size()-1 && col < grid[0].size() - 1) { //diagonal checker for centerpiece
		if (grid[row+1][col+1] == "@" || grid[row-1][col-1] == "@" || grid[row+1][col-1] == "@" || grid[row-1][col+1] == "@") {
			diagonal++;
		}
	}	
	// diagonal checker for top left corner
	if (row == 0 && col == 0) {
		if (grid[row+1][col+1] == "@") {
			diagonal++;
		}
	}
	//diagonal checker for bottem left corner
	if (row == grid.size()-1 && col == 0) {
		if (grid[row-1][col+1] == "@") {
			diagonal++;
		}
	}
	//diagonal checker for top right coner
	if (row == 0 && col == grid[0].size()-1){
		if (grid[row+1][col-1] == "@"){
			diagonal++;
		}
	}
	//diagonal checker for bottem right corner
	if (row == grid.size()-1 && col == grid[0].size()-1){
		if (grid[row-1][col-1] == "@"){
			diagonal++;
		}
	}
	//diagonal checker from bottem middle
	if (row == grid.size()-1 && col > 0 && col < grid[0].size()-1) {
		if (grid[row-1][col-1] == "@" || grid[row-1][col+1] == "@"){
			diagonal++;
		}
	}
	//diagonal checker from top middle
	if (row == 0 && col > 0 && col < grid[0].size()-1) {
		if (grid[row+1][col-1] == "@" || grid[row+1][col+1] == "@"){
			diagonal++;
		}
	}
	//diagonal checker from middle of left
	if (col == 0 && row > 0 && row < grid.size()-1) {
		if (grid[row-1][col+1] == "@" || grid[row+1][col+1] == "@"){
			diagonal++;
		}
	}
	//diagonal checker from middle of right
	if (col == grid[0].size()-1 && row > 0 && row < grid.size()-1) {
		if (grid[row-1][col-1] == "@" || grid[row+1][col-1] == "@"){
			diagonal++;
		}
	}


	if (rc >= maxstars || cc >= maxstars || diagonal > 0) {
		return false;
	}
	else {
		return true;
	}
}

void PrintSolutions(vector<vector<vector<string>>>& solutions, ofstream out) {
	for (unsigned int i = 0; i < solutions.size(); i++) {
		out << "\n";
		out << "Solution " << i+1 << ":" << "\n";
		for (unsigned int j = 0; j < solutions[i].size(); j++) {
			for (unsigned int k = 0; k < solutions[i][j].size(); k++) {
				out << solutions[i][j][k];
			}
			out << "\n";
		}
	}
}


class ZoneCounter {
public:
	ZoneCounter(std::string Zone) : letter(Zone) {}
	int counter = 0;
	int occurances = 0;
	int passed = 0;
	std::string letter;
};

bool ZoneSort(const ZoneCounter& obj1, const ZoneCounter& obj2) {
	return obj1.occurances < obj2.occurances;
}

//solution_finder(loc(i,j), copy_grid, copy_Zone, maxstars, solutions, star)

void solution_finder(loc position, vector<vector<string>> board, vector<ZoneCounter> letters, vector<vector<vector<string>>>& solutions, string star, int maxstars, int pass, string lett) {
	int sol = 0;
	if (pass == maxstars * letters.size()) {	//base case -> max stars is the max stars per zone, and letters is a counter of stars per zone
		for (int i = 0; i < letters.size(); i++) {
			sol+=letters[i].counter;
		}
		if (sol == maxstars * letters.size()) {
			solutions.push_back(board);
			return;
		}
	}
	//other base case is checking if all zones have same # stars as max stars
	string tmp;
	if (rowcolcheck(board, position, maxstars, star) == true) {
		for (unsigned int i = 0; i < letters.size(); i++) {
			if (lett == letters[i].letter) {
				if (letters[i].counter < maxstars) {
					board[position.row][position.col] = star; // star = "@"
					letters[i].counter++;
					pass++;
					

					if ((letters[i].counter = maxstars) && (i < letters.size() - 1)) {	//tmp becomes next letter
						tmp = letters[i+1].letter;
	
					} else if (i == letters.size()-1) {
						for (int a = 0; a < letters.size(); a++) {
							if (letters[a].counter == 0) {
								tmp = letters[a].letter;
							}
						}
					} else {
						tmp = letters[i].letter;
					}
				}
				break;
			}
		}
	}
	for (unsigned int i = 0; i < board.size(); i++) {
		for (unsigned int j = 0; j < board[i].size(); j++) {
			
			if (tmp == board[i][j]) {
				if (i == 0 && j == 0) {	//top left corner case
					if ((board[i+1][j+1] != "@") && (board[i][j+1] != "@") && (board[i+1][j] != "@")) {
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
					}
				}
				else if ((i == board.size() - 1) && (j == board[i].size()-1)) {	//bottem right corner case


					if ((board[i][j-1] != "@") && (board[i-1][j] != "@") && (board[i-1][j-1] != "@")) {
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
					}
				}
				else if ((i == board.size() - 1) && (j == 0)) {	//bottem left corner case
					if ((board[i][j+1] != "@") && (board[i-1][j] != "@") && (board[i-1][j+1] != "@")) {
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
					}
				}
				else if ((i == 0) && (j == board[i].size() - 1)) {	//top right corner case
					if ((board[i][j-1] != "@") && (board[i+1][j] != "@") && (board[i+1][j-1] != "@")) {
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
					}
				}
				else if ((i > 0 && i < board.size() - 1) && (j > 0 && j < board[i].size() - 1)) {	//any numbers in the middle
					if ((board[i-1][j] != "@") && (board[i+1][j] != "@") && (board[i][j+1] != "@") && (board[i][j-1] != "@") && (board[i+1][j+1] != "@") && (board[i-1][j-1] != "@") && (board[i+1][j-1] != "@") && (board[i-1][j+1] != "@")) {
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
					}
				}
				else if ((i == 0 && j > 0 && j < board[i].size() - 1)) {	//top middle
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
				}
				else if (i == board.size()-1 && j > 0 && j < board[i].size() - 1) {	//bottem middle
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
				}
				else if (j == 0 && i > 0 && i < board.size() - 1) { //left column middle
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
				}
				else if (j == board[i].size() - 1 && i > 0 && i < board.size()-1) {	//right column middle
						solution_finder(loc(i,j), board, letters, solutions, star, maxstars, pass, tmp);
				} else {
					return;
				}
			}
		}
	}
	return;
}


int main(int argc, char const *argv[]) {
//./a.out [input file] [output file] [stars per zone] [output mode] [solution mode]
	int stars;
	int rows;
	int columns;
	int maxstars;
	std::string star = "@";
	std::string character;
	std::string blank;
	std::string output_mode;
	std::string solution_mode;
	std::vector<std::string> blankrow;
	std::string tmp;
	std::vector<ZoneCounter> zones;
	std::vector<std::string> info;
	std::vector<std::string> letters;
	std::vector<std::vector<std::string>> grid;
	vector<vector<vector<string>>> solutions;
	std::string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//output mode
	//solution mode

	//error checking
	if (argc < 4 || argc > 6) {
		if (argc < 4) {
			std::cerr << "too little arguments" << std::endl;
			exit(1);
		}
		if (argc > 6) {
			std::cerr << "too many arguments" << std::endl;
			exit(1);
		}
	} 

	std::string file = argv[1];
	//maxstars = 1; 
	maxstars = atoi(argv[3]);
	output_mode = argv[4];
	solution_mode = argv[5];
	std::ifstream inFile;
	inFile.open(file);
	if (!inFile) {
		std::cerr << "can't open " << argv[1] << " to read.\n";
		exit(1);
	}
	std::ofstream out(argv[2]);
	stars = *argv[2];
	inFile >> rows >> columns;
	//create empty grid -> vector of vector of single strings
	blank = ".";
	for (int i = 0; i < columns; i++){
		blankrow.push_back(blank);
	}
	for (int i = 0; i < rows; i++){
		grid.push_back(blankrow);
	}

	while (inFile >> character) {
		info.push_back(character);
		if (alpha.find(character) != std::string::npos) {
			letters.push_back(character);
		}
	}
	for (unsigned int i = 0; i < letters.size(); i++){	//creates vector of all zones
		zones.push_back(ZoneCounter(letters[i]));
	}
	
	int k = 0;
	for (unsigned int i = 0; i < info.size() - 1; i+=2){
		if (alpha.find(info[i]) != std::string::npos){
				tmp = letters[k];
				k++;
		}
		else {
			grid[std::stoi(info[i+1])][std::stoi(info[i])] = tmp;
			for (unsigned int j = 0; j < zones.size(); j++){
				if (zones[j].letter == tmp) {
					zones[j].occurances++;
					break;
				}
			}
		}
	}
	k = 0; //just in case
	inFile.close();
	//sort zones by occurances on board (smallest zone to largest zone)
	sort(zones.begin(), zones.end(), ZoneSort);
	std::string tmp2 = zones[0].letter;
	vector<vector<string>> copy_grid;
	vector<ZoneCounter> copy_Zone;
	bool oneS = false;
	int x = 0;
	for (unsigned int i = 0; i < grid.size(); i++) {	//iterating through whole grid
		for (unsigned int j = 0; j < grid[i].size(); j++) {
			if (solution_mode == "one_solution" || solution_mode == "One_Solution" || solution_mode == "One Solution") {
				if (solutions.size() == 1) {
					oneS = true;
					break;
				}
			}
			if (zones[x].passed == zones[x].occurances) { //if entire zone passed, move to next zone
				x++;
				i = 0;
				j = 0;
			}
			if (grid[i][j] == zones[x].letter) {
				copy_grid = grid;
				copy_Zone = zones;
				solution_finder(loc(i,j), copy_grid, copy_Zone, solutions, star, maxstars, 0, zones[x].letter);
				zones[x].passed++; //counter for times that specific point for a letter is passed to the total occurances of the letter (from main)
			}
		}
		if (oneS == true) {
			break;
		}
	}
	vector<vector<string>> oneSolution;
	if (solution_mode == "one_solution") {
		oneSolution = solutions[0];
	}
	else if (solution_mode == "all_solutions") {
	}
		//find all solutions
	if (output_mode == "Count") {
		//only print number of solutions found
		out << "Number of Solutions: " << solutions.size() << "\n";
	}
	else if (output_mode == "Print" || output_mode == "print") {
		//print the count and print all solutions
		if (solution_mode == ("one_solution")){
			out << "Number of Solutions: 1" << endl;
			out << endl;
			for (unsigned int i = 0; i < oneSolution.size(); i++){
				for (unsigned int j = 0; j < oneSolution[i].size(); j++) {
					out << oneSolution[i][j];
				}
				out << "\n";
			}
		} else {
			out << "Number of Solutions: " << solutions.size() << "\n";
			for (unsigned int i = 0; i < solutions.size(); i++) {
				out << "\n";
				out << "Solution " << i+1 << ":" << "\n";
				for (unsigned int j = 0; j < solutions[i].size(); j++) {
					for (unsigned int k = 0; k < solutions[i][j].size(); k++) {
						out << solutions[i][j][k];
						}
					out << "\n";
					}
				}		
			}
		
		}
};	