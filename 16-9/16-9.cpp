// 16-9.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	�������д����Ե�����STL������
		��for_each()������������������ǰ����������ָ������������ĵ����������һ��������һ����������
					  for_each()�����Ѻ����������������е�ÿһ��Ԫ�ء��������������޸�������Ԫ�ص�ֵ��
		������for_each()��������forѭ�����磺
		for_each(books.begin(),books.end(),ShowReview);//����books�����е�ÿһ��Ԫ��ʹ��ShowReview����

		��random_shuffle()���ú�����������ָ������������ĵ���������������Ԫ�ؽ�������������������
		                    �ܹ�������ʡ�
		�磺
		random_shuffle(books.begin(),books.end());

		��sort()���ú���ҲҪ�������ܹ�����������ʣ����Ҹú����������汾��
		�汾1����ȫ���򣩸ú�����������ָ������ĵ�������������������Ԫ��ʹ��Ԫ���������õ�<�������������
		�汾2�������������򣩸ú�����������������ǰ����������ָ������ĵ��������������һ�������Ǻ�������
		������Ԫ��ʹ�øú��������������
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
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
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following " << books.size() << " ratings:\n" << " Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		/*��������*/
		sort(books.begin(), books.end());
		cout << "Sorte by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		/*��rating����*/
		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		/*�������*/
		random_shuffle(books.begin(), books.end());
		cout << "Sorted by random:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
	{
		cout << "No entries.";
	}
	cout << "Bye\n";
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


bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
	{
		return true;
	}
	else if (r1.title == r2.title && r1.rating < r2.rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}

