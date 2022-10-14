// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<string>
#include <iostream>
#include"Totaldamage.h"
#include "Menu.h"
using namespace std;



int main()
{
    Menu menu;
    int choice = 0;//选项
    calculate Calculate;
    while (true)
    {
        menu.Show_Menu();
        cout << "请输入选项" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0 ://退出
            menu.exitSystem();
            break;
        case 1 ://单角色伤害计算
            cout << "是否有增幅反应（1：是）（2：否）" << endl;
            int a;
            cin >> a;
            if (a==1)
            {
                Calculate.Singlecalculationyes();
            }
            else 
            {
                Calculate.Singlecalculationno();
            }
            break;
        case 2 ://多角色吃BUFF伤害计算
            cout << "咕咕咕" << endl;
            break;
        default:
            system("cls");
            break;
        }
    }



    system("pause");
    return 0;
}
