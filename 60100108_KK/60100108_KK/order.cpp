#include <iostream>
#include <string>
#include "order.h"

using namespace std;

Order::Order(Chicken chicken, string name, string add, string pnum)
{
	setChicken(chicken);
	setName(name);
	setAdd(add);
	setPnum(pnum);
	mem = false;
	vip = false;
	unpaid = false;
}

Order::Order()
{
	mem = false;
	vip = false;
	unpaid = false;
}

void Order::setPnum(string pnum)	//set phone number
{
	this->pnum = pnum;
}

void Order::setAdd(string add)	//set address
{
	this->add = add;
}

void Order::setName(string name)	//set name
{
	this->name = name;
}

string Order::getPnum()	//get phone number
{
	return pnum;
}

string Order::getAdd()	//get address
{
	return add;
}

string Order::getName()	//get name
{
	return name;
}

Chicken Order::getChicken()	//get ordered chicken information
{
	return chicken;
}

void Order::setChicken(Chicken chicken)	//set chicken
{
	this->chicken.cname = chicken.cname;
	this->chicken.cprice = chicken.cprice;
	this->chicken.cnum = chicken.cnum;
}

void Order::calCprice()	//calculate chicken price
{
	if (chicken.cname == "�����̵�")
	{
		chicken.cprice = 15000 * chicken.cnum;
	}
	else if (chicken.cname == "���")
	{
		chicken.cprice = 16000 * chicken.cnum;
	}
	else if (chicken.cname == "�ݹ�")
	{
		chicken.cprice = 16000 * chicken.cnum;
	}
}

int Order::getCprice()	//get chicken price
{
	return chicken.cprice;
}

void Order::print()	//print information
{
	cout << "***********" << endl;
	cout << "�̸�: " << getName() << endl;
	cout << "�ּ�: " << getAdd() << endl;
	cout << "��ȣ: " << getPnum() << endl;
	cout << "ġŲ: " << chicken.cname << " " << chicken.cnum <<"��"<< endl;
	cout << "***********" << endl;
	if (vip == true)
	{
		cout << "***VIP***" << endl;
		cout << "�ܻ�ݾ�: ";
		if (unpaid == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	cout << "***************************\n" << endl;
}
