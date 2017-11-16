// 16-12.cpp : 定义控制台应用程序的入口点。
//List模板类的一些方法：
/*
	merge()
	remove()
	sort()
	splice()
	unique()
*/

#include "stdafx.h"
#include <iostream>
#include <list>				//使用链表类
#include <iterator>		   //使用迭代器类
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void outint(int n) { cout << n << " "; }

int main()
{
	list<int> one(5, 2);//包含5个2的整型链表
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);//将stuff中的所有元素插入到two链表的第一个元素前面
	int more[6] = { 6,4,2,4,6,5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl;
	cout << "List two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl;
	cout << "List three: ";
	for_each(three.begin(), three.end(), outint);

	cout << endl;
	three.remove(2);//从链表中删除所有元素为2的实例
	cout << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);//将链表one的内容插入到three链表的第一个元素前面，同时one容器将被清空
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();//将连续的相同元素压缩为单个元素
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();//对链表three进行升序排序
	three.unique();//将连续的相同元素压缩为单个元素
	cout << endl;
	cout << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);//将链表three和链表two排序后，进行合并，并且two链表变为空
	cout << endl;
	cout << "Sorted two merged into three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	getchar();
    return 0;
}

