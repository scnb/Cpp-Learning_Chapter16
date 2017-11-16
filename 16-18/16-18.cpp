// 16-18.cpp : �������̨Ӧ�ó������ڵ㡣
//��������������
/*
	��ʱ��ѡ��ʹ��STL������STL������ͨ��������method���Ǹ��õ�ѡ��
	�ٷ������ʺ����ض���������
	����Ϊ��Ա������������ʹ��ģ������ڴ�����ߣ��Ӷ�����Ҫʱ���������ĳ��ȡ�

	����һ���Ƕ����������ܷ���ͨ�����ʺϣ����Ƿ���������ͨ�á����Խ������������顢string����STL������
	�������������������ϵ��������͡�
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
	cout << "After using the remove() method:\n";			//ʹ��remove()����
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	list<int>::iterator last;								//��������������������remove�������ص�ָ���µĳ�βֵ�ĵ�����
	last = remove(lb.begin(), lb.end(), 4);					//ʹ��remove()����
	cout << "After using the remove function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	lb.erase(last, lb.end());								//��erase()����ɾ���в�����Ҫ������
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