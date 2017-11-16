// 16-8.cpp : 定义控制台应用程序的入口点。
//vector模板类:
/*
	所有STL容器都提供的基本方法：size() 返回容器中元素数目
								 swap() 交换两个容器的内容
								 begin() 返回一个指向容器中第一个元素的迭代器
								 end()  返回一个指向容器中最后一个元素的后一个元素的迭代器
	迭代器用法示例：如声明一个vector的double类型的迭代器：
					vector<double>::iterator pd;
					pd = score.begin();
					*pd = 22.3;
					pd++;
	vector模板私有的方法：
				①push_back() 它将元素添加到矢量末尾
				②erase() 删除矢量中给定区间的元素，接受两个参数，指定要删除的区间，如[it1,it2)，左闭右开
				③insert() 在指定位置的前面插入元素，接受三个迭代器参数，第一个参数指定了新元素的插入位置，
				  第二个和第三个迭代器参数定义了插入区间，[it1,it2)

	注意STL的区间是左开右闭的。

	16-8程序依次调用了这些方法
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
		vector<Review> oldlist(books);//使用了复制构造函数
		if (num > 3)
		{
			//删除两个条目
			books.erase(books.begin() + 1, books.begin() + 3);//调用erase方法
			cout << "After erasure:\n";
			for (pr = books.begin();pr != books.end();pr++)
			{
				ShowReview(*pr);
			}
			//插入一个条目							
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);//调用insert方法
			cout << "After insertion:\n";
			for (pr = books.begin();pr != books.end();pr++)
			{
				ShowReview(*pr);
			}
			books.swap(oldlist);       //books对象使用swap方法，与oldlist对象互换元素
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
