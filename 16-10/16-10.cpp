// 16-10.cpp : �������̨Ӧ�ó������ڵ㡣
//���������(reverse_iterator)��
/*
	��reverse_iteratorִ�е������������������ݼ���
	Ӧ�÷�������������׷����ӡ���������ݡ�
	���磺
		vector������һ����Ϊrbegin()�ĳ�Ա����������һ��ָ��β�ķ��������
				����һ����Ϊrend()�ĳ�Ա����������һ��ָ���һ��Ԫ�صķ����������
		����ʹ����������������������������ݣ�
		copy(dice.rbegin(),dice.rend(),out_iter);

	ע������⣺����ָ������ȵݼ����ٽ�����á�
				��Ϊdice.rbegin()���س�β����˲��ܶԸõ�ַ���н�����á�ͬ�������rend()���ص�һ��Ԫ��
				��λ�ã���copy()��������һ��λ��ֹͣ��
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	//copy from array to vector
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cout!\n";
	//create an ostream iterator
	ostream_iterator<int, char> out_iter(cout, " ");
	//copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";
	//ʹ��STL����
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	//ʹ����ʾ����������
	for (ri = dice.rbegin();ri != dice.rend();ri++)
	{
		cout << *ri << ' ';
	}
	cout << endl;
	getchar();
    return 0;
}

