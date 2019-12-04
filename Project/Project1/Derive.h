#pragma once
#include "Base1.h"
#include "Base2.h"
#include "Base3.h"
#include "Interface.h"
class Derive :public Base1, public Base2, public Base3,public Interface
{
public:
	void f() { cout << "Derive::f" << endl; } //子函数可以不加virtual关键字，
	virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
	void fi(){ cout << "Derive::fi" << endl; }
	virtual ~Derive() {
		cout << "Derive::~" << endl;
	}
};

