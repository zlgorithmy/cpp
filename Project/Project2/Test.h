#pragma once
#include<iostream>
using namespace std;
class Test
{
	const int m;//��ʼ���б��ʼ��const��Ա
	const int n = 20; //c++11 ֧��ֱ�ӳ�ʼ��
	static int a;//static��Ա�������ʼ��
	static const int c=5; //ֻ��������ʱ��ʼ��

	int i = 0;
public:
	Test() : m(10) 
	{
		++a;// static��ԱΪ�����ж�����
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
		//a++;const���κ�������������������޸�
		int* pa = const_cast<int*>( &a); //����ͨ��ȥ�������Գ��������޸�
		(*pa)++;
		return a + b;
	}
	int add(const int* a, const int* b)
	{
		(*(const_cast<int*>(a)))++;//����ͨ��ȥ�������Գ��������޸�
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
	const int* getConsti()//const ���κ�������ֵ������ʹ��const���գ�����ֵ���ܱ��޸ġ�
	{
		return &i;
	}
	void displayi()
	{
		cout << i << endl;
	}

	void testConst()const //const ���� �����޸ķǾ�̬��Ա����
	{
		cout << "i:" << i;
		a++; //��̬��Ա��������Ӱ������޸�
	}

	int c;
};

int Test::a = 0; 