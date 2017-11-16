// 16-15.cpp : �������̨Ӧ�ó������ڵ㡣
//�������󡪡���������functor���������Ժ�����ʽ�루�����ʹ�õ��������
/*
	��������������ָ������ָ��������ˣ���������������

	���������
	����������generator���ǲ��ò����Ϳ��Ե��õĺ�����
	��һԪ������unary function������һ�������Ϳ��Ե��õĺ�����
	�۶�Ԫ������binary function�����������������Ե��õĺ�����
	�Ľ��汾��
	�ٷ���boolֵ��һԪ������ν�ʣ�predicate��
	�ڷ���boolֵ�Ķ�Ԫ�����Ƕ�Ԫν�ʣ�binary predicate��

	���磬listģ����һ����ν����Ϊ������remove_if()��Ա���ú�����ν�����������е�ÿ��Ԫ�أ����ν��
	����true����ɾ����Ԫ�ء�
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
	TooBig<int> f100(100);//����TooBig����󣬲�����cutoffֵΪ����100
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);//ʹ��һ���������ĺ�������
	etcetera.remove_if(TooBig<int>(200));//ʹ��һ��δ�����ĺ�������
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	getchar();
    return 0;
}
