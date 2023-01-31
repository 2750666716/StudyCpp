#include <iostream>
#include <string>

int main()
{
	//"Jie"是一个字符串字面量，字符串字面量是存储在内存只读部分的
	const char* name = "Jie";											//实际上有四个字符，最后一个是空终止符\0
	char name2[4] = { 'J','i','e','\0' };								//'\0'表示字符串终止
	const wchar_t* name4 = L"Jie";										//宽字符

	std::string name3 = std::string("Jie") + "Hello";                   //string的append
	name3.append("Hello");
	bool contains = name3.find("ll") != std::string::npos;				//string的find

	//多行字符串
	const char* example = R"(											
Line1
Line2
Line3)";


	std::cout << name2 << std::endl;

	std::cout << name3 << std::endl;									//要包含string头文件，不然输出不了

	std::cout << example << std::endl;

	
	std::cin.get();

}