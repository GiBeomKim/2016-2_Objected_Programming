#ifndef __ORDER__H__
#define __ORDER__H__

#include <string>

using namespace std;

struct Chicken
{
	string cname;//프라이드, 양념, 반반
	int cnum;
	int cprice;
};

class Order
{
protected:
	Chicken chicken; //order
	string name;
	string add; //address
	string pnum;

public:
	Order(Chicken chicken, string name, string add, string pnum);
	Order();

	bool mem;   //whether member or not
	bool vip;
	bool unpaid;

	void setPnum(string);
	void setAdd(string);
	void setName(string);
	string getPnum();
	string getAdd();
	string getName();
	Chicken getChicken();
	void setChicken(Chicken);
	void calCprice();
	int getCprice();

	void print();
};


#endif // ORDER_H_INCLUDED
