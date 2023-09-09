#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "OrderList.h"
using namespace std;

OrderList::OrderList() {

}


bool Timesort(order& a, order& b){
  return ((a.getPtime() == b.getPtime()) || (a.getPtime() < b.getPtime()));
}
bool IDsort(order& a, order& b){
  return ((a.getID() == b.getID()) || (a.getID() < b.getID()));
}



// void OrderList::push_back(order(int id, int promised_time, int n_items, list<string> order_items)) {
// 	order tmp;
// 	tmp.setID(id);
// 	tmp.setPtime(promised_time);
// 	tmp.setNtime(n_items);
// 	tmp.setOrder_Items(list<string> order_items);
// 	orders.push_back(tmp);
// }

void OrderList::push_back(order thingy) {
	orders.push_bacK(thingy);
}

iterator OrderList::begin() {
	return orders.begin();
}

iterator OrderList::end() {
	return orders.end();
}

void OrderList::size() {
	return orders.size();
}

void OrderList::sort() {
	return orders.sort();
}

void OrderList::sort(IDsort) {
	return orders.sort(IDsort);
}

void OrderList::sort(Timesort) {
	return orders.sort(Timesort);
}

int OrderList::size() {
	return orders.size();
}

void OrderList::erase(list<order>::iterator ptr) {
	orders.erase(ptr);
}
