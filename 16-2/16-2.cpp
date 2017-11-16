// 16-2.cpp : 定义控制台应用程序的入口点。
//string类的输入：
/*
	1、C-风格字符串的输入                   2、string类的输入
	char info[100];							string info;
	①cin>>info;							①cin>>info;
	②getline(info,100);					②getline(cin,info);
	③cin.get(info,100);
	
	两者很大的一个区别就是：对于C风格字符串的输入都要指定要读取的字符个数，而string类因为能够智能的裁剪
	输入字符串的长短，所以不用指定大小。

	两个版本的getline()都有一个可选参数，用于指定使用哪个字符来确定输入的边界。
	getline()函数是读取一行，但从输入流中删除行尾的换行符并不保留它，而get()函数是读取一行，然后把行尾的换行符留在输入流中。

	string类的getline()函数从输入中读取字符，并将其存到目标对象中，直到出现下列情况：
	①到达文件尾，在这种情况下，输入流的eofbit将被设置，这意味着eof()和fail()都将返回true；
	②遇到分界字符（默认为\n），在这种情况下，将把分界字符从输入流中删除，但并不保留它。
	③读取到的字符数将达到最大允许值，这意味着将设置输入流的failbit，方法fail()将返回true；
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		std::cerr << "Can't open file.Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');//使用 : 作为分解符，即当读取到:时，停止读取
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
	getchar();
	getchar();
    return 0;
}

