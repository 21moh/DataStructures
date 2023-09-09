#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "items.h"
using namespace std;
//holds time it takes to complete the item and name the idem

items::items() {
	time = 0;
	name = "";
}
items::items(int cook_time, string item_name){
	time = cook_time;
	name = item_name;
}