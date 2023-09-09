#ifndef __OrderList_h_
#define __OrderList_h_

#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "order.cpp"
using namespace std;

class OrderList {
public:
Orderlist();
//void push_back(order(int id, int promised_time, int n_items, int order_items));
//void getOrderList();
void push_back(order thingy);
void erase(list<order>::iterator ptr);

std::list<order> orders;

private:

};


#endif