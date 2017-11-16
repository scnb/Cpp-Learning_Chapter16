// 16-17.cpp : �������̨Ӧ�ó������ڵ㡣
//�㷨��
/*
	STL���㷨��ֳ�4�飺
	�ٷ��޸�ʽ���в������������е�ÿ��Ԫ�ؽ��в�������Щ�������޸����������ݡ�
	���޸�ʽ���в������������е�ÿ��Ԫ�ؽ��в�������Щ���������޸����������ݡ�
	���������ز���������������������������ֺ�����
	�����ֲ���������������������ۻ������������������ڲ��˻�������С�ƣ��������ڶ����ĺ�����
	
	�㷨��ͨ��������
	1�����㷨���з���ķ�ʽ֮һ�ǰ�������õ�λ�ý��з��ࡣ
		�پ͵��㷨���͵���ɹ����������������ԭʼ�����ϡ�
		�ڸ����㷨�������㷨������������������͵���һ��λ�á�
	2����Щ�㷨�������汾���͵ذ汾�͸��ư汾��
		STL��Լ���ǣ����ư汾�����ƽ���_copy��β�����ư汾������һ������ĵ������������ò���ָ������ķ���λ�á�
		����һ�����������õ�����ָ���Ƶ����һ��ֵ�����һ��λ�á�
	3�����⣬��Щ�����������İ汾�������ݽ�����Ӧ��������Ԫ�صõ��Ľ����ִ�в�������Щ�汾������ͨ����_if��β��

*/

//�ó����������ַ����������У���������еĿ��ܵ����

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string letters;
	cout << "Enter the letter grouping (quit to quit): ";
	while (cin >> letters && letters != "quit")
	{
		cout << "Permutations of " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))	//�㷨next_permutation�ṩΨһ���������
		{
			cout << letters << endl;
		}
		cout << "Enter next sequence (quit to quit): ";
	}
	cout << "Done\n";
	getchar();
    return 0;
}

