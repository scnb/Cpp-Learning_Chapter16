// 16-22.cpp : 定义控制台应用程序的入口点。
//initializer_list：C++11新增的模板。
/*
	用途：可使用初始化列表语法将STL容器初始化为一系列值：vector<double> payments {45.99,39.23,19.95,89.01};
	使用列表中的四个值来初始化vector容器的元素，之所以可行，是因为容器类现在包含将initializer_list<T>作为
	参数的构造函数。

	所有initializer_list元素的类型都必须相同。

	可按值传递initializer_list对象，也可按引用传递initializer_list对象。还可以将一个initializer_list赋给另一个
	initializer_list对象。

*/

#include "stdafx.h"
#include <iostream>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

double sum(initializer_list<double> il);
double average(const initializer_list<double> & ril);

int main()
{
	cout << "List 1: sum = " << sum({ 2,3,4 }) << ", ave = " << average({ 2,3,4 }) << '\n';//函数参数可以是initializer_list字面量
	initializer_list<double> dl = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "List 2: sum = " << sum(dl) << ", ave = " << average(dl) << '\n';//函数参数也可以是initializer_list变量
	dl = { 16.0,25.0,36.0,40.0,64.0 };
	cout << "List 3: sum = " << sum(dl) << ", ave = " << average(dl) << '\n';
	getchar();
    return 0;
}

double sum(initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin();p != il.end();p++)
	{
		tot += *p;
	}
	return tot;
}

double average(const initializer_list<double> & ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto p = ril.begin();p != ril.end();p++)
		{
			tot += *p;
		}
		ave = tot / n;
	}
	return ave;
}
