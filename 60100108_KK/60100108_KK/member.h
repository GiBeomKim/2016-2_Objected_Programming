#ifndef __MEMBER__H__
#define __MEMBER__H__

#include "orderHandler.h"
#include <string>


using namespace std;

class Member
{
private:
	string pnum;
	string add;
	string name;
	int point;

	bool vip;   
	int unpaid;

public:
	Member(string pnum, string add, string name);
	Member();
	void setPnum(string);
	void setAdd(string);
	void setName(string);
	void setUnpaid(int unpaid);
	void setVip(bool);
	void setPoint(int);
	string getPnum();
	string getAdd();
	string getName();
	int getPoint();
	int getUnpaid();
	bool isVip(); //VIP여부

	void payUnpaid(int pay, OrderHandler &oHandler); //외상금액

	void print();
	void operator=(Member&);
};



#endif // MEMBER_H_INCLUDED
