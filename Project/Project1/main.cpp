//#include <iostream>
#include "Derive.h"
//using namespace std;

//typedef  ��������(*������)(������)
typedef void(*Fun)(void);

void displayD(string s) {
	cout << "-----------"<<s<<"-------------------------" << endl;
}

//��ȡ�麯����
void test()
{
	Derive d;
	//cout << "size(d):" << sizeof(d) << endl;
	int** pVtab = (int**)&d;

	//Base1's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0); //д��һ Base1::f
	//pFun = (Fun)pVtab[0][0];//д���� Base1::f
	//pFun();

	//��д
	//((Fun)pVtab[0][0])();//Base1::f
	//((Fun)* ((int*) * (int*)((int*)&d + 0) + 0))();//Base1::f

	//Base1 �麯����
	displayD("Base1");
	((Fun)pVtab[0][0])(); //����f��������д�������麯������ֻ��Derive::f
	((Fun)pVtab[0][1])();//Base1::g
	((Fun)pVtab[0][2])();//Base1::h

	//Derive �麯����
	displayD("Derive");
	((Fun)pVtab[0][3])();//Derive::f1
	((Fun)pVtab[0][4])();//Derive::g1
	((Fun)pVtab[0][5])();//Derive::h1

	//Base2 �麯����
	displayD("Base2");
	((Fun)pVtab[1][0])();//����f��������д�������麯������ֻ��Derive::f
	((Fun)pVtab[1][1])();//Base2::g
	((Fun)pVtab[1][2])();//Base2::h

	//Base3 �麯����
	displayD("Base3");
	((Fun)pVtab[2][0])();//����f��������д�������麯������ֻ��Derive::f
	((Fun)pVtab[2][1])();//Base2::g
	((Fun)pVtab[2][2])();//Base2::h
}
void test1()
{
	//Base1 b1;
	//Base2 b2;
	//Base3 b3;
	//Derive d;

	Base1* pb1 = new Derive();
	pb1->f();//Derive::f,ָ���������ĸ���ָ������Ӻ�����д���麯��ʱ��������Ӻ����е��麯��

	delete pb1;
	//Derive::~
	//Base3::~
	//Base2::~
	//Base1::~
	//��Base1�������������麯������ֻ�����
}
int main()
{
	//cout << "hello world1!" << endl;
	test1();
	return 0;
}