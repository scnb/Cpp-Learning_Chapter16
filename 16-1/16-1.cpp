// 16-1.cpp : �������̨Ӧ�ó������ڵ㡣
//string�ࡪ�����캯��

#include "stdafx.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string one("Lottery Winner!");//��string�����ʼ��Ϊ�ַ���
	cout << one << endl;
	string two(20, '$');//����һ������20��Ԫ�ص�string����ÿ��Ԫ�ض�����ʼ��Ϊ$
	cout << two << endl;
	string three(one);//���ø��ƹ��캯������һ��string����one��ʼ��Ϊstring����three
	cout << three << endl;
	one += "Oops!";//�����������������one����ĺ�������ַ���
	cout << one << endl;
	two = "Sorry! That was ";//�����������������string����ֵ��two����
	three[0] = 'P';//���������������ȡ���ַ����е�ÿһ���ַ������ܹ�ʹ�������ʾ��
	string four;//Ĭ�Ϲ��캯������һ���Ժ�ɶ�����и�ֵ���ַ���
	four = two + three;//����������+��������õ���two�����three������ɵ���ʱ�������������ص�=�������������ʱ�����Ƹ�four����
	cout << four << endl;
	char alls[] = "All's well that ends well.";
	string five(alls, 20);//�ù��캯����һ��C����ַ�����һ��������������������������ʾҪ���ƶ��ٸ��ַ�
	cout << five << "!\n";
	string six(alls + 6, alls + 10);//�ù��캯����һ��ģ�������template<class Iter> string(Iter begin,Iter end)
									//���캯����ʹ��begin��endָ���λ��֮���ֵ����string������г�ʼ����[begin,end)
	cout << six << ", ";
	string seven(&five[6], &five[10]);//ͬ�ϣ�ֻ�ǰ�begin��end�ı�ʾ�����ı��ˣ�ע�����������ͬ�������������Ƕ���ĵ�ַ
	cout << seven << "����\n";
	string eight(four, 7, 16);//�ù��캯����һ��string����Ĳ������ݸ��Ƶ���һ��string������
	cout << eight << " in motion!" << endl;
	getchar();
    return 0;
}

