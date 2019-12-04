#pragma once
#include<iostream>
using namespace std;
class Test
{
	const int m;//初始化列表初始化const成员
	const int n = 20; //c++11 支持直接初始化
	static int a;//static成员在类外初始化
	static const int c=5; //只能在声明时初始化

	int i = 0;
public:
	Test() : m(10) 
	{
		++a;// static成员为类所有对象共有
		i = 0;
	}
	const void f()const
	{
		cout << "m:" << m<<endl;
		cout << "n:" << n << endl;
		cout << "a:" << a << endl;
		cout << "c:" << c << endl;
	}
	int add(const int a, const int b) 
	{
		//a++;const修饰函数参数不允许参数被修改
		int* pa = const_cast<int*>( &a); //可以通过去常操作对常量进行修改
		(*pa)++;
		return a + b;
	}
	int add(const int* a, const int* b)
	{
		(*(const_cast<int*>(a)))++;//可以通过去常操作对常量进行修改
		cout << "&a=" << a << endl;
		cout << "a=" << *a << endl;
		return *a + *b;
	}
	int add0(const int& a, const int& b)
	{
		(const_cast<int&>(a))++;
		cout << "&a=" << &a << endl;
		cout << "a=" << a << endl;
		return a + b;
	}
	int* geti()
	{
		return &i;
	}
	const int* getConsti()//const 修饰函数返回值，必须使用const接收，返回值不能被修改。
	{
		return &i;
	}
	void displayi()
	{
		cout << i << endl;
	}

	void testConst()const //const 函数 不能修改非静态成员变量
	{
		cout << "i:" << i;
		a++; //静态成员变量不受影响可以修改
	}

	int c;
};

int Test::a = 0; 