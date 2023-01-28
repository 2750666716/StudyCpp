#include <iostream>
#include <string>

class Entity
{
public:
	virtual std::string GetName() { return "Entity"; }
};

class Player :public Entity
{
private:
	std::string m_name;
public:
	Player(const std::string& name)
		:m_name(name)
	{}

	virtual std::string GetName() override{ return m_name; }
};

int main()
{
	//Entity*  entity = new Entity();
	Player* player=new Player("yang");
	Entity* entity = player;

	std::cout << entity->GetName() << std::endl;
	std::cout << player->GetName() << std::endl;
	std::cin.get();
}