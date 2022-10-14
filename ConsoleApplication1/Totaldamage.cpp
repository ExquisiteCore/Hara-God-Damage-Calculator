#include"Totaldamage.h"
using namespace std;

calculate::calculate()
{
	calculate::AttackValue = 1;//攻击
	calculate::MagnificationValue = 1;//倍率
	calculate::DamagebonusValue = 1;//伤害加成区
	calculate::CriticaldamageValue = 1; //暴击伤害
	calculate::IncreaseresponserateValue = 1;//增幅反应倍率
	calculate::DefensereliefValue = 1;//防御减免
	calculate::ResistancereductionValue = 1;//抗性减免
}

double calculate::Criticaldamage() 
{ 
	cout << "请输入角色暴击伤害" << endl;
	double value;
	cin >> value;
	CriticaldamageValue = value / 100;
	return CriticaldamageValue;
}//暴击伤害
double calculate::Magnification()
{
	cout << "请输入角色技能倍率" << endl;
	double value;
	cin >> value;
	MagnificationValue = value / 100;
	return MagnificationValue;
}//倍率
double calculate::Increaseresponserate()
{
	cout << "请输入角色元素精通" << endl;
	double c;
	cin >> c;
	double ak = (2.78 * c) / (c + 1400);//精通提升
	//增幅反应总倍率=反应基础倍率*(1 + 精通提升 + 反应系数提高)
	cout << "请输入反应基础倍率：水火蒸发2.0，火水蒸发1.5，火冰融化2.0，冰火融化1.5."<< endl;
	double a;
	cin >> a;
	IncreaseresponserateValue = a * (1 + ak );
	return IncreaseresponserateValue; 
}//增幅反应倍率
double calculate::Defenserelief()
{
	//防御对象承伤=((人物等级+100)/(1-无视防御%)*(1-防御减免%+防御增加%)*(怪物等级+100)+人物等级+100)
	cout << "请输入角色等级" << endl;    
	double a , b , c , g;
	cin >> a;
	cout << "请输入怪物等级" << endl;
	cin >> c;
	cout << "是否有减防(1:是  2：否)" << endl;
	cin >> g;
	if (g==2)
	{//190/(190+190)
		b =  (a + 100) / ((c + 100) + (a + 100)) ;
	}
	else
	{//190/((1-30%)*190+190)
		cout << "防御减免百分比（不要带%号）" << endl;
		double af , f;
		cin >> af;
		f = af / 100;
		b = (a + 100) / (1-f) * (c + 100) + (a + 100);
	}
	b = DefensereliefValue;
	return DefensereliefValue;
} //防御减免
double calculate::Resistancereduction()
{
	double a,b;

	cin >> b;
	cout << "请输入怪物元素（物理）抗性" << endl;
	cout << "1为默认古龙蜥10%元素30%物理抗性(不考虑龙蜥属性)" << endl;

	double Resistance;
	cin >> a;
	if (a == 1) 
	{
		cout << "请选择角色属性（物理或元素）" << endl;
		cout << "1(物理)  2(元素)" << endl;
		if(b==2){ Resistance = 0.1; }
		else { Resistance = 0.3; }
	}
	else
	{
		cout << "请输入抗性百分比（不带%号）" << endl;

		double x;
		cin >> x;
		Resistance = x / 100;
	}
	cout << "是否有减抗（1：是 2：否）" << endl;
	int aa;
	cin >> aa;
	if(a==1)
	{
		double Resistance1;
		double k;
		cout << "请输入减抗百分比（不带百分号）" << endl;
		cin >> k;
		k = k / 100;
		Resistance1 = Resistance - k;
		ResistancereductionValue = 1 - (Resistance1 / 2) ;//1 - R / 2
	}
	else
	{

		ResistancereductionValue = 1 - Resistance; 
	}
	//举例：比如甘雨1命减15%抗性，作用于10%抗性的丘丘人
	//减抗前，10% 抗，对象承伤为1 - 10 %= 90 %
	//减抗后， - 5 % 抗，对象承伤为1 - -5 % / 2 = 1 + 5 % / 2 = 102.5 %
	//R > 75 % 时，抗性对象承伤 = 1 / (1 + 4R)
	//0≤R≤75 % 时，抗性对象承伤 = 1 - R
	//R < 0时，抗性对象承伤 = 1 - R / 2
	return ResistancereductionValue; 
}//抗性减免
double calculate::Damagebonus()
{ 
	cout << "请输入角色伤害加成（如造成伤害加XXX，元素伤害加成）" << endl;
	double value;
	cin >> value;
	DamagebonusValue = value / 100;
	return DamagebonusValue;
} //伤害加成

double calculate::Singlecalculationyes()
{
	cout << "当前为单角色伤害计算" << endl;
	cout << "请输入角色攻击力" << endl;
	cin >> AttackValue;
	cout << "角色攻击力:" << AttackValue << endl;
	MagnificationValue = Magnification();  //倍率函数
	DamagebonusValue = Damagebonus();      //伤害加成
	CriticaldamageValue = Criticaldamage();//爆伤计算
	IncreaseresponserateValue = Increaseresponserate(); // 增幅计算
	DefensereliefValue = Defenserelief();//防御计算
	ResistancereductionValue = Resistancereduction();//抗性
	double ai;
	ai = AttackValue * MagnificationValue * (1 + DamagebonusValue) * (1 + CriticaldamageValue) * DefensereliefValue * IncreaseresponserateValue * ResistancereductionValue;
	cout << "计算面板：" << "攻击力:" << AttackValue << "% 技能倍率：" << MagnificationValue * 100 << "% 伤害加成："<< DamagebonusValue * 100 << "爆伤：" << CriticaldamageValue * 100 << "% 增幅：" << IncreaseresponserateValue * 100 << "% 防御抗性：" << DefensereliefValue * 100 << "% 怪物抗性:" << ResistancereductionValue * 100 <<endl;
	cout << ai << endl;
	return 0;
}
double calculate::Singlecalculationno()
{
	cout << "当前为单角色伤害计算" << endl;
	cout << "请输入角色攻击力" << endl;
	cin >> AttackValue;
	cout << "角色攻击力:" << AttackValue << endl;
	MagnificationValue = Magnification();  //倍率函数
	DamagebonusValue = Damagebonus();      //伤害加成
	CriticaldamageValue = Criticaldamage();//爆伤计算
	DefensereliefValue = Defenserelief();//防御计算
	double ai;
	ai = AttackValue * MagnificationValue * (1 + DamagebonusValue) * (1 + CriticaldamageValue) * DefensereliefValue * ResistancereductionValue;
	cout << "面板：" << "攻击力:" << AttackValue << "% 技能倍率：" << MagnificationValue * 100 << "% 伤害加成：" << DamagebonusValue * 100 << "爆伤：" << CriticaldamageValue * 100  << "% 防御抗性：" << DefensereliefValue * 100 << "% 怪物抗性:" << ResistancereductionValue * 100 << endl;
	cout << ai << endl;
	return 0;
}
calculate::~calculate()
{

}

//七大乘区    //防御对象承伤=((人物等级+100)/(1-无视防御%)*(1-防御减免%+防御增加%)*(怪物等级+100)+人物等级+100)
//伤害 = 攻击力 * 伤害倍率 * (1 + 伤害加成) * (1 + 暴击伤害) * 增幅反应倍率 * 防御减免 * 抗性减免
//初始化类            反应基础倍率：水火蒸发2.0，火水蒸发1.5，火冰融化2.0，冰火融化1.5.
//calculate::Attack;//      元素精通提升= (2.78*精通)/(精通+1400)
//                         增幅反应总倍率=反应基础倍率*(1 + 精通提升 + 反应系数提高)
//calculate.Magnification = 1;//倍率区
//calculate.Damagebonus = 1;//伤害加成区
//calculate.Criticaldamage = 1;//暴击伤害
//calculate.Increaseresponserate = 1;//增幅反应倍率
//calculate.Defenserelief = 1;//防御减免
//calculate.Resistancereduction = 1;//抗性减免