// 16-11.cpp : �������̨Ӧ�ó������ڵ㡣
//���ֲ�����������������������µ�Ԫ�أ������Ḳ�����е����ݣ���ʹ���Զ��ڴ������ȷ���ܹ������µ���Ϣ��
/*
	��back_insert_iterator����Ԫ�ز��뵽����β��
	��front_insert_iterator����Ԫ�ز��뵽����ͷ��
	��insert_iterator����Ԫ�ز��뵽insert_iterator���캯���Ĳ���ָ����λ��ǰ�档

	��Щ������������������Ϊģ���������ʵ�ʵ�������ʶ����Ϊ���캯���Ĳ�����
	���磺ҪΪdice��vector<int>��������һ��back_insert_iterator��������������
	back_insert_iterator<vector<int> > back_iter(dice);
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::string;
using std::back_insert_iterator;
using std::insert_iterator;


void output(const string & s) { cout << s << " "; }

int main()
{
	string s1[4] = { "fine","fish","fashion","fate" };
	string s2[2] = { "busy","bats" };
	string s3[2] = { "silly","singers" };
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//����������back_insert_iterator ����
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//����������insert_iterator ����
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	getchar();
    return 0;
}

