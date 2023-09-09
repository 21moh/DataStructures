#ifndef __KITCHEN_LIST_h_
#define __KITCHEN_LIST_h_

#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "items.h"
using namespace std;

class KitchenList {
public:
void push_back(items thing);
void erase(list<items>::iterator ptr);

list<items> foods;
private:
	
};


#endif
