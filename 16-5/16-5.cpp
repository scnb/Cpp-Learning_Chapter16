// 16-5.cpp : 定义控制台应用程序的入口点。
//智能指针：
/*
		智能指针是行为类似于指针的类对象，在该对象过期时，其析构函数将删除该智能指针指向的内存。

		三种智能指针模板，都定义了类似指针的对象，可以将new获得的地址赋给这种对象。当智能指针过期时，
		其析构函数将使用delete来释放内存。

		例如：auto_ptr包含如下构造函数：
		template<class X> 
		class auto_ptr
		{
			public:
			explicit auto_ptr(X * p = 0) throw();
		}
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>					//创建智能指针，必须包含头文件

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::auto_ptr;
using std::unique_ptr;
using std::shared_ptr;

class Report
{
private:
	string str;
public:
	Report(const string s) : str(s) { cout << "Object Created!\n"; }
	~Report() { cout << "Object deleted!\n"; }
	void comment() const { cout << str << "\n"; }
};


int main()
{
	/*用代码块来分别把每一种智能指针包括，当程序在代码块之外时，将自动调用析构函数*/
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));//注意在auto_ptr<Report>这里用尖括号而不是圆括号
		ps->comment();
	}
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	getchar();
    return 0;
}

