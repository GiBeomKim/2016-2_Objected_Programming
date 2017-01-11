#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

//공통적으로 사용할 정적 메서드를 캡슐화한 클래스
class Global {
public:
	Global() { }
	~Global() {}
	static void clrscr();  //화면을 지우는 메서드
	static int getnum();  //정수를 입력받는 메서드
	static string getstr();  //문자열을 입력받는 메서드
};
