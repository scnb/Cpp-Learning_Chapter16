// 16-2.cpp : �������̨Ӧ�ó������ڵ㡣
//string������룺
/*
	1��C-����ַ���������                   2��string�������
	char info[100];							string info;
	��cin>>info;							��cin>>info;
	��getline(info,100);					��getline(cin,info);
	��cin.get(info,100);
	
	���ߺܴ��һ��������ǣ�����C����ַ��������붼Ҫָ��Ҫ��ȡ���ַ���������string����Ϊ�ܹ����ܵĲü�
	�����ַ����ĳ��̣����Բ���ָ����С��

	�����汾��getline()����һ����ѡ����������ָ��ʹ���ĸ��ַ���ȷ������ı߽硣
	getline()�����Ƕ�ȡһ�У�������������ɾ����β�Ļ��з���������������get()�����Ƕ�ȡһ�У�Ȼ�����β�Ļ��з������������С�

	string���getline()�����������ж�ȡ�ַ���������浽Ŀ������У�ֱ���������������
	�ٵ����ļ�β������������£���������eofbit�������ã�����ζ��eof()��fail()��������true��
	�������ֽ��ַ���Ĭ��Ϊ\n��������������£����ѷֽ��ַ�����������ɾ������������������
	�۶�ȡ�����ַ������ﵽ�������ֵ������ζ�Ž�������������failbit������fail()������true��
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
	getline(fin, item, ':');//ʹ�� : ��Ϊ�ֽ����������ȡ��:ʱ��ֹͣ��ȡ
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

