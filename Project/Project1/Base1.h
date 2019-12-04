#pragma once
#include <iostream>
using namespace std;

class Base1
{
	public:
		virtual void f() { 
			cout << "Base1::f" << endl;
		}
		virtual void g() {
			cout << "Base1::g" << endl;
		}
		virtual void h() {
			cout << "Base1::h" << endl;
		}
		virtual ~Base1() {
			cout << "Base1::~" << endl;
		}
};

