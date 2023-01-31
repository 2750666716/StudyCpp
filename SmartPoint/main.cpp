#include <iostream>
#include <memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{

	}

};

int main()
{
	{
		std::shared_ptr<Entity> e0;
		{
			//unique指针不能复制；因为unique的定义里把拷贝构造函数和拷贝构造操作符delete了。
			//std::unique_ptr<Entity> entity(new Entity());
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();

			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;					//这里会增加共享指针的引用计数
		}
	}

	{
		//弱指针可以用来判断当前共享指针是否有效，弱指针不会增加引用计数
		std::weak_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;					
		}
		//注意：当程序执行到e0所在作用域外后，sharedEntity才被释放，这时引用计数为0
		//程序执行到这里时e0已经是野指针了（标志sharedEntity是否存活）
	}
	

	

	std::cin.get();
}