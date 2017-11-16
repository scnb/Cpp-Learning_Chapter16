// 16-7.cpp : 定义控制台应用程序的入口点。
//STL（标准模板库）：提供了一组表示容器、迭代器、函数对象和算法的模板。
/*
	STL不是一种面向对象的编程，而是一种不同的编程模式-泛型编程（generic programming）。
	①容器是一个与数组类似的单元，可以存储若干个值。STL容器是同质的，即存储的值的类型相同。
	②迭代器用来遍历容器的对象，与能够遍历数组的指针类似，是广义指针。
	③函数对象是类似于函数的对象，可以是类对象或函数指针。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const int NUM = 5;

int main()
{
	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "You will do exactly as told. You will enter " << NUM << " book titles and your ratings (0-10).\n";
	int i;
	for (i = 0;i < NUM;i++)
	{
		cout << "Enter title #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "Enter your rating (0-10): ";
		cin >> ratings[i];                                                                 
		cin.get();
	}
	cout << "Thank you. You entered the following:\n Rating\tBook\n";
	for (i = 0;i < NUM;i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
	getchar();
    return 0;
}

