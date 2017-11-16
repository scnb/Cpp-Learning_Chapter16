// 16-21.cpp : �������̨Ӧ�ó������ڵ㡣
//slice�ࣺ����������������������������±�ָ�����ܣ�������������£�����ʾ�Ĳ���һ��ֵ����һ��ֵ��
/*
	slice���󱻳�ʼ��Ϊ��������ֵ����ʼ��������������Ԫ�ؿ�ࡣ
	����ʼ�����ǵ�һ����ѡ�е�Ԫ�ص�����
	��������ָ��Ҫѡ�ж��ٸ�Ԫ��
	�ۿ���ʾԪ��֮��ļ����

	slice�������������±�ָ�����ܣ����¿���ʹ��һ��һάvalarray��������ʾ��ά���ݡ�
	����һ��valarray����valint�а���12��Ԫ�أ���ʾ����һ��4��3�еľ���slice(0,3,1)��ʾ��һ�е�Ԫ�أ�
	��slice(0,4,3)���ʾ��һ�е�Ԫ�ء�
*/

#include "stdafx.h"
#include <iostream>
#include <valarray>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::valarray;

const int SIZE = 12;
typedef valarray<int> vint;
void show(const vint & v, int cols);

int main()
{
	using std::slice;
	vint valint(SIZE);

	int i;
	for (i = 0;i < SIZE;i++)
	{
		valint[i] = rand() % 10;
	}
	cout << "Original array:\n";
	show(valint, 3);

	vint vcol(valint[slice(1, 4, 3)]);				//�����ó��ڶ�������ֵ��vcol
	cout << "Second col:\n";
	show(vcol, 1);									//��һ������ʾvcol

	vint vrow(valint[slice(3, 3, 1)]);				//�����ó����ڶ�������ֵ��vrow
	cout << "First row:\n";
	show(vrow, 3);
	valint[slice(2, 4, 3)] = 10;					//��valint�����ά����ĵڶ��У������һ�У���ֵΪ10
	cout << "Set last column to 10:\n";
	show(valint, 3);
	
	cout << "Set first column to sum of next two:\n";
	//û��Ϊslices�ඨ��+�������������Ҫת����valarray<int>��ʹ��sliceָ����Ԫ�ش���һ��������valint����
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);//�ѵڶ��к͵����ж�ӦԪ�غ͸�ֵ����һ��
	show(valint, 3);
	getchar();
	return 0;
}

void show(const vint & v, int cols)				//cols��ʾ�ö�ά���������
{
	int lim = v.size();
	for (int i = 0;i < lim;i++)
	{
		cout.widen(3);
		cout << v[i];
		if (i%cols == cols - 1)					//��ʾ�Ѿ��������һ�У��û�����
		{
			cout << endl;
		}
		else								    //������Կո����
		{
			cout << ' ';
		}
	}
	if (lim % cols != 0)						//��ά����Ԫ�ظ���������������������ʲô�����ԭʼ���������⣿
	{
		cout << endl;
	}
}