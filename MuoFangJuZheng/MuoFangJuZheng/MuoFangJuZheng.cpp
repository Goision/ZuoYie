#include "pch.h"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

void main()
{
	void assignment(int h, int l, int**a);		//给数组赋值函数
	void initialization(int**a, int n);		//为数组赋初值，方便判断
	void traversal(int**a, int n);		//遍历数组
	int input = NULL;

	//输入阶数
	cout << "plz input the number: " << endl;
	cin >> input;
	while (input % 2 == 0)
	{
		cout << "worry input, ";
		cout << "plz input the number: " << endl;
		cin >> input;
	}
	cout << endl;

	//定义二维数组
	int **arr = new int*[input];
	for (int i = 0; i < input; i++)
	{
		arr[i] = new int[input];
	}

	initialization(arr, input);

	assignment(input, input, arr);
	
	traversal(arr, input);

	//释放空间
	for (int i = 0; i < input; i++)
	{
		delete[]arr[i];
	}
	arr = NULL;
}

void initialization(int**a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
}

void traversal(int**a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
		cout << endl;
	}	
}

void assignment(int h, int l, int**a)
{
	int limit = h;
	int number = h * l;

	h = 0;
	l = (l - 1) / 2;

	a[h][l] = 1;

	for (int i = 0; i < number - 1; i++)
	{
		h--;
		l++;

		if (h < 0 && l > limit - 1)
		{
			h += 2;
			l -= 1;
		}
		if (h < 0 && l <= limit - 1)
		{
			h += limit;
		}
		if (l > limit - 1 && h >= 0)
		{
			l -= limit;
		}
		if (a[h][l] != 0)
		{
			l--;
			h += 2;
		}

		a[h][l] = i + 2;		
	}	
}