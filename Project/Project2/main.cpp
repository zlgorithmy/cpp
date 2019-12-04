#include<iostream>
#include "Test.h"
using namespace std;
void test()
{
	Test t, t1;
	t.f();
}
void test0()
{
	int a = 0;
	int b = 1;
	int* const pa = &a; //const int类型指针pa,pa不可以再指向其他地址，const离变量名较近，指向的地址不可变
	*pa = 6;// a:6
	//pa = &b; //不允许
	cout << "a:" << a << endl;

	const int* pb = &b; //int 型指针，*离对象名近指针指向的内容不可变
	pb = pa;
	//*pb = 6;//不允许

	//*在const前内容可变
	cout << "b:" << b << endl;
}
void display(volatile const int& a)
{
	cout << "&a=" << &a << " a=" << a << endl;
}
void test1()
{
	Test t;
	const int a = 2;
	const int b = 2;
	//	cout <<"1+2="<< t.add(1, 2) << endl;
	cout << "&a=" << &a << endl;
	cout << "a=" << a << endl;
	cout << a << "+" << b << "=" << t.add(&a, &b) << endl;
	cout << "a=" << a << endl;
	cout << a << "+" << b << "=" << t.add0(a, b) << endl;
	cout << "a=" << a << endl;
	display(a);

	(*(const_cast<int*>(&a)))+=2;
	cout << "&a=" << &a << endl;
	cout << "a=" << a << endl;
}
void add(volatile const int& a)
{
	cout << "&a=" << &a << " a=" << a << endl;
	(*(const_cast<int*>(&a))) ++;
}
void test2()
{
	volatile const int a = 0;  //不加volatile,则在函数作用域内是0，作为参数会变化
	add(a);
	add(a);
	add(a);
	cout << "&a=" << &a << " a=" << a << endl;
	display(a);
}
void test3()
{
	Test t;
	*t.geti() = 5;
	cout << *t.geti() << endl;
	t.displayi();

	const int* p = t.getConsti();
	(*(const_cast<int*>(p)))++;
	cout << *p << endl;
	t.displayi();
}
void test4()
{
	Test t;
	const Test t1; //const 对象只能调用const修饰的函数
	t1.f();
	t.testConst(); 
	t1.f();
}
int main()
{
	test4();
	return 0;
}