#include <iostream>
#include <string>

#include "member.h"

using namespace std;

Member::Member(string pnum, string add, string name)
{
	setPnum(pnum);
	setAdd(add);
	setName(name);
	setPoint(0);	//initial point: 0
	vip = false;
	setUnpaid(0);
}

Member::Member()
{
	setPoint(0);
	vip = false;
	setUnpaid(0);
}

void Member::setPnum(string pnum)	//set phone number
{
	this->pnum = pnum;
}

void Member::setAdd(string add)	//set address
{
	this->add = add;
}

void Member::setName(string name)	//set name
{
	this->name = name;
}

void Member::setPoint(int point)	//set point
{
	this->point = point;
}

string Member::getPnum()		//get phone number
{
	return pnum;
}

string Member::getAdd()	//get address
{
	return add;
}

string Member::getName()	//get name
{
	return name;
}

int Member::getPoint()	//get point
{
	return point;
}

void Member::print()	//print the information
{
	cout << "\n***************" << endl;
	cout << "��  ��: " << getName() << endl;
	cout << "��  ��: " << getAdd() << endl;
	cout << "��  ȣ: " << getPnum() << endl;
	cout << "����Ʈ: " << getPoint() << endl;
	cout << "***************\n" << endl;
	if (vip)
	{
		cout << "***VIP***" << endl;
		cout << "�ܻ�ݾ�: " << getUnpaid() << endl;
	}
}

bool Member::isVip()	//VIP���� üũ
{
	return vip;
}

int Member::getUnpaid()	//VIP�� �ܻ��� �� get
{
	return unpaid;
}

void Member::setUnpaid(int unpaid)	//VIP�� �ܻ��� �� set
{
	this->unpaid = unpaid;
}

void Member::setVip(bool tf)
{
	vip = tf;
}

void Member::payUnpaid(int pay, OrderHandler &oHandler)	//VIP�� �ܻ��� �� ����
{
	if (pay > unpaid)
	{
		cout << "Wrong input." << endl;
	}
	else
	{
		oHandler.sell += pay;
		unpaid -= pay;
		cout << "���� �ܻ�ݾ�: " << unpaid << " won" << endl;
	}
}

void Member::operator=(Member &member)	//operator overloading
{
	this->setPnum(member.getPnum());
	this->setAdd(member.getAdd());
	this->setName(member.getName());
	this->setPoint(member.getPoint());
	this->setVip(member.isVip());
	this->setUnpaid(member.getUnpaid());
}
