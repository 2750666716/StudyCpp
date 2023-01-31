#include <iostream>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const
	{
		return m_Name;
	}
};

int main()
{
	Entity* e1;
	{
		Entity entity("Jie");
		e1 = &entity;
		std::cout << entity.GetName() << std::endl;
	}

	Entity* e2;
	{
		Entity* entity = new Entity("Jie");
		e2 = entity;
		std::cout << entity->GetName() << std::endl;
		delete entity;
	}

	std::cin.get();

	delete e1;
	delete e2;

}