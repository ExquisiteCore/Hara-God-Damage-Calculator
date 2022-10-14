#pragma once
#include<string>
#include <iostream>
using namespace std;
class calculate
{
public:
	calculate();

	double Singlecalculationyes();//单次计算
	double Singlecalculationno();//单次计算
	double AttackValue;//攻击区
	double MagnificationValue; // 倍率区
	double  DamagebonusValue;//伤害加成区
	double CriticaldamageValue; //暴击伤害
	double IncreaseresponserateValue;//增幅反应倍率
	double DefensereliefValue;//防御减免
	double ResistancereductionValue;//抗性减免

	double Magnification(); // 倍率区
	double  Damagebonus();//伤害加成区
	double Criticaldamage(); //暴击伤害
	double Increaseresponserate();//增幅反应倍率
	double Defenserelief();//防御减免
	double Resistancereduction();//抗性减免

	~calculate();

};
