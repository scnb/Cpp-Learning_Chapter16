// 16-10.cpp : 定义控制台应用程序的入口点。
//反向迭代器(reverse_iterator)：
/*
	对reverse_iterator执行递增操作将导致它被递减。
	应用反向迭代器将容易反向打印容器的内容。
	例如：
		vector类中有一个名为rbegin()的成员函数：返回一个指向超尾的反向迭代器
				还有一个名为rend()的成员函数：返回一个指向第一个元素的反向迭代器。
		可以使用下面的语句来反向输出容器的内容：
		copy(dice.rbegin(),dice.rend(),out_iter);

	注意的问题：反向指针必须先递减，再解除引用。
				因为dice.rbegin()返回超尾，因此不能对该地址进行解除引用。同样，如果rend()返回第一个元素
				的位置，则copy()必须提早一个位置停止。
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	//copy from array to vector
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cout!\n";
	//create an ostream iterator
	ostream_iterator<int, char> out_iter(cout, " ");
	//copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";
	//使用STL函数
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	//使用显示声明迭代器
	for (ri = dice.rbegin();ri != dice.rend();ri++)
	{
		cout << *ri << ' ';
	}
	cout << endl;
	getchar();
    return 0;
}

