// 16-14.cpp : 定义控制台应用程序的入口点。
//关联容器（associative container)：将值与键关联在一起，并使用键来查找值。（基于树结构）
/*
		STL提供了4种关联容器：set、multiset、map和multimap
		set：其值类型与键相同，键是唯一的。
		multiset：类似与set，只是可能有多个值的键相同。
		map：值与键的类型不同，键是唯一的，每个键只对应一个值。
		multimap：与map类似，只是一个键可以对应多个值。

		集合的一些标准操作：
		①并集包含两个集合合并后的内容，并且保持键的唯一性。
		②交集包含两个集合都有的元素。
		③两个集合的差是第一个集合减去两个集合都有的元素。

		set_union()函数：接受5个迭代器参数，前两个迭代器定义了第一个集合的区间，接下来的两个迭代
		定义了第二个集合的区间，最后一个迭代器是输出迭代器，指出将结果集合复制到什么位置。
		使用输出迭代器：set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<string,char> out(cout," "));
		或使用插入迭代器：set_union(A.begin(),A.end().B.begin(),B.end(),insert_iterator<set<string> >(C,C.begin));
		set_intersection()和set_difference()分别查找交集和获得两个集合的差。

		1、set示例：
		set是关联集合，可反转，可排序，且键是唯一的，所以不能存储多个相同的值。
		set也使用模板参数来指定要存储的值类型：set<string> A;
		set具有一个将迭代器区间作为参数的构造函数：提供了一种将集合初始化为数组内容的简单方法。
		例如：
		string s1[6];
		set<string> A(s1,s1+6);
		其中第二个模板参数是可选的，指出用于对键进行排序的比较函数或对象。

		两个有用的set方法：
		lower_bound()：将键作为参数并返回一个迭代器，该迭代器指向集合中第一个不小于键参数的成员。
		upper_bound()：将键作为参数并返回一个迭代器，该迭代器指向集合中第一个大于键参数的成员。

		2、multimap示例：
		multimap也是可反转的、经过排序的关联容器，但键和值的类型不同，且同一个键可能和多个值相关联。
		基本的multimap声明使用模板参数指定键的类型和存储的值类型。另外，第三个参数是可选的，指出用于对键
		排序的比较函数或对象。
		multimap<int,string> codes;

		为了将信息结合在一起，实际的值类型将键类型和数据类型结合为一对。
		为此，STL使用模板类将这两种值存储到一个对象中。
		例如，codes对象的值类型为pair<const int,string>
		例如：用区号作为键来存储城市名：
		①pair<const int,string> item(213,"Los Angeles");
		  codes.insert(item);
		②codes.insert(pair<const int,string> (213,"Los Angeles"));

		对于pair对象，可以使用first和second来访问其两个部分。
		例如：item.first   item.second
		
		其他成员函数：
		count()函数接受键作为参数，并返回具有该键的元素数目
		equal_range()函数用键作为参数，且返回两个迭代器，它们表示的区间与该键匹配。
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

