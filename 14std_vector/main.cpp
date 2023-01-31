#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x,float y,float z)
		:x(x),y(y),z(z)
	{}

	//拷贝构造函数
	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

//std::vector基本用法，vectro是STL（标准模板库）里的
void VectorBase()
{
	std::vector<float> Vertexes;
	Vertexes.push_back(1.f);
	Vertexes.push_back(2.f);
	Vertexes.push_back(3.f);

	//for (int i = 0; i < Vertexes.size(); i++)
	//{
	//	std::cout << Vertexes[i] << std::endl;
	//}

	//去除数组第二个元素
	Vertexes.erase(Vertexes.begin() + 1);

	//const加引用 避免复制
	for (const float& v : Vertexes)
	{
		std::cout << v << std::endl;
	}

	//清空数组
	Vertexes.clear();
}

//std::vector的没有使用优化时，这里的三次push_back共会有六次拷贝
void VectorNotOptimize()
{
	//每次push_back，就是给vertexes重新分配一块更大的内存来确保能装下新的元素数据

	std::vector<Vertex> vertexes;
	vertexes.push_back(Vertex(1,2,3));
	vertexes.push_back(Vertex(4,5,6));
	vertexes.push_back(Vertex(7,8,9));

}

//std::vector的使用优化
void VectorOptimize()
{
	std::vector<Vertex> vertexes;

	//优化策略一：预先分配一定的容量
	vertexes.reserve(3);

	vertexes.push_back(Vertex(1,2,3));
	vertexes.push_back(Vertex(4,5,6));
	//优化策略二：使用emplace_back,然后只传入Vertex构造函数的参数列表(7,8,9)。也就是直接在vector的内存里使用参数列表构造一个对象。
	//			  如果参数填Vertex(7,8,9),则是先构造了一个对象，再复制到实际的数组中，所以会调用Vertex(7,8,9)对象的拷贝构造
	vertexes.emplace_back(7,8,9);

}


int main()
{
	VectorBase();

	//VectorNotOptimize();

	VectorOptimize();


	std::cin.get();
}