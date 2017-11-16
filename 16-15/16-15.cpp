// 16-15.cpp : 定义控制台应用程序的入口点。
//函数对象——函数符（functor）：可以以函数方式与（）结合使用的任意对象。
/*
	包括：函数名、指向函数的指针和重载了（）运算符的类对象。

	函数符概念：
	①生成器（generator）是不用参数就可以调用的函数符
	②一元函数（unary function）是用一个参数就可以调用的函数符
	③二元函数（binary function）是用两个参数可以调用的函数符
	改进版本：
	①返回bool值的一元函数是谓词（predicate）
	②返回bool值的二元函数是二元谓词（binary predicate）

	例如，list模板有一个将谓词作为参数的remove_if()成员，该函数将谓词用于区间中的每个元素，如果谓词
	返回true，则删除该元素。
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::iterator;
using std::list;

template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) {}
	bool operator()(const T & v) { return v > cutoff; }
};

void outint(int n) { cout << n << " "; }

int main()
{
	TooBig<int> f100(100);//创建TooBig类对象，并设置cutoff值为整型100
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);//使用一个被命名的函数对象
	etcetera.remove_if(TooBig<int>(200));//使用一个未命名的函数对象
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	getchar();
    return 0;
}
