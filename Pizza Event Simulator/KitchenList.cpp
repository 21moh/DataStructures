#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "KitchenList.h"
using namespace std;



void KitchenList::push_back(items thing) {
	foods.push_back(thing);
}

void KitchenList::erase(list<items>::iterator ptr) {
	foods.erase(ptr);
}