#include"Menu.h"
using namespace std;

Menu::Menu()
{

}

//չʾ�˵�
void Menu::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "***********��ӭʹ���˺�������    *********" << endl;
	cout << "***********0.�˳�����            *********" << endl;
	cout << "***********1.��ɫ�����˺�����    *********" << endl;
	cout << "***********2.���ɫ��BUFF�˺�����*********" << endl;
	cout << "***********By���������          *********" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void Menu::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

Menu::~Menu()
{

}