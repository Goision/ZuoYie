#include "pch.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::setfill;
using std::setw;

void main()
{
	int Format(int number);		//计算输出格式
	int row;
	int column;
	int num;		//保存输入的数字
	int layer = 0;		//记录层数
	int n = 1;		//矩阵的数字
	int format;		//记录输出格式

	cout << "plz input the number: " << endl;
	cin >> num;
	format = Format(num);

	//申请空间.二维动态数组
	int **a = new int*[num];		//分配一个指针数组，将其首地址保存在a中
	for (int i = 0; i < num; i++)		//为指针数组的每个元素分配一个数组
	{
		a[i] = new int[num];
	}

	//使用空间
	while (true)
	{
		row = column = layer++;

		//判断是否跳出循环
		if (row > (num - 1) / 2)
		{
			break;
		}

		//Up Line
		for (; column < num - layer; column++)
		{
			a[row][column] = n++;
		}

		//Right Line
		for (; row < num - layer; row++)
		{
			a[row][column] = n++;
		}

		//Down Line
		for (; column > layer-1; column--)
		{
			a[row][column] = n++;
		}

		//Left Line
		for (; row > layer - 1; row--)
		{
			a[row][column] = n++;
		}		
	}

	//为奇数层矩阵最中间数赋值
	if (num % 2 != 0)
	{
		a[num / 2][num / 2] = num * num;
	}

	//遍历数组
	for (int i = 0; i < num; i++)
	{
		cout << endl;
		for (int j = 0; j < num; j++)
		{
			cout << setfill('0') << setw(format) << a[i][j] << "  ";
		}
		cout << endl;
	}

	//释放空间
	for (int i = 0; i < num; i++)
	{
		delete[]a[i];
	}
	a = NULL;
}

int Format(int number)
{
	int t = 0;
	number *= number;
	while (number != 0)
	{
		number = number / 10;
		t++;
	}

	return t;
}