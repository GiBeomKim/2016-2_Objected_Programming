#ifndef __ORDERHANDLER__H__
#define __ORDERHANDLER__H__

#include "order.h"
#include "handler.h"
#include <string>

using namespace std;

struct Node
{
	Order order;
	Node* next;
};

struct List
{
	Node* front;
	Node* back;
	int size;
};

class OrderHandler : public Handler, public HandlerPrint
{
public:
	List* list;
	int sell;
	int vip;

	OrderHandler();
	~OrderHandler();
	void addOrder(Order);
	void add(Order);
	void addVip(Order);
	//void completeOrder();
	int getSell();
	
	void print();  //all order
	void save(string);    //txt파일로 저장. 확장자는 .order
	void load(string);    //불어오기. 확장자는 .order

	void initializeList();
};

#endif // ORDERHANDLER_H_INCLUDED
