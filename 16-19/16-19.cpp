// 16-19.cpp : 定义控制台应用程序的入口点。
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
		
		set<string> wordset;						//把字符串放在集合中，并转换成小写形式（避免了在原容器上进行操作）
		transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
		cout << "\nAlphabetic list of words:\n";
		for_each(wordset.begin(), wordset.end(), display);
		cout << endl;

		map<string, int> wordmap;					//把字符串和其出现的频率放在map容器中
		set<string>::iterator si;
		for (si = wordset.begin();si != wordset.end();si++)			//对于集合中的每个词，都计算它在矢量中出现的次数
		{
			wordmap[*si] = count(words.begin(), words.end(), *si);	//count()函数将一个区间和一个值作为参数，并返回这个值在区间中出现的次数
																	//map类可以用数组表示法来访问存储的值。例如，wordmap["the"]表示与键"the"相关联的值，这里表示"the"出现的次数。
		}

		cout << "\nWord frequency:\n";				//显示字符串出现频率
		for (si = wordset.begin();si != wordset.end();si++)
		{
			cout << *si << ": " << wordmap[*si] << endl;
		}
	getchar();
	getchar();
    return 0;
}

string & ToLower(string & st)						//已引用的方式传递字符串
{
	transform(st.begin(), st.end(), st.begin(), toLower);		//使用transform()函数将toLower函数应用到每个元素
	return st;
}

void display(const string & s)
{
	cout << s <<" ";
}
