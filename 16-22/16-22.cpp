// 16-22.cpp : �������̨Ӧ�ó������ڵ㡣
//initializer_list��C++11������ģ�塣
/*
	��;����ʹ�ó�ʼ���б��﷨��STL������ʼ��Ϊһϵ��ֵ��vector<double> payments {45.99,39.23,19.95,89.01};
	ʹ���б��е��ĸ�ֵ����ʼ��vector������Ԫ�أ�֮���Կ��У�����Ϊ���������ڰ�����initializer_list<T>��Ϊ
	�����Ĺ��캯����

	����initializer_listԪ�ص����Ͷ�������ͬ��

	�ɰ�ֵ����initializer_list����Ҳ�ɰ����ô���initializer_list���󡣻����Խ�һ��initializer_list������һ��
	initializer_list����

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
	cout << "List 1: sum = " << sum({ 2,3,4 }) << ", ave = " << average({ 2,3,4 }) << '\n';//��������������initializer_list������
	initializer_list<double> dl = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "List 2: sum = " << sum(dl) << ", ave = " << average(dl) << '\n';//��������Ҳ������initializer_list����
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
