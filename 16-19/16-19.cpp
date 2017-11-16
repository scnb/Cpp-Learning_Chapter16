// 16-19.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::iterator;
using std::insert_iterator;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
	vector<string> words;
	cout << "Enter words (enter quit to quit):\n";
	string input;
	while (cin >> input && input != "quit")
	{
		words.push_back(input);
	}
		cout << "You entered the following words:\n";
		for_each(words.begin(), words.end(), display);
		cout << endl;
		
		set<string> wordset;						//���ַ������ڼ����У���ת����Сд��ʽ����������ԭ�����Ͻ��в�����
		transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
		cout << "\nAlphabetic list of words:\n";
		for_each(wordset.begin(), wordset.end(), display);
		cout << endl;

		map<string, int> wordmap;					//���ַ���������ֵ�Ƶ�ʷ���map������
		set<string>::iterator si;
		for (si = wordset.begin();si != wordset.end();si++)			//���ڼ����е�ÿ���ʣ�����������ʸ���г��ֵĴ���
		{
			wordmap[*si] = count(words.begin(), words.end(), *si);	//count()������һ�������һ��ֵ��Ϊ���������������ֵ�������г��ֵĴ���
																	//map������������ʾ�������ʴ洢��ֵ�����磬wordmap["the"]��ʾ���"the"�������ֵ�������ʾ"the"���ֵĴ�����
		}

		cout << "\nWord frequency:\n";				//��ʾ�ַ�������Ƶ��
		for (si = wordset.begin();si != wordset.end();si++)
		{
			cout << *si << ": " << wordmap[*si] << endl;
		}
	getchar();
	getchar();
    return 0;
}

string & ToLower(string & st)						//�����õķ�ʽ�����ַ���
{
	transform(st.begin(), st.end(), st.begin(), toLower);		//ʹ��transform()������toLower����Ӧ�õ�ÿ��Ԫ��
	return st;
}

void display(const string & s)
{
	cout << s <<" ";
}
