#pragma once
#include <iostream>
using namespace std;
class Base3
{
public:
	virtual void f() { cout << "Base3::f" << endl; }

	virtual void g() { cout << "Base3::g" << endl; }

	virtual void h() { cout << "Base3::h" << endl; }
	virtual ~Base3() {
		cout << "Base3::~" << endl;
	}
};

