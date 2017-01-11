#include <iostream>
#include <stdlib.h>
#include "memberHandler.h"
#include <fstream>

using namespace std;

MemberHandler::MemberHandler()
{
	mList = NULL;
	num = 0;
}

MemberHandler::~MemberHandler()
{
	deleteAll();
}

void MemberHandler::addMember(Member m) {        //add member into the list
	MemberNode* n = new MemberNode();
	n->member.setPnum(m.getPnum());
	n->member.setAdd(m.getAdd());
	n->member.setName(m.getName());
	n->member.setPoint(m.getPoint());
	n->member.setVip(m.isVip());
	n->member.setUnpaid(m.getUnpaid());

	n->next = NULL;

	if (mList == NULL) {	//linked list로 구현
		mList = n;
		num++;
	}
	else {
		MemberNode *p;
		p = mList;

		while (p->next != NULL)
		{

			p = p->next;
		}
		p->next = n;
		num++;
	}

}

void MemberHandler::deleteMember(string name) {
	MemberNode* p = mList;
	if (p == NULL)
	{
		cout << "Nothing to delete!" << endl;
		return;
	}
	if (p->member.getName() == name) {	//if the first node to be deleted
		mList = mList->next;
		cout << "아래 고객이 삭제되었습니다:" << endl;
		p->member.print();
		delete p;
		num--;
		return;
	}
	while (p->next != NULL) {	//if the middle node to be deleted 
		if (p->next->member.getName() == name) {
			MemberNode* for_del = p->next;
			p->next = for_del->next;
			cout << "아래 고객이 삭제되었습니다:" << endl;
			for_del->member.print();
			delete for_del;
			num--;
			return;
		}
		else {
			p = p->next;
		}
	}
	if ((p->next == NULL) && (p->member.getName() == name)) { //if the last node to be deleted
		MemberNode* keep = mList;
		while (keep->next != p)
		{
			keep = keep->next;
		}
		cout << "아래 고객이 삭제되었습니다:" << endl;
		p->member.print();
		delete p;
		num--;
		keep->next = NULL;
		return;
	}
	cout << "The member does not exist." << endl;
}

void MemberHandler::deleteAll() //delete all members into the list
{
	MemberNode* p = mList;
	MemberNode* for_del;
	while (p != NULL)
	{
		for_del = p;
		p = p->next;
		delete for_del;
	}

	mList = NULL;
	num = 0;
	return;
}

MemberNode* MemberHandler::searchName(string name)    //search a member using name
{
	MemberNode* p = mList;

	while (p != NULL)
	{
		if (p->member.getName() == name)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}

	return NULL;
}

MemberNode* MemberHandler::searchPnum(string pnum)	//search a member using phone number
{
	MemberNode* p = mList;

	while (p != NULL)
	{
		if (p->member.getPnum() == pnum)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}

	return NULL;
}

void MemberHandler::searchVip() //모든 VIP 고객들을 검색
{
	MemberNode* p = mList;
	bool existVip = false;

	while (p != NULL)
	{
		if (p->member.isVip() == true)
		{
			p->member.print();
			existVip = true;
		}
		p = p->next;
	}

	if (existVip == false)
	{
		cout << "VIP가 없습니다." << endl;
	}
}


void MemberHandler::print()   //print all members
{
	if (mList == NULL)
	{
		cout << "There is nothing to print." << endl;
		return;
	}

	MemberNode* p = mList;

	for (int i = 0; i < num; i++)
	{
		p->member.print();
		p = p->next;
	}
}

void MemberHandler::save(string filename) { // save the list as a file
	if (mList == NULL) {
		cout << "There is nothing to save." << endl;
		return;
	}

	ofstream output;


	output.open((filename + ".member").c_str());
	if (output.fail())
	{
		cout << "Failed to open file. Check the directory." << endl;
		output.close();
		return;
	}

	MemberNode* p = mList;

	output << num << endl;

	while (p != NULL) {
		output
			<< p->member.getPnum() << "|"
			<< p->member.getAdd() << "|"
			<< p->member.getName() << "|"
			<< p->member.getPoint() << "|"
			<< p->member.isVip() << "|"
			<< p->member.getUnpaid()
			<< endl;
		p = p->next;
	}
	output.close();
	cout << "*** " << filename + ".member 파일이 저장되었습니다." << " ***\n" << endl;
}

void MemberHandler::load(string filename) {	//load the list from file
	ifstream input;

	input.open(filename.c_str());
	if (input.fail())
	{
		cout << "Failed to open file. Check the directory." << endl;
		input.close();
		return;
	}

	if (num != 0)
	{
		char c;
		cout << "There already exists members. Do you want delete them? (y/n)" << endl << "> ";	//if there already exist some members, ask to user
		cin >> c;
		if (c == 'n')
		{
			cout << "Canceled Loading" << endl;
			return;
		}
		else
		{
			deleteAll();
		}
	}
	string str;
	int cnt;
	input >> cnt;
	getline(input, str);
	string token[6];
	int index = 0;

	for (int i = 0; i<cnt; i++)
	{
		index = 0;
		getline(input, str);
		int tmp;

		while (1)
		{
			tmp = str.find("|");
			if (tmp == string::npos) break;  //cannot find
			token[index++] = str.substr(0, tmp);
			str = str.substr(tmp + 1);
		}

		token[index] = str;

		Member m(token[0], token[1], token[2]);
		m.setPoint(atoi(token[3].c_str()));
		if (bool(atoi(token[4].c_str())) == true)
		{
			m.setVip(true);
		}
		else
		{
			m.setVip(false);
		}
		m.setUnpaid(atoi(token[5].c_str()));
		addMember(m);
	}

	input.close();
	cout << "*** " << filename << " 파일을 불러왔습니다." << " ***\n" << endl;
}

void MemberHandler::sortName()	//sort the member using name (ascending)
{
	MemberNode* p, *q;
	for (p = mList; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->member.getName() > q->member.getName())
			{
				Member tmp;

				tmp = p->member;
				p->member = q->member;
				q->member = tmp;
			}
		}
	}
}

void MemberHandler::sortPoint()	//sort the members using point (descending)
{
	MemberNode* p, *q;
	for (p = mList; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->member.getPoint() < q->member.getPoint())
			{
				Member tmp;
				tmp = p->member;
				p->member = q->member;
				q->member = tmp;
			}
		}
	}
}

void MemberHandler::sortVip()	//VIP 된 순서대로 정렬
{
	MemberNode* p, *q;
	for (p = mList; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if ((p->member.isVip() == false) && (q->member.isVip() == true))
			{
				Member tmp;
				tmp = p->member;
				p->member = q->member;
				q->member = tmp;
			}
		}
	}
}
