// 16-20.cpp : �������̨Ӧ�ó������ڵ㡣
//ģ����valarray��ʹ�ã���ģ���౻��Ƴ����ڱ�ʾ��ֵ���飬֧�ָ�����ֵ������ݡ�
//���磬�����������������ӡ��������ÿ��Ԫ��Ӧ����ѧ�����Լ�������������Դ������㡣

/*
	1��vectorģ������һ����������㷨ϵͳ��һ���֣���֧�����������Ĳ����������򡢲��롢�������С�������������
	ת�Ƶ����������еȡ�

	2��array��Ϊ���������������Ƶģ���ͨ���ṩ���á�����ȫ�Ľӿڣ�����������գ�Ч�ʸ��ߡ���ʾ�̶����ȵ�����
	����˲�֧��push_back()��insert()�����ṩ�˶��STL����������begin(),end()��rbegin()��rend()����˺����׽�STL�㷨����array����

	3��valarray��ģ����������ֵ����ģ�����STL��һ���֡����磬��û��push_back()��insert()��������Ϊ�ܶ���ѧ
	�����ṩ��һ�����ֱ�۵Ľӿڡ�
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
	while (cin >> temp && temp > 0)						//�Ȱ����ݴ浽vector������
	{
		data.push_back(temp);
	}
	sort(data.begin(), data.end());						//��vector�����е����ݽ�������

	int size = data.size();								//ȡ��������ǰԪ�ظ���

	valarray<double> numbers(size);						
	int i;
	for (i = 0;i < size;i++)
	{
		numbers[i] = data[i];							//���ø�ֵ������vector�����е�Ԫ�ظ��Ƹ�valarray����
	}

	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);								//��sqrt��������valarray�������õ�ÿ��Ԫ�صĸ�ֲ��������һ��valarray����
	valarray<double> results(size);
	results = numbers + 2.0*sq_rts;						//��valarray���������������е������
	cout.setf(std::ios_base::fixed);					//������ʾ��ʽ
	cout.precision(4);									//���þ���ΪС�����4λ
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

