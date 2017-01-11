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
		cout << "*************** �������� ���! ġŲ ****************** " << endl;
		cout << "******************************************************" << endl;
		cout << "\n�޴��� �������ּ��� (��, �ֹ�, Ŭ����, ������)" << endl << "> ";
		cin >> input;
		if (input == "��")	//Member mode
		{
			cout << "\n<<<<������>>>>" << endl;
			cout << "�޴��� �������ּ��� (��ȸ, �߰�, ����, ���λ���, �˻�, ����, ����, �ҷ�����, ����)" << endl << "> ";
			cin >> input;

			if (input == "�߰�")
			{
				string name, pnum, add;
				cout << "<<<���ο� �� �߰�>>>" << endl << "�̸��� �Է��ϼ���" << endl << "> ";
				cin >> name;
				cout << "�ڵ��� ��ȣ�� �Է��ϼ���" << endl << "> ";
				cin >> pnum;
				cout << "�ּҸ� �Է��ϼ���" << endl << "> ";
				cin >> add;

				Member m(pnum, add, name);
				MemberNode* mp = mHandler.searchName(name);
				if (mp == NULL)
				{
					mHandler.addMember(m);
					cout << "�߰��� ��:" << endl;
					m.print();
				}
				else
				{
					cout << name << " ���� �̹� �����մϴ�." << endl;
					cout << "Information:" << endl;
					mp->member.print();
				}
			}
			else if (input == "����")
			{
				cout << "�����ϰ��� �ϴ� �� �̸��� �Է��ϼ���" << endl << "> ";
				cin >> input;

				mHandler.deleteMember(input);
				g.clrscr();

			}
			else if (input == "���λ���")
			{
				cout << "���� ��� �� ������ ����ʴϱ�? (y/n)" << endl << "> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					mHandler.deleteAll();
					cout << "��� ���� �����Ǿ����ϴ�!" << endl;
				}
				else if (c == 'n')
				{
					cout << "��ҵǾ����ϴ�." << endl;
				}

			}
			else if (input == "��ȸ")
			{
				mHandler.print();
			}
			else if (input == "�˻�")
			{
				cout << "�˻��ϰ��� �ϴ� ������ �������ּ���. (VIP, �̸�, �ڵ��� �� ��1)" << endl << "> ";
				cin >> input;
				if (input == "VIP")
				{
					mHandler.searchVip();
				}
				else if (input == "�̸�")
				{
					cout << "�̸��� �Է����ּ���." << endl << "> ";
					cin >> input;
					MemberNode* mp = mHandler.searchName(input);
					if (mp != NULL)    mp->member.print();
					else
					{
						cout << "The member does not exist." << endl;
					}
				}
				else if (input == "�ڵ���")
				{
					cout << "�ڵ��� ��ȣ�� �Է����ּ���." << endl << "> ";
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
					cout << "�߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
				}
			}
			else if (input == "����")
			{
				cout << "�����ϰ��� �ϴ� ������ �������ּ���. (VIP, �̸�, ����Ʈ �� ��1)" << endl << "> ";
				cin >> input;
				if (input == "VIP")
				{
					mHandler.sortVip();
					mHandler.print();
				}
				else if (input == "�̸�")
				{
					mHandler.sortName();
					mHandler.print();
				}
				else if (input == "����Ʈ")
				{
					mHandler.sortPoint();
					mHandler.print();
				}
				else
				{
					cout << "�߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
				}
			}
			else if (input == "����")
			{
				cout << "������ ���ϸ��� �Է����ּ���." << endl;
				cout << "> ";
				cin >> input;
				mHandler.save(input);
			}
			else if (input == "�ҷ�����")
			{
				cout << "�ҷ������� ���ϸ��� �Է����ּ���(Ȯ���� .member)" << endl;
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
			else if (input == "����")
			{
				g.clrscr();
			}
			else
			{
				cout << "�߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
			}
		}
		else if (input == "�ֹ�")	//Order mode
		{
			cout << "\n<<<<�ֹ�����>>>>" << endl;
			cout << "�޴��� �������ּ���. (�߰�, ��ȸ, VIP����, ����, ����, �ҷ�����, ����)" << endl << "> ";   //�ܻ� ���� ó��
			cin >> input;
			if (input == "�߰�")
			{
				Chicken c;
				string name, add, pnum;
				cout << "***********************" << endl;
				cout << "******* �޴� **********" << endl;
				cout << "***********************" << endl;
				cout << "**�����̵� 15,000 won**" << endl;
				cout << "**��    �� 16,000 won**" << endl;
				cout << "**��    �� 16,000 won**" << endl;
				cout << "***********************" << endl;
				cout << "\n�ֹ� ������ �Է��ϼ���." << endl;
				cout << "ġŲ ���� (�����̵�, ���, �ݹ�): ";
				cin >> c.cname;
				cout << "����: ";
				cin >> c.cnum;
				if ((c.cname != "�����̵�") && (c.cname != "���") && (c.cname != "�ݹ�"))
				{
					cout << "�߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
					continue;
				}

				cout << "����: ";
				cin >> name;
				cout << "��  ��: ";
				cin >> add;
				cout << "��  ȣ: ";
				cin >> pnum;

				Order o(c, name, add, pnum);
				o.calCprice();
				cout << "������ " << o.getCprice() << " �� �Դϴ�." << endl;

				MemberNode *m = mHandler.searchName(name);
				if (m != NULL)
				{
					o.mem = true;
					if (m->member.isVip() == true)
					{
						o.vip = true;
						cout << "�ܻ��Ͻðڽ��ϱ�? (y/n)" << endl << "> ";
						char c;
						cin >> c;
						if (c == 'y')
						{
							o.unpaid = true;
							m->member.setUnpaid(m->member.getUnpaid() + o.getCprice());
						}
						else
						{
							//VIP�� n�� ������ ������ �ϴ� ����
						}
					}
					m->member.setPoint(m->member.getPoint() + (o.getCprice() / 10));  //point up
					cout << "���� ����Ʈ: " << m->member.getPoint() << " ��" << endl;
					if ((m->member.getPoint() > 5000) && (m->member.isVip() == false))	//make vip
					{
						m->member.setVip(true);
						cout << "�����մϴ�! VIP�� �±޵Ǿ����ϴ�!" << endl;
					}
				}

				oHandler.addOrder(o);
			}
			/*
			else if (input == "Ȯ��")
			{
				oHandler.completeOrder();
			}
			*/
			else if (input == "����")
			{
				cout << "���� ����: " << oHandler.getSell() << " ��" << endl;
			}
			else if (input == "��ȸ")
			{
				oHandler.print();
			}
			else if (input == "VIP����")
			{
				cout << "VIP �� �̸��� �Է��ϼ���" << endl;
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
					cout << "���� VIP�� �ƴմϴ�." << endl;
					continue;
				}
				else
				{
					cout << "���� �ܻ� �� �ݾ�: " << m->member.getUnpaid() << " ��" << endl;
					cout<<"���� ���� �Է��ϼ���" << endl;
					cout << "> ";
					int pay;
					cin >> pay;
					m->member.payUnpaid(pay, oHandler);
				}
			}
			else if (input == "����")
			{
				cout << "������ ���ϸ��� �Է��ϼ���." << endl;
				cout << "> ";
				cin >> input;
				oHandler.save(input);
			}
			else if (input == "�ҷ�����")
			{
				cout << "�ҷ��� ���ϸ��� �Է��ϼ���(Ȯ���� .order)" << endl;
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
			else if (input == "����")
			{
				g.clrscr();
			}
			else
			{
				cout << "�߸� �Է��ϼ̽��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
			}
		}
		else if (input == "Ŭ����")
		{
			g.clrscr();
		}
		else if (input == "������")
		{
			if (mHandler.num > 0)
			{
				cout << "������� ���� �� ������ �ֽ��ϴ�. �����Ͻðڽ��ϱ�? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "���ϸ��� �Է��ϼ���." << endl;
					cout << "> ";
					cin >> input;
					mHandler.save(input);
				}
			}
			if (oHandler.list->size > 0)
			{
				cout << "������� ���� �ֹ� ������ �ֽ��ϴ�. �����Ͻðڽ��ϱ�? (y/n)\n> ";
				char c;
				cin >> c;
				if (c == 'y')
				{
					cout << "���ϸ��� �Է��ϼ���." << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �õ����ּ���." << endl;
		}
	}

	return 0;
}
