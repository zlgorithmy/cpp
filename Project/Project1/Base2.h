#pragma once
#include <iostream>
using namespace std;
class Base2
{
public:
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
	virtual ~Base2() {
		cout << "Base2::~" << endl;
	}
};

