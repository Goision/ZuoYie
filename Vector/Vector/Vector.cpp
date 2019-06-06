#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setfill;
using std::setw;

void main()
{
	int Format(int number);		//计算输出格式
	int num;		//保存输入的数字
	int row;
	int column;
	int layer = 0;		//记录层数
	int format;		//记录输出格式
	int n = 1;		//矩阵的数字

	cout << "plz input the number: " << endl;
	cin >> num;
	format = Format(num);

	//定义二维向量
	vector<vector<int>>arr(num, vector<int>(num));

	//为二维向量赋值
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
			arr[row][column] = n++;
		}

		//Right Line
		for (; row < num - layer; row++)
		{
			arr[row][column] = n++;
		}

		//Down Line
		for (; column > layer - 1; column--)
		{
			arr[row][column] = n++;
		}

		//Left Line
		for (; row > layer - 1; row--)
		{
			arr[row][column] = n++;
		}
	}

	//为奇数层矩阵最中间数赋值
	if (num % 2 != 0)
	{
		arr[num / 2][num / 2] = num * num;
	}

	//遍历二维向量
	for (int i = 0; i < arr.size(); i++)           //arr.size()获取行向量的大小
	{
		cout << endl;
		for (int j = 0; j < arr[i].size(); j++)    //获取向量中具体每个向量的大小
		{
			cout << setfill('0') << setw(format) << arr[i][j] << "  ";
		}
		cout << endl;
	}

	// 销毁所有数据，释放内存
	arr.~vector();
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