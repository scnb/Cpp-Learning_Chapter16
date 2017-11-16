// 16_4.cpp : 定义控制台应用程序的入口点。
//string类的其他功能：
/*
	①删除字符串的全部或部分内容
	②用一个字符串的部分或全部内容替换另一个字符串的部分或全部内容
	③将数据插入到字符串中或删除字符串中的数据
	④将一个字符串的部分或全部内容与另一个字符串的部分或全部内容进行比较
	⑤从字符串中提取子字符串
	⑥将一个字符串中的内容复制到另一个字符串中
	⑦交换两个字符串的内容
	⑧方法capacity()返回分配给当前内存块的大小
	⑨reserve()请求内存块的最小长度
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Size:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "Capacities:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
	getchar();
    return 0;
}

