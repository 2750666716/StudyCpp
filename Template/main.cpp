#include "iostream"

//模板函数
template<typename T>
void Print(const T Value)
{
	std::cout << Value << std::endl;
}

//模板类
template<typename T,int Size>
class Array
{
private:
	T m_Array[Size];
public:
	int GetSize() const { return Size; }
};

int main()
{
	Print<int>(10);
	Print("Hello");

	Array<int, 5> array;
	
} 