#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
	mutable int m_DebugCount = 0;       //mutable关键字表示变量不受const限制，是可变的
public:
	int GetX() const				//这种const在方法名后，只在类中有效。表示不会修改类成员
	{
		m_DebugCount++;
		return m_X;
	}

	int GetX()
	{
		return m_X;
	}

	void SetX(int x)
	{
		m_X = x;
	}
};

void PrintEntity(const Entity& e)
{
	std::cout << e.GetX() << std::endl;   //注意，这里使用了const版本的GetX()方法
}


int main()
{
	//声明一个常量，表示最大年龄，
	const int MAX_AGE = 100;

	//常量指针，能改变指针本身，但不能改变指针所指的内容
	const int* a = new int;
	//*a = 2;//错误
	a = &MAX_AGE;

	//指针常量，能改变指针所指的内容，但不能改变指针本身
	int* const b = new int;
	*b = 2;
	//b = &MAX_AGE;//错误


	std::cout << *b << std::endl;

	std::cout << *b << std::endl;

	std::cin.get();

}