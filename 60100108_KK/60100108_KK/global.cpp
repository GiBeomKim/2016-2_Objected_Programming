#include "global.h"

void Global::clrscr()  //ȭ���� ����� �޼���
{
	system("cls");
}

int Global::getnum()  //������ �Է¹޴� �޼���
{
	int num;
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	sscanf(buf, "%d", &num);
	return num;
}

string Global::getstr()  //���ڿ��� �Է¹޴� �޼���
{
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	return buf;
}
