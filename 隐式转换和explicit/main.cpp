#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name)
		:m_Name(name), m_Age(-1) {}

	Entity(int age)
		:m_Name("UnKnown"),m_Age(age){}

};

void PrintEntity(const Entity& entity)
{
	//PrintEntity
}


int main()
{
	//Entity a("Jie");
	//Entity b(22);			//尽量使用这种方式构造，要避免使用隐式构造

	//隐式地将22转换成一个Entity，构造出一个Entity
	Entity b = 22;

	//这里报错是因为explicit关键字禁用了隐式转换，必须显示调用构造函数
	//explicit 可以防止意外转换，导致出bug
	Entity a = std::string("Jie");
	PrintEntity(std::string("Jie"));
	Entity a("Jie");
	PrintEntity(Entity("Jie"));



	std::cin.get();
}