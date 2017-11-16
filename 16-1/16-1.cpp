// 16-1.cpp : 定义控制台应用程序的入口点。
//string类——构造函数

#include "stdafx.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string one("Lottery Winner!");//将string对象初始化为字符串
	cout << one << endl;
	string two(20, '$');//创建一个包含20个元素的string对象，每个元素都被初始化为$
	cout << two << endl;
	string three(one);//利用复制构造函数，将一个string对象one初始化为string对象three
	cout << three << endl;
	one += "Oops!";//利用重载运算符，在one对象的后面添加字符串
	cout << one << endl;
	two = "Sorry! That was ";//利用重载运算符，将string对象赋值给two对象
	three[0] = 'P';//利用重载运算符，取得字符串中的每一个字符，即能够使用数组表示法
	string four;//默认构造函数创建一个以后可对其进行赋值的字符串
	four = two + three;//先利用重载+运算符，得到由two对象和three对象组成的临时对象，再利用重载的=运算符，将该临时对象复制给four对象
	cout << four << endl;
	char alls[] = "All's well that ends well.";
	string five(alls, 20);//该构造函数将一个C风格字符串和一个整数当作参数，整数参数表示要复制多少个字符
	cout << five << "!\n";
	string six(alls + 6, alls + 10);//该构造函数有一个模板参数：template<class Iter> string(Iter begin,Iter end)
									//构造函数将使用begin和end指向的位置之间的值，对string对象进行初始化。[begin,end)
	cout << six << ", ";
	string seven(&five[6], &five[10]);//同上，只是把begin和end的表示方法改变了，注意对象名（不同于数组名）不是对象的地址
	cout << seven << "……\n";
	string eight(four, 7, 16);//该构造函数将一个string对象的部分内容复制到另一个string对象中
	cout << eight << " in motion!" << endl;
	getchar();
    return 0;
}

