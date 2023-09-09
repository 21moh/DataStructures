#ifndef __order_h_
#define __order_h_

#include <cassert>
#include <iostream>
#include <string>
#include <list>
using namespace std;

class order {
public:
order();
order(int id, int promised_time, int n_items, list<string> order_items);
int getID();
int getPtime();
list<string> getFood();

void setID(int id);
void setTime(int promised_time);
void setNitems(int n_items);
void setOrder_Items(list<string> order_items);


private:
	int id_;
	int promised_time_;
	int n_items_;
	list<string> order_items_;

};


#endif