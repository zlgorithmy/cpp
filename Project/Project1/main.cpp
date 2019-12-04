//#include <iostream>
#include "Derive.h"
//using namespace std;

//typedef  返回类型(*新类型)(参数表)
typedef void(*Fun)(void);

void displayD(string s) {
	cout << "-----------"<<s<<"-------------------------" << endl;
}

//获取虚函数表
void test()
{
	Derive d;
	//cout << "size(d):" << sizeof(d) << endl;
	int** pVtab = (int**)&d;

	//Base1's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0); //写法一 Base1::f
	//pFun = (Fun)pVtab[0][0];//写法二 Base1::f
	//pFun();

	//简写
	//((Fun)pVtab[0][0])();//Base1::f
	//((Fun)* ((int*) * (int*)((int*)&d + 0) + 0))();//Base1::f

	//Base1 虚函数表
	displayD("Base1");
	((Fun)pVtab[0][0])(); //由于f函数被重写，所以虚函数表中只有Derive::f
	((Fun)pVtab[0][1])();//Base1::g
	((Fun)pVtab[0][2])();//Base1::h

	//Derive 虚函数表
	displayD("Derive");
	((Fun)pVtab[0][3])();//Derive::f1
	((Fun)pVtab[0][4])();//Derive::g1
	((Fun)pVtab[0][5])();//Derive::h1

	//Base2 虚函数表
	displayD("Base2");
	((Fun)pVtab[1][0])();//由于f函数被重写，所以虚函数表中只有Derive::f
	((Fun)pVtab[1][1])();//Base2::g
	((Fun)pVtab[1][2])();//Base2::h

	//Base3 虚函数表
	displayD("Base3");
	((Fun)pVtab[2][0])();//由于f函数被重写，所以虚函数表中只有Derive::f
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
	pb1->f();//Derive::f,指向子类对象的父类指针调用子函数重写的虚函数时，会调用子函数中的虚函数

	delete pb1;
	//Derive::~
	//Base3::~
	//Base2::~
	//Base1::~
	//若Base1析构函数不是虚函数，则只会调用
}
int main()
{
	//cout << "hello world1!" << endl;
	test1();
	return 0;
}