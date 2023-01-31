#include <iostream>

int main()
{
	//数组实际上就是一个指针,数组中数据在内存中是连续的
	const int size = 5;
	int example[size];					//这个地址，有五个整数
	int* ptr = example;
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}

	example[1] = 5;
	*ptr = 6;
	*(ptr + 1) = 6;				//这里+1 表示指针偏移1*4字节，因为ptr是int指针   *(int*)((char*)ptr + 4) = 6;

	std::cout << example[1] << std::endl;
	std::cout << sizeof(example) << std::endl;

	//在堆上创建数组
	int* another = new int[5];
	for (int i = 0; i < 5; i++)
	{
		another[i] = 2;
	}

	//new了后 记得delete
	delete[] another;     

	std::cin.get();

}