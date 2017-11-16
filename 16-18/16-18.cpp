// 16-18.cpp : 定义控制台应用程序的入口点。
//函数和容器方法
/*
	有时可选择使用STL方法或STL函数，通常方法（method）是更好的选择。
	①方法更适合于特定的容器。
	②作为成员函数，它可以使用模板类的内存管理工具，从而在需要时调整容器的长度。

	从另一个角度来看，尽管方法通常更适合，但非方法函数更通用。可以将它们用于数组、string对象、STL容器、
	还可以用它们来处理混合的容器类型。
*/

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void Show(int);

const int LIM = 10;

int main()
{
	int ar[LIM] = { 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "Original list contents:\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);
	cout << "After using the remove() method:\n";			//使用remove()方法
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	list<int>::iterator last;								//创建迭代器，用来保存remove函数返回的指向新的超尾值的迭代器
	last = remove(lb.begin(), lb.end(), 4);					//使用remove()函数
	cout << "After using the remove function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	lb.erase(last, lb.end());								//用erase()函数删除中不再需要的区间
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	getchar();
    return 0;
}

void Show(int v)
{
	cout << v << ' ';
}