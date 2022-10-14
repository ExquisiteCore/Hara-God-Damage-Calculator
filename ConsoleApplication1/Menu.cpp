#include"Menu.h"
using namespace std;

Menu::Menu()
{

}

//展示菜单
void Menu::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "***********欢迎使用伤害计算器    *********" << endl;
	cout << "***********0.退出工具            *********" << endl;
	cout << "***********1.角色单次伤害计算    *********" << endl;
	cout << "***********2.多角色吃BUFF伤害计算*********" << endl;
	cout << "***********By：咸鱼的闲          *********" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void Menu::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

Menu::~Menu()
{

}