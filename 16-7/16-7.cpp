// 16-7.cpp : �������̨Ӧ�ó������ڵ㡣
//STL����׼ģ��⣩���ṩ��һ���ʾ������������������������㷨��ģ�塣
/*
	STL����һ���������ı�̣�����һ�ֲ�ͬ�ı��ģʽ-���ͱ�̣�generic programming����
	��������һ�����������Ƶĵ�Ԫ�����Դ洢���ɸ�ֵ��STL������ͬ�ʵģ����洢��ֵ��������ͬ��
	�ڵ������������������Ķ������ܹ����������ָ�����ƣ��ǹ���ָ�롣
	�ۺ��������������ں����Ķ��󣬿�������������ָ�롣
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

