#include <iostream>

int main()
{
	//数组实际上就是一个指针
	const int size = 5;
	int example[size];					//这个地址，有五个整数
	int* ptr = example;
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}

	example[1] = 5;
	*(ptr + 1) = 6;

	//在堆上创建数组
	int* another = new int[5];
	for (int i = 0; i < 5; i++)
	{
		another[i] = 2;
	}
	delete[] another;     //记得delete

	std::cin.get();

}