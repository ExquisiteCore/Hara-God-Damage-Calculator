#include"Totaldamage.h"
using namespace std;

calculate::calculate()
{
	calculate::AttackValue = 1;//����
	calculate::MagnificationValue = 1;//����
	calculate::DamagebonusValue = 1;//�˺��ӳ���
	calculate::CriticaldamageValue = 1; //�����˺�
	calculate::IncreaseresponserateValue = 1;//������Ӧ����
	calculate::DefensereliefValue = 1;//��������
	calculate::ResistancereductionValue = 1;//���Լ���
}

double calculate::Criticaldamage() 
{ 
	cout << "�������ɫ�����˺�" << endl;
	double value;
	cin >> value;
	CriticaldamageValue = value / 100;
	return CriticaldamageValue;
}//�����˺�
double calculate::Magnification()
{
	cout << "�������ɫ���ܱ���" << endl;
	double value;
	cin >> value;
	MagnificationValue = value / 100;
	return MagnificationValue;
}//����
double calculate::Increaseresponserate()
{
	cout << "�������ɫԪ�ؾ�ͨ" << endl;
	double c;
	cin >> c;
	double ak = (2.78 * c) / (c + 1400);//��ͨ����
	//������Ӧ�ܱ���=��Ӧ��������*(1 + ��ͨ���� + ��Ӧϵ�����)
	cout << "�����뷴Ӧ�������ʣ�ˮ������2.0����ˮ����1.5������ڻ�2.0�������ڻ�1.5."<< endl;
	double a;
	cin >> a;
	IncreaseresponserateValue = a * (1 + ak );
	return IncreaseresponserateValue; 
}//������Ӧ����
double calculate::Defenserelief()
{
	//�����������=((����ȼ�+100)/(1-���ӷ���%)*(1-��������%+��������%)*(����ȼ�+100)+����ȼ�+100)
	cout << "�������ɫ�ȼ�" << endl;    
	double a , b , c , g;
	cin >> a;
	cout << "���������ȼ�" << endl;
	cin >> c;
	cout << "�Ƿ��м���(1:��  2����)" << endl;
	cin >> g;
	if (g==2)
	{//190/(190+190)
		b =  (a + 100) / ((c + 100) + (a + 100)) ;
	}
	else
	{//190/((1-30%)*190+190)
		cout << "��������ٷֱȣ���Ҫ��%�ţ�" << endl;
		double af , f;
		cin >> af;
		f = af / 100;
		b = (a + 100) / (1-f) * (c + 100) + (a + 100);
	}
	b = DefensereliefValue;
	return DefensereliefValue;
} //��������
double calculate::Resistancereduction()
{
	double a,b;

	cin >> b;
	cout << "���������Ԫ�أ���������" << endl;
	cout << "1ΪĬ�Ϲ�����10%Ԫ��30%������(��������������)" << endl;

	double Resistance;
	cin >> a;
	if (a == 1) 
	{
		cout << "��ѡ���ɫ���ԣ������Ԫ�أ�" << endl;
		cout << "1(����)  2(Ԫ��)" << endl;
		if(b==2){ Resistance = 0.1; }
		else { Resistance = 0.3; }
	}
	else
	{
		cout << "�����뿹�԰ٷֱȣ�����%�ţ�" << endl;

		double x;
		cin >> x;
		Resistance = x / 100;
	}
	cout << "�Ƿ��м�����1���� 2����" << endl;
	int aa;
	cin >> aa;
	if(a==1)
	{
		double Resistance1;
		double k;
		cout << "����������ٷֱȣ������ٷֺţ�" << endl;
		cin >> k;
		k = k / 100;
		Resistance1 = Resistance - k;
		ResistancereductionValue = 1 - (Resistance1 / 2) ;//1 - R / 2
	}
	else
	{

		ResistancereductionValue = 1 - Resistance; 
	}
	//�������������1����15%���ԣ�������10%���Ե�������
	//����ǰ��10% �����������Ϊ1 - 10 %= 90 %
	//������ - 5 % �����������Ϊ1 - -5 % / 2 = 1 + 5 % / 2 = 102.5 %
	//R > 75 % ʱ�����Զ������ = 1 / (1 + 4R)
	//0��R��75 % ʱ�����Զ������ = 1 - R
	//R < 0ʱ�����Զ������ = 1 - R / 2
	return ResistancereductionValue; 
}//���Լ���
double calculate::Damagebonus()
{ 
	cout << "�������ɫ�˺��ӳɣ�������˺���XXX��Ԫ���˺��ӳɣ�" << endl;
	double value;
	cin >> value;
	DamagebonusValue = value / 100;
	return DamagebonusValue;
} //�˺��ӳ�

double calculate::Singlecalculationyes()
{
	cout << "��ǰΪ����ɫ�˺�����" << endl;
	cout << "�������ɫ������" << endl;
	cin >> AttackValue;
	cout << "��ɫ������:" << AttackValue << endl;
	MagnificationValue = Magnification();  //���ʺ���
	DamagebonusValue = Damagebonus();      //�˺��ӳ�
	CriticaldamageValue = Criticaldamage();//���˼���
	IncreaseresponserateValue = Increaseresponserate(); // ��������
	DefensereliefValue = Defenserelief();//��������
	ResistancereductionValue = Resistancereduction();//����
	double ai;
	ai = AttackValue * MagnificationValue * (1 + DamagebonusValue) * (1 + CriticaldamageValue) * DefensereliefValue * IncreaseresponserateValue * ResistancereductionValue;
	cout << "������壺" << "������:" << AttackValue << "% ���ܱ��ʣ�" << MagnificationValue * 100 << "% �˺��ӳɣ�"<< DamagebonusValue * 100 << "���ˣ�" << CriticaldamageValue * 100 << "% ������" << IncreaseresponserateValue * 100 << "% �������ԣ�" << DefensereliefValue * 100 << "% ���￹��:" << ResistancereductionValue * 100 <<endl;
	cout << ai << endl;
	return 0;
}
double calculate::Singlecalculationno()
{
	cout << "��ǰΪ����ɫ�˺�����" << endl;
	cout << "�������ɫ������" << endl;
	cin >> AttackValue;
	cout << "��ɫ������:" << AttackValue << endl;
	MagnificationValue = Magnification();  //���ʺ���
	DamagebonusValue = Damagebonus();      //�˺��ӳ�
	CriticaldamageValue = Criticaldamage();//���˼���
	DefensereliefValue = Defenserelief();//��������
	double ai;
	ai = AttackValue * MagnificationValue * (1 + DamagebonusValue) * (1 + CriticaldamageValue) * DefensereliefValue * ResistancereductionValue;
	cout << "��壺" << "������:" << AttackValue << "% ���ܱ��ʣ�" << MagnificationValue * 100 << "% �˺��ӳɣ�" << DamagebonusValue * 100 << "���ˣ�" << CriticaldamageValue * 100  << "% �������ԣ�" << DefensereliefValue * 100 << "% ���￹��:" << ResistancereductionValue * 100 << endl;
	cout << ai << endl;
	return 0;
}
calculate::~calculate()
{

}

//�ߴ����    //�����������=((����ȼ�+100)/(1-���ӷ���%)*(1-��������%+��������%)*(����ȼ�+100)+����ȼ�+100)
//�˺� = ������ * �˺����� * (1 + �˺��ӳ�) * (1 + �����˺�) * ������Ӧ���� * �������� * ���Լ���
//��ʼ����            ��Ӧ�������ʣ�ˮ������2.0����ˮ����1.5������ڻ�2.0�������ڻ�1.5.
//calculate::Attack;//      Ԫ�ؾ�ͨ����= (2.78*��ͨ)/(��ͨ+1400)
//                         ������Ӧ�ܱ���=��Ӧ��������*(1 + ��ͨ���� + ��Ӧϵ�����)
//calculate.Magnification = 1;//������
//calculate.Damagebonus = 1;//�˺��ӳ���
//calculate.Criticaldamage = 1;//�����˺�
//calculate.Increaseresponserate = 1;//������Ӧ����
//calculate.Defenserelief = 1;//��������
//calculate.Resistancereduction = 1;//���Լ���