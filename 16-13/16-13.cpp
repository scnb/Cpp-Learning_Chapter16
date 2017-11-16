// 16-13.cpp : �������̨Ӧ�ó������ڵ㡣
//����������associative container)����ֵ���������һ�𣬲�ʹ�ü�������ֵ�����������ṹ��
/*
		 STL�ṩ��4�ֹ���������set��multiset��map��multimap
		 set����ֵ���������ͬ������Ψһ�ġ�
		 multiset��������set��ֻ�ǿ����ж��ֵ�ļ���ͬ��
		 map��ֵ��������Ͳ�ͬ������Ψһ�ģ�ÿ����ֻ��Ӧһ��ֵ��
		 multimap����map���ƣ�ֻ��һ�������Զ�Ӧ���ֵ��

���ϵ�һЩ��׼������
		 �ٲ��������������Ϻϲ�������ݣ����ұ��ּ���Ψһ�ԡ�
		 �ڽ��������������϶��е�Ԫ�ء�
		 ���������ϵĲ��ǵ�һ�����ϼ�ȥ�������϶��е�Ԫ�ء�

		 set_union()����������5��������������ǰ���������������˵�һ�����ϵ����䣬����������������
						  �����˵ڶ������ϵ����䣬���һ���������������������ָ����������ϸ��Ƶ�ʲôλ�á�
			ʹ�������������set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<string,char> out(cout," "));
			��ʹ�ò����������set_union(A.begin(),A.end().B.begin(),B.end(),insert_iterator<set<string> >(C,C.begin));
		 set_intersection()��set_difference()�ֱ���ҽ����ͻ���������ϵĲ

1��setʾ����
		set�ǹ������ϣ��ɷ�ת���������Ҽ���Ψһ�ģ����Բ��ܴ洢�����ͬ��ֵ��
		setҲʹ��ģ�������ָ��Ҫ�洢��ֵ���ͣ�set<string> A;
		set����һ����������������Ϊ�����Ĺ��캯�����ṩ��һ�ֽ����ϳ�ʼ��Ϊ�������ݵļ򵥷�����
		���磺
		string s1[6];
		set<string> A(s1,s1+6);
		���еڶ���ģ������ǿ�ѡ�ģ�ָ�����ڶԼ���������ıȽϺ��������

		�������õ�set������
			lower_bound()��������Ϊ����������һ�����������õ�����ָ�򼯺��е�һ����С�ڼ������ĳ�Ա��
			upper_bound()��������Ϊ����������һ�����������õ�����ָ�򼯺��е�һ�����ڼ������ĳ�Ա��

2��multimapʾ����
			multimapҲ�ǿɷ�ת�ġ���������Ĺ���������������ֵ�����Ͳ�ͬ����ͬһ�������ܺͶ��ֵ�������
			������multimap����ʹ��ģ�����ָ���������ͺʹ洢��ֵ���͡����⣬�����������ǿ�ѡ�ģ�ָ�����ڶԼ�
			����ıȽϺ��������
			multimap<int,string> codes;

			Ϊ�˽���Ϣ�����һ��ʵ�ʵ�ֵ���ͽ������ͺ��������ͽ��Ϊһ�ԡ�
			Ϊ�ˣ�STLʹ��ģ���ཫ������ֵ�洢��һ�������С�
			���磬codes�����ֵ����Ϊpair<const int,string>
			���磺��������Ϊ�����洢��������
			��pair<const int,string> item(213,"Los Angeles");
			codes.insert(item);
			��codes.insert(pair<const int,string> (213,"Los Angeles"));

			����pair���󣬿���ʹ��first��second���������������֡�
			���磺item.first   item.second

			������Ա������
			count()�������ܼ���Ϊ�����������ؾ��иü���Ԫ����Ŀ
			equal_range()�����ü���Ϊ�������ҷ������������������Ǳ�ʾ��������ü�ƥ�䡣
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::set;
using std::ostream_iterator;
using std::insert_iterator;

int main()
{
	const int N = 6;
	string s1[N] = { "buffoon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };

	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char> out(cout, " ");//�������������
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;
	//�󲢼�
	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	//�󽻼�
	cout << "Intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	//���������ϵĲ�
	cout << "Difference of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "Set C:\n";
	//ʹ���������Ĳ������������A��B�Ĳ������뵽C�ļ�����
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;
	//��ʾ����
	cout << "Showing a range:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;
	getchar();
    return 0;
}

