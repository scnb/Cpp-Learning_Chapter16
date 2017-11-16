// 16-20.cpp : 定义控制台应用程序的入口点。
//模板类valarray的使用：该模板类被设计成用于表示数值数组，支持各种数值数组操纵。
//例如，将两个数组的内容相加、对数组的每个元素应用数学函数以及对数组进行线性代数运算。

/*
	1、vector模板类是一个容器类和算法系统的一部分，它支持面向容器的操作，如排序、插入、重新排列、搜索、将数据
	转移到其他容器中等。

	2、array是为代替内置数组而设计的，它通过提供更好、更安全的接口，让数组更紧凑，效率更高。表示固定长度的数组
	，因此不支持push_back()和insert()，但提供了多个STL方法，包括begin(),end()，rbegin()和rend()，因此很容易将STL算法用于array对象。

	3、valarray类模板是面向数值计算的，不是STL的一部分。例如，它没有push_back()和insert()方法，但为很多数学
	运算提供了一个简答、直观的接口。
*/

#include "stdafx.h"
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::valarray;
using std::vector;

int main()
{
	vector<double> data;
	double temp;

	cout << "Enter numbers (<=0 to quit):\n";
	while (cin >> temp && temp > 0)						//先把数据存到vector容器中
	{
		data.push_back(temp);
	}
	sort(data.begin(), data.end());						//对vector容器中的数据进行排序

	int size = data.size();								//取得容器当前元素个数

	valarray<double> numbers(size);						
	int i;
	for (i = 0;i < size;i++)
	{
		numbers[i] = data[i];							//利用赋值法，将vector容器中的元素复制给valarray容器
	}

	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);								//将sqrt函数用于valarray容器，得到每个元素的根植，并返回一个valarray容器
	valarray<double> results(size);
	results = numbers + 2.0*sq_rts;						//对valarray容器，重载了所有的运算符
	cout.setf(std::ios_base::fixed);					//设置显示格式
	cout.precision(4);									//设置精度为小数点后4位
	for (i = 0;i < size;i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}
	cout << "Done.\n";
	getchar();
	getchar();
    return 0;
}

