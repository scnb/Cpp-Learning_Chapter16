// 16-17.cpp : 定义控制台应用程序的入口点。
//算法：
/*
	STL将算法库分成4组：
	①非修改式序列操作：对区间中的每个元素进行操作，这些操作不修改容器的内容。
	②修改式序列操作：对区间中的每个元素进行操作，这些操作可以修改容器的内容。
	③排序和相关操作：包括多个排序函数和其他各种函数。
	④数字操作：包括将区间的内容累积，计算两个容器的内部乘积，计算小计，计算相邻对象差的函数。
	
	算法的通用特征：
	1、对算法进行分类的方式之一是按结果放置的位置进行分类。
		①就地算法：就地完成工作，结果被保存在原始数据上。
		②复制算法：这种算法创建拷贝，将结果发送到另一个位置。
	2、有些算法有两个版本：就地版本和复制版本。
		STL的约定是，复制版本的名称将以_copy结尾。复制版本将接受一个额外的迭代器参数，该参数指定结果的放置位置。
		返回一个迭代器，该迭代器指向复制的最后一个值后面的一个位置。
	3、另外，有些函数有这样的版本，即根据将函数应用于容器元素得到的结果来执行操作。这些版本的名称通常以_if结尾。

*/

//该程序对输入的字符串进行排列，并输出所有的可能的组合

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
		while (next_permutation(letters.begin(), letters.end()))	//算法next_permutation提供唯一的排列组合
		{
			cout << letters << endl;
		}
		cout << "Enter next sequence (quit to quit): ";
	}
	cout << "Done\n";
	getchar();
    return 0;
}

