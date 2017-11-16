// 16-11.cpp : 定义控制台应用程序的入口点。
//三种插入迭代器：插入操作将添加新的元素，而不会覆盖已有的数据，并使用自动内存分配来确保能够容纳新的信息。
/*
	①back_insert_iterator：将元素插入到容器尾部
	②front_insert_iterator：将元素插入到容器头部
	③insert_iterator：将元素插入到insert_iterator构造函数的参数指定的位置前面。

	这些迭代器将容器类型作为模板参数，将实际的容器标识符作为构造函数的参数。
	例如：要为dice的vector<int>容器创建一个back_insert_iterator，可以这样做：
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
	//构建无名的back_insert_iterator 对象
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//构建无名的insert_iterator 对象
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	getchar();
    return 0;
}

