#include <iostream>

//这段表示，只有预处理中定义YJ_DEBUG才执行语句，否则将替换为空
//说明这些宏只是用于调试(Debug),在release下将宏替换为空语句(不会执行打印和LOG)
#if YJ_DEBUG == 1
#define 打印(message) std::cout <<message<<std::endl;
#define LOG(message) std::cout <<message<<std::endl;
#else
#define 打印(message)
#define LOG(message)
#endif // YJ_DEBUG


//这里使用多行宏代替了main函数，这里反斜杠(\)是enter换行的转义符
#define MAIN int main()\
{\
	LOG(5);\
	std::cin.get();\
}

MAIN

//int main()
//{
//	打印(5);
//	LOG(5);
//	std::cin.get();
//}