// 16-14.cpp : �������̨Ӧ�ó������ڵ㡣
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
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;

typedef int KeyType;
typedef std::pair<const KeyType, string> Pair;
typedef std::multimap<KeyType, string> MapCode;

int main()
{
	MapCode codes;
	codes.insert(Pair(415, "San Francisco"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));

	cout << "Number of cities with area code 415: " << codes.count(415) << endl;
	cout << "Number of cities with area code 718: " << codes.count(718) << endl;
	cout << "Number of cities with area code 510: " << codes.count(510) << endl;
	cout << "Area Code	City\n";
	MapCode::iterator it;
	for (it = codes.begin();it != codes.end();it++)
	{
		cout << "	" << (*it).first << "	" << (*it).second << endl;
	}
	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	cout << "Cities with area code 718:\n";
	for (it = range.first;it != range.second;it++)
	{
		cout<<(*it).second << endl;
	}
	getchar();
    return 0;
}

