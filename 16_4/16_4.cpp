// 16_4.cpp : �������̨Ӧ�ó������ڵ㡣
//string����������ܣ�
/*
	��ɾ���ַ�����ȫ���򲿷�����
	����һ���ַ����Ĳ��ֻ�ȫ�������滻��һ���ַ����Ĳ��ֻ�ȫ������
	�۽����ݲ��뵽�ַ����л�ɾ���ַ����е�����
	�ܽ�һ���ַ����Ĳ��ֻ�ȫ����������һ���ַ����Ĳ��ֻ�ȫ�����ݽ��бȽ�
	�ݴ��ַ�������ȡ���ַ���
	�޽�һ���ַ����е����ݸ��Ƶ���һ���ַ�����
	�߽��������ַ���������
	�෽��capacity()���ط������ǰ�ڴ��Ĵ�С
	��reserve()�����ڴ�����С����
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

