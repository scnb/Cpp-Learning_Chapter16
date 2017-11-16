// 16-5.cpp : �������̨Ӧ�ó������ڵ㡣
//����ָ�룺
/*
		����ָ������Ϊ������ָ���������ڸö������ʱ��������������ɾ��������ָ��ָ����ڴ档

		��������ָ��ģ�壬������������ָ��Ķ��󣬿��Խ�new��õĵ�ַ�������ֶ��󡣵�����ָ�����ʱ��
		������������ʹ��delete���ͷ��ڴ档

		���磺auto_ptr�������¹��캯����
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
#include <memory>					//��������ָ�룬�������ͷ�ļ�

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
	/*�ô�������ֱ��ÿһ������ָ��������������ڴ����֮��ʱ�����Զ�������������*/
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));//ע����auto_ptr<Report>�����ü����Ŷ�����Բ����
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

