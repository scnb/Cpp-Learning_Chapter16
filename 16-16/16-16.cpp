// 16-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::plus;
using std::bind1st;
using std::multiplies;

void Show(double);

const int LIM = 6;

int main()
{
	double arr1[LIM] = { 28,29,30,35,38,59 };
	double arr2[LIM] = { 63,65,69,75,80,99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	cout.setf(std::ios_base::fixed);
	cout.precision(1);
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	cout << "m8:\t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;
	//使用函数符 plus将两个vector相加
	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
	cout << "sum:\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;
	//利用函数符 multiplies将gr8的每个元素与2.5相乘
	vector<double> prod(LIM);
	transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
	cout << "prod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;
	getchar();
    return 0;
}

void Show(double v)
{
	cout.width(6);
	cout << v << ' ';
}
