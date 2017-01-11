#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "member.h"
#include "order.h"
#include "memberHandler.h"
#include "orderHandler.h"
#include "global.h"

int main(void)
{
	MemberHandler mHandler;
	OrderHandler oHandler;
	Global g;
	string input;

	while (1)
	{
		cout << "******************************************************" << endl;
		cout << "*************** 교수님이 쏜다! 치킨 ****************** " << endl;
		cout << "******************************************************" << endl;
		cout << "\n메뉴를 선택해주세요 (고객, 주문, 클리어, 나가기)" << endl << "> ";
		cin >> input;
		if (input == "고객")	//Member mode
		{
			cout << "\n<<<<고객관리>>>>" << endl;
			cout << "메뉴를 선택해주세요 (조회, 추가, 삭제, 전부삭제, 검색, 정렬, 저장, 불러오기, 메인)" << endl << "> ";
			cin >> input;

			if (input == "추가")
			{
				string name, pnum, add;
				cout << "<<<새로운 고객 추가>>>" << endl << "이름을 입력하세요" << endl << "> ";
				cin >> name;
				cout << "핸드폰 번호를 입력하세요" << endl << "> ";
				cin >> pnum;
				cout << "주소를 입력하세요" << endl << "> ";
				cin >> add;

				Member m(pnum, add, name);
				MemberNode* mp = mHandler.searchName(name);
				if (mp == NULL)
				{
					mHandler.addMember(m);
					cout << "추가된 고객:" << endl;
					m.print();
				}
				else
				{
					cout << name << " 고객은 이미 존재합니다." << endl;
					cout << "Information:" << endl;
					mp->member.print();
				}
			}
			else if (input == "삭제")
			{
				cout << "삭제하고자 하는 고객 이름을 입력하세요" << endl << "> ";
				cin >> input;

				mHandler.deleteMember(input);
				g.clrscr();

			}
			else if (input == "전부삭제")
			{
				cout << "정말 모든 고객 정보를 지우십니까? (y/n)" << endl << "> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					mHandler.deleteAll();
					cout << "모든 고객이 삭제되었습니다!" << endl;
				}
				else if (c == 'n')
				{
					cout << "취소되었습니다." << endl;
				}

			}
			else if (input == "조회")
			{
				mHandler.print();
			}
			else if (input == "검색")
			{
				cout << "검색하고자 하는 조건을 선택해주세요. (VIP, 이름, 핸드폰 중 택1)" << endl << "> ";
				cin >> input;
				if (input == "VIP")
				{
					mHandler.searchVip();
				}
				else if (input == "이름")
				{
					cout << "이름을 입력해주세요." << endl << "> ";
					cin >> input;
					MemberNode* mp = mHandler.searchName(input);
					if (mp != NULL)    mp->member.print();
					else
					{
						cout << "The member does not exist." << endl;
					}
				}
				else if (input == "핸드폰")
				{
					cout << "핸드폰 번호를 입력해주세요." << endl << "> ";
					cin >> input;
					MemberNode* mp = mHandler.searchPnum(input);
					if (mp != NULL)    mp->member.print();
					else
					{
						cout << "The member does not exist." << endl;
					}
				}
				else
				{
					cout << "잘못 입력하셨습니다. 메인 메뉴로 돌아갑니다." << endl;
				}
			}
			else if (input == "정렬")
			{
				cout << "정렬하고자 하는 조건을 선택해주세요. (VIP, 이름, 포인트 중 택1)" << endl << "> ";
				cin >> input;
				if (input == "VIP")
				{
					mHandler.sortVip();
					mHandler.print();
				}
				else if (input == "이름")
				{
					mHandler.sortName();
					mHandler.print();
				}
				else if (input == "포인트")
				{
					mHandler.sortPoint();
					mHandler.print();
				}
				else
				{
					cout << "잘못 입력하셨습니다. 메인 메뉴로 돌아갑니다." << endl;
				}
			}
			else if (input == "저장")
			{
				cout << "저장할 파일명을 입력해주세요." << endl;
				cout << "> ";
				cin >> input;
				mHandler.save(input);
			}
			else if (input == "불러오기")
			{
				cout << "불러오기할 파일명을 입력해주세요(확장자 .member)" << endl;
				cout << "> ";
				cin >> input;
				if (input.find(".member") == string::npos)
				{
					cout << "Wrong file! Choose .member file." << endl;
				}
				else
				{
					mHandler.load(input);
				}
			}
			else if (input == "메인")
			{
				g.clrscr();
			}
			else
			{
				cout << "잘못 입력하셨습니다. 메인 메뉴로 돌아갑니다." << endl;
			}
		}
		else if (input == "주문")	//Order mode
		{
			cout << "\n<<<<주문관리>>>>" << endl;
			cout << "메뉴를 선택해주세요. (추가, 조회, VIP결제, 매출, 저장, 불러오기, 메인)" << endl << "> ";   //외상 지불 처리
			cin >> input;
			if (input == "추가")
			{
				Chicken c;
				string name, add, pnum;
				cout << "***********************" << endl;
				cout << "******* 메뉴 **********" << endl;
				cout << "***********************" << endl;
				cout << "**프라이드 15,000 won**" << endl;
				cout << "**양    념 16,000 won**" << endl;
				cout << "**반    반 16,000 won**" << endl;
				cout << "***********************" << endl;
				cout << "\n주문 정보를 입력하세요." << endl;
				cout << "치킨 종류 (프라이드, 양념, 반반): ";
				cin >> c.cname;
				cout << "수량: ";
				cin >> c.cnum;
				if ((c.cname != "프라이드") && (c.cname != "양념") && (c.cname != "반반"))
				{
					cout << "잘못 입력하셨습니다. 메인 메뉴로 돌아갑니다." << endl;
					continue;
				}

				cout << "고객명: ";
				cin >> name;
				cout << "주  소: ";
				cin >> add;
				cout << "번  호: ";
				cin >> pnum;

				Order o(c, name, add, pnum);
				o.calCprice();
				cout << "가격은 " << o.getCprice() << " 원 입니다." << endl;

				MemberNode *m = mHandler.searchName(name);
				if (m != NULL)
				{
					o.mem = true;
					if (m->member.isVip() == true)
					{
						o.vip = true;
						cout << "외상하시겠습니까? (y/n)" << endl << "> ";
						char c;
						cin >> c;
						if (c == 'y')
						{
							o.unpaid = true;
							m->member.setUnpaid(m->member.getUnpaid() + o.getCprice());
						}
						else
						{
							//VIP가 n을 누르는 가정은 일단 무시
						}
					}
					m->member.setPoint(m->member.getPoint() + (o.getCprice() / 10));  //point up
					cout << "현재 포인트: " << m->member.getPoint() << " 점" << endl;
					if ((m->member.getPoint() > 5000) && (m->member.isVip() == false))	//make vip
					{
						m->member.setVip(true);
						cout << "축하합니다! VIP로 승급되었습니다!" << endl;
					}
				}

				oHandler.addOrder(o);
			}
			/*
			else if (input == "확정")
			{
				oHandler.completeOrder();
			}
			*/
			else if (input == "매출")
			{
				cout << "현재 매출: " << oHandler.getSell() << " 원" << endl;
			}
			else if (input == "조회")
			{
				oHandler.print();
			}
			else if (input == "VIP결제")
			{
				cout << "VIP 고객 이름을 입력하세요" << endl;
				cout << "> ";
				cin >> input;
				MemberNode *m = mHandler.searchName(input);
				if (m == NULL)
				{
					cout << "That customer does not exist." << endl;
					continue;
				}
				if (m->member.isVip() == false)
				{
					cout << "아직 VIP가 아닙니다." << endl;
					continue;
				}
				else
				{
					cout << "현재 외상 총 금액: " << m->member.getUnpaid() << " 원" << endl;
					cout<<"갚은 돈을 입력하세요" << endl;
					cout << "> ";
					int pay;
					cin >> pay;
					m->member.payUnpaid(pay, oHandler);
				}
			}
			else if (input == "저장")
			{
				cout << "저장할 파일명을 입력하세요." << endl;
				cout << "> ";
				cin >> input;
				oHandler.save(input);
			}
			else if (input == "불러오기")
			{
				cout << "불러올 파일명을 입력하세요(확장자 .order)" << endl;
				cout << "> ";
				cin >> input;
				if (input.find(".order") == string::npos)
				{
					cout << "Wrong file! Choose .order file." << endl;
				}
				else
				{
					oHandler.load(input);
				}
			}
			else if (input == "메인")
			{
				g.clrscr();
			}
			else
			{
				cout << "잘못 입력하셨습니다. 메인 메뉴로 돌아갑니다." << endl;
			}
		}
		else if (input == "클리어")
		{
			g.clrscr();
		}
		else if (input == "나가기")
		{
			if (mHandler.num > 0)
			{
				cout << "저장되지 않은 고객 정보가 있습니다. 저장하시겠습니까? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "파일명을 입력하세요." << endl;
					cout << "> ";
					cin >> input;
					mHandler.save(input);
				}
			}
			if (oHandler.list->size > 0)
			{
				cout << "저장되지 않은 주문 정보가 있습니다. 저장하시겠습니까? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "파일명을 입력하세요." << endl;
					cout << "> ";
					cin >> input;
					oHandler.save(input);
				}
			}
			cout << "Exit the program." << endl;
			return 0;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 다시 시도해주세요." << endl;
		}
	}

	return 0;
}
