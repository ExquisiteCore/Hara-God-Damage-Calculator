#pragma once
#include<string>
#include <iostream>
using namespace std;
class calculate
{
public:
	calculate();

	double Singlecalculationyes();//���μ���
	double Singlecalculationno();//���μ���
	double AttackValue;//������
	double MagnificationValue; // ������
	double  DamagebonusValue;//�˺��ӳ���
	double CriticaldamageValue; //�����˺�
	double IncreaseresponserateValue;//������Ӧ����
	double DefensereliefValue;//��������
	double ResistancereductionValue;//���Լ���

	double Magnification(); // ������
	double  Damagebonus();//�˺��ӳ���
	double Criticaldamage(); //�����˺�
	double Increaseresponserate();//������Ӧ����
	double Defenserelief();//��������
	double Resistancereduction();//���Լ���

	~calculate();

};
