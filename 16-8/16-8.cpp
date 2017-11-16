// 16-8.cpp : �������̨Ӧ�ó������ڵ㡣
//vectorģ����:
/*
	����STL�������ṩ�Ļ���������size() ����������Ԫ����Ŀ
								 swap() ������������������
								 begin() ����һ��ָ�������е�һ��Ԫ�صĵ�����
								 end()  ����һ��ָ�����������һ��Ԫ�صĺ�һ��Ԫ�صĵ�����
	�������÷�ʾ����������һ��vector��double���͵ĵ�������
					vector<double>::iterator pd;
					pd = score.begin();
					*pd = 22.3;
					pd++;
	vectorģ��˽�еķ�����
				��push_back() ����Ԫ����ӵ�ʸ��ĩβ
				��erase() ɾ��ʸ���и��������Ԫ�أ���������������ָ��Ҫɾ�������䣬��[it1,it2)������ҿ�
				��insert() ��ָ��λ�õ�ǰ�����Ԫ�أ�����������������������һ������ָ������Ԫ�صĲ���λ�ã�
				  �ڶ����͵��������������������˲������䣬[it1,it2)

	ע��STL�����������ұյġ�

	16-8�������ε�������Щ����
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Review
{
	string title;
	int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);
	}
	int num = books.size();
	if (num > 0)
	{
		cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
		for (int i = 0;i < num;i++)
		{
			ShowReview(books[i]);
		}
		cout << "Reprising:\n" << "Rating\tBook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin();pr != books.end();pr++)
		{
			ShowReview(*pr);
		}
		vector<Review> oldlist(books);//ʹ���˸��ƹ��캯��
		if (num > 3)
		{
			//ɾ��������Ŀ
			books.erase(books.begin() + 1, books.begin() + 3);//����erase����
			cout << "After erasure:\n";
			for (pr = books.begin();pr != books.end();pr++)
			{
				ShowReview(*pr);
			}
			//����һ����Ŀ							
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);//����insert����
			cout << "After insertion:\n";
			for (pr = books.begin();pr != books.end();pr++)
			{
				ShowReview(*pr);
			}
			books.swap(oldlist);       //books����ʹ��swap��������oldlist���󻥻�Ԫ��
			cout << "Swaping oldlist with books:\n";
			for (pr = books.begin();pr != books.end();pr++)
			{
				ShowReview(*pr);
			}
		}
	}
	else
	{
		cout << "Nothing entered,nothing gained.\n";
	}
	getchar();
    return 0;
}

bool FillReview(Review & rr)
{
	cout << "Enter book title(quit to quit): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
	{
		return false;
	}
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin)
	{
		return false;
	}
	//��ȡ���з�
	while (cin.get() != '\n')
	{
		continue;
	}
	return true;
}

void ShowReview(const Review & rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}
