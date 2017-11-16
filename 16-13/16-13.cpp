// 16-13.cpp : 定义控制台应用程序的入口点。
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

	ostream_iterator<string, char> out(cout, " ");//定义输出迭代器
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;
	//求并集
	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	//求交集
	cout << "Intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	//求两个集合的差
	cout << "Difference of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "Set C:\n";
	//使用了匿名的插入迭代器，将A和B的并集插入到C的集合中
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;
	//显示区间
	cout << "Showing a range:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;
	getchar();
    return 0;
}

