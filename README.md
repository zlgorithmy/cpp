# cpp

* [虚函数](Project/Project1/pro.md)
  1. 允许被子类重新定义的函数
  2. 虚函数的作用是运行时多态的实现
  3. 虚函数的声明：virtual returntype func(parameter);
  4. 简单说就是指向子类对象的父类指针在调用虚函数时会调用子类函数，如果不使用虚函数则会调用父类函数
  5. 查看虚函数表：cl main.cpp /d1reportSingleClassLayoutB
* 纯虚函数
  1. 纯虚函数只为派生接口，包含纯虚函数的类叫抽象类
  2. 抽象类只能被继承，无法被实例化
  3. 子类必须实现接口
* 析构函数为什么要声明为虚函数
  1. 避免内存泄漏，使得 释放使用指向子类对象的父类指针时可以成功调用子类析构函数
  2. 若不使用虚函数，则子类申请的资源得不到释放
* ++i和i++比较
  1. i++返回原值，++i返回加1后的值
  2. i++先使用i进行运算，++i先进行加1运算，i的值都增加1
  3. ++i是左值，可以 ++i=3;结果i的值为3
  4. 当i为内置数据类型时，运算效率一致
  5. 对于自定义类型，++i效率高于i++，前者将对象作为左值返回，后者则把对象原始值的副本作为右值返回
* vector的reserve和capacity的区别
  1. reserve() 用于让容器预留空间，capacity()返回容器最大能容纳元素个数
* const
  1. 常变量：const type 变量名 或者 type const 变量名
  2. const 类型指针
     1. const离对象名近指向的地址不可变 int* const pa = &a;*pa = 6;
     2. *离对象名近指针内容不可变 const int *pb = &b; pb = &a;
  3. 修饰函数参数，函数不得修改参数
     1. void Fun(const type *param); //修饰指针型传入参数
     2. void Fun(const type &param); //修饰引用型传入参数
  4. 修饰函数返回值，返回值不可以被修改，而且返回值需要赋给常量或者常指针
  5. 修饰成员函数，type func(type) const;
     1. const对象只能访问const成员函数,非const对象也可以访问const成员函数
     2. const对象成员不能被修改
     3. const成员函数不能修改成员数据
  6. const成员必须初始化
