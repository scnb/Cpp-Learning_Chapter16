// 16-21.cpp : 定义控制台应用程序的入口点。
//slice类：该类对象可用作数组索引（特殊的下标指定功能），在这种情况下，它表示的不是一个值而是一组值。
/*
	slice对象被初始化为三个整数值：起始索引、索引数和元素跨距。
	①起始索引是第一个被选中的元素的索引
	②索引数指出要选中多少个元素
	③跨距表示元素之间的间隔。

	slice类的这种特殊的下标指定功能，导致可以使用一个一维valarray对象来表示二维数据。
	假设一个valarray对象valint中包含12个元素，表示这是一个4行3列的矩阵。slice(0,3,1)表示第一行的元素，
	而slice(0,4,3)则表示第一列的元素。
*/

#include "stdafx.h"
#include <iostream>
#include <valarray>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::valarray;

const int SIZE = 12;
typedef valarray<int> vint;
void show(const vint & v, int cols);

int main()
{
	using std::slice;
	vint valint(SIZE);

	int i;
	for (i = 0;i < SIZE;i++)
	{
		valint[i] = rand() % 10;
	}
	cout << "Original array:\n";
	show(valint, 3);

	vint vcol(valint[slice(1, 4, 3)]);				//单独拿出第二列来赋值给vcol
	cout << "Second col:\n";
	show(vcol, 1);									//在一列中显示vcol

	vint vrow(valint[slice(3, 3, 1)]);				//单独拿出来第二行来赋值给vrow
	cout << "First row:\n";
	show(vrow, 3);
	valint[slice(2, 4, 3)] = 10;					//将valint这个二维数组的第二列（即最后一列）赋值为10
	cout << "Set last column to 10:\n";
	show(valint, 3);
	
	cout << "Set first column to sum of next two:\n";
	//没有为slices类定义+运算符，所以需要转换成valarray<int>，使用slice指定的元素创建一个完整的valint对象
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);//把第二列和第三列对应元素和赋值给第一列
	show(valint, 3);
	getchar();
	return 0;
}

void show(const vint & v, int cols)				//cols表示该二维数组的列数
{
	int lim = v.size();
	for (int i = 0;i < lim;i++)
	{
		cout.widen(3);
		cout << v[i];
		if (i%cols == cols - 1)					//表示已经到了最后一列，该换行了
		{
			cout << endl;
		}
		else								    //否则就以空格隔开
		{
			cout << ' ';
		}
	}
	if (lim % cols != 0)						//二维数组元素个数不能整除列数，这是什么情况？原始数据有问题？
	{
		cout << endl;
	}
}