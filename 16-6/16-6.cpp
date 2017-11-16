// 16-6.cpp : �������̨Ӧ�ó������ڵ㡣
//����ָ��������������⣺
/*
		������������еģ�pwin = films[2] �������漰��������Ȩ��ת�����⡣

		Ϊ�˽����һ������ָ�븳ֵ����һ������ָ�뵼�£���������ָ��ָ��ͬһ���ڴ�ʱ����������deleteͬһ�ڴ�
		�����⣬���������ְ취��
		�ٶ��帳ֵ�������ʹִ֮���ֵ����������ָ��ָ��ͬ�Ķ������е�һ����������һ������ĸ�����
		�ڽ�������Ȩ��ownership����������ض��Ķ���ֻ����һ������ָ�����ӵ����������ֻ��ӵ�иö���
		  ������ָ��Ĺ��캯���Ż�ɾ���ö���Ȼ���ø�ֵ����ת������Ȩ������auto_ptr��unique_ptrʹ�����ֲ��ԡ�
		�۴������ܸ��ߵ�ָ�룬���������ض����������ָ��������Ϊ���ü���(reference counting)����
		  ���磬��ֵʱ����������1����ָ�����ʱ����������1���������һ��ָ�����ʱ���ŵ���delete��share_ptr�������ֲ��ԡ�
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
	pwin = films[2];                   //����auto_ptr��������ָ�룬��ֵ����ת��������Ȩ����ʱ��films[2]����˿�ָ��

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0;i < 5;i++)
	{
		cout << *films[i] << endl;     //��i=2ʱ����Ϊfilms[2]���ǿ�ָ�루����˵����Чָ�룩�����Է�������
	}
	cout << "The winner is " << *pwin << endl;
	getchar();
    return 0;
}

