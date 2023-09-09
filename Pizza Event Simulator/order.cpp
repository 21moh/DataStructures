#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "order.h"
using namespace std;

order::order() {
	id_ = 0;
	promised_time_ = 0;
	n_items_ = 0;
}

order::order(int id, int promised_time, int n_items, list<string> order_items) {
	id_ = id;
	promised_time_ = promised_time;
	n_items_ = n_items;
	order_items_ = order_items;
}

int order::getID() {
	return id_;
}

int order::getPtime() {
	return promised_time_;
}

list<string> order::getFood() {
	return order_items_;
}

void order::setID(int id) {
	id_ = id;
}

void order::setTime(int promised_time) {
	promised_time_ = promised_time;
}

void order::setNitems(int n_items) {
	n_items_ = n_items;
}

void order::setOrder_Items(list<string> order_items) {
	order_items_ = order_items;
}







