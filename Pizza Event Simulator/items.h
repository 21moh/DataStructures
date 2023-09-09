#ifndef __items_H_
#define __items_H_

#include <cassert>
#include <iostream>
#include <string>
#include <list>
using namespace std;
//holds time it takes to complete the item and name the idem
class items {
public:
	//constructor
	items();
	items(int cook_time, string item_name);
	//accessors
	int getCookTime() {return time;}
	std::string getName() const {return name;}
	//setter
	void SetCookTime(int cook_time) {time = cook_time;}
	void SetName(string name_) {name = name_;}

private:
	int time; 
	std::string name;
};

#endif