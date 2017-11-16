// 16-12.cpp : �������̨Ӧ�ó������ڵ㡣
//Listģ�����һЩ������
/*
	merge()
	remove()
	sort()
	splice()
	unique()
*/

#include "stdafx.h"
#include <iostream>
#include <list>				//ʹ��������
#include <iterator>		   //ʹ�õ�������
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void outint(int n) { cout << n << " "; }

int main()
{
	list<int> one(5, 2);//����5��2����������
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);//��stuff�е�����Ԫ�ز��뵽two����ĵ�һ��Ԫ��ǰ��
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
	three.remove(2);//��������ɾ������Ԫ��Ϊ2��ʵ��
	cout << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);//������one�����ݲ��뵽three����ĵ�һ��Ԫ��ǰ�棬ͬʱone�����������
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();//����������ͬԪ��ѹ��Ϊ����Ԫ��
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();//������three������������
	three.unique();//����������ͬԪ��ѹ��Ϊ����Ԫ��
	cout << endl;
	cout << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);//������three������two����󣬽��кϲ�������two�����Ϊ��
	cout << endl;
	cout << "Sorted two merged into three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	getchar();
    return 0;
}

