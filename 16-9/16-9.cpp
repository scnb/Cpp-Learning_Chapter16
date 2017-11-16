// 16-9.cpp : 定义控制台应用程序的入口点。
//
/*
	三个具有代表性的其他STL函数：
		①for_each()：它接受三个参数，前两个参数是指定容器中区间的迭代器，最后一个参数是一个函数对象。
					  for_each()函数把函数参数用于容器中的每一个元素。函数参数不能修改容器中元素的值。
		可以用for_each()函数代替for循环，如：
		for_each(books.begin(),books.end(),ShowReview);//即对books对象中的每一个元素使用ShowReview方法

		②random_shuffle()：该函数接受两个指定容器中区间的迭代器，并对其间的元素进行随机排序。容器必须得
		                    能够随机访问。
		如：
		random_shuffle(books.begin(),books.end());

		③sort()：该函数也要求容器能够进行随机访问，并且该函数有两个版本。
		版本1：（全排序）该函数接受两个指定区间的迭代器参数，并对其间的元素使用元素类型内置的<运算符进行排序。
		版本2：（完整弱排序）该函数接受三个参数，前两个参数是指定区间的迭代器参数，最后一个参数是函数对象。
		对其间的元素使用该函数对象进行排序。
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

		/*升序排序*/
		sort(books.begin(), books.end());
		cout << "Sorte by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		/*按rating排序*/
		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		/*随机排序*/
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
	//读取换行符
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

