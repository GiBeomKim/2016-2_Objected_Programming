#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

//���������� ����� ���� �޼��带 ĸ��ȭ�� Ŭ����
class Global {
public:
	Global() { }
	~Global() {}
	static void clrscr();  //ȭ���� ����� �޼���
	static int getnum();  //������ �Է¹޴� �޼���
	static string getstr();  //���ڿ��� �Է¹޴� �޼���
};
