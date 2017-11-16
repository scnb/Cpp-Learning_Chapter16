// 16-6.cpp : 定义控制台应用程序的入口点。
//智能指针可能引发的问题：
/*
		例如下面程序中的：pwin = films[2] ，这里涉及到了所有权的转换问题。

		为了解决将一个智能指针赋值给另一个智能指针导致，两个智能指针指向同一个内存时，出现两次delete同一内存
		的问题，有如下三种办法：
		①定义赋值运算符，使之执行深赋值。这样两个指针指向不同的对象，其中的一个对象是另一个对象的副本。
		②建立所有权（ownership）概念，对于特定的对象，只能有一个智能指针可以拥有它，这样只有拥有该对象
		  的智能指针的构造函数才会删除该对象。然后，让赋值操作转让所有权。对于auto_ptr和unique_ptr使用这种策略。
		③创建智能更高的指针，跟踪引用特定对象的智能指针数（称为引用计数(reference counting)）。
		  例如，赋值时，计数将加1，而指针过期时，计数将减1。仅当最后一个指针过期时，才调用delete。share_ptr采用这种策略。
*/

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::auto_ptr;

int main()
{
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs")),
	};
	auto_ptr<string> pwin;
	pwin = films[2];                   //对于auto_ptr类型智能指针，赋值操作转换了所有权，这时，films[2]变成了空指针

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0;i < 5;i++)
	{
		cout << *films[i] << endl;     //当i=2时，因为films[2]已是空指针（或者说是无效指针），所以发生错误。
	}
	cout << "The winner is " << *pwin << endl;
	getchar();
    return 0;
}

