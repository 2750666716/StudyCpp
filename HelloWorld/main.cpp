#include <iostream>
#include "Log.h"

int main()
{

	const char* string = "Hello";
	for (int i = 0; i < 6; i++)
	{
		const char c = string[i];

		std::cout << c << std::endl;
	}

	Log("Hello World");
	std::cin.get();
}

//断点后F5继续、或者shift+F11跳出函数，F11逐语句，F10逐过程