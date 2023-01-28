#include <iostream>

//Static.cpp中也定义了一个s_var的变量，但被标记为静态的（只在自己所在的.cpp链接），所以不会有link错误
int s_var = 10;

//在外部找e_var这个变量
extern int e_var;


void Function()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}


//类或结构体中的静态（无论创建多少个实例，x,y在内存中只有一份）
struct Entity
{
	static int x, y;
	static void print() { std::cout << x << "," << y << std::endl; }  //要注意静态方法不能访问非静态变量
};
int Entity::x;
int Entity::y;


//单例
class Singleton
{
public:
	static Singleton& Get()
	{
		 static Singleton instance;
		 return instance;
	}

	void Print()
	{
		std::cout << "Singleton" << std::endl;
	}
};


int main()
{
	std::cout << s_var << std::endl;
	std::cout << e_var << std::endl;

	Entity e;
	
	Entity::x = 9;
	Entity::y = 9;
	
	e.print();

	Function();
	Function();
	Function();

	Singleton::Get().Print();

	
	std::cin.get();
}