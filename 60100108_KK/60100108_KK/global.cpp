#include "global.h"

void Global::clrscr()  //화면을 지우는 메서드
{
	system("cls");
}

int Global::getnum()  //정수를 입력받는 메서드
{
	int num;
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	sscanf(buf, "%d", &num);
	return num;
}

string Global::getstr()  //문자열을 입력받는 메서드
{
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	return buf;
}
