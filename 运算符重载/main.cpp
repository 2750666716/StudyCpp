#include <iostream>

struct Vector2
{
	float x, y;

	Vector2(float x,float y)
		:x(x),y(y){}

	Vector2 Add(const Vector2& other) const
	{
		//return Vector2(x + other.x, y + other.y);
		return *this + other;			//这里+号 是下面创建的
	}

	//重载+运算符,用于替代Add方法
	Vector2 operator+(const Vector2& other) const
	{
		//return Add(other);
		return Vector2(x + other.x, y + other.y);;
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 Multiply(const float val) const
	{
		return Vector2(x * val, y * val);
	}
	
	//重载*运算符,用于替代Multiply方法
	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	
	Vector2 operator*(const float val) const
	{
		return Vector2(x * val, y * val);
	}

	//比较运算符重载
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		//return x != other.x || y != other.y;
		return !(*this == other);
	}

};

std::ostream& operator<<(std::ostream& stream,const Vector2& vector2)
{
	return stream << vector2.x << "," << vector2.y;
}

int main()
{
	Vector2 v1(3.f, 4.f);
	Vector2 v2(6.f, 8.f);

	Vector2 v3 = v1.Add(v2);
	Vector2 v4 = v1.Multiply(2);
	
	Vector2 v5 = v1 + v2;
	Vector2 v6 = v1 * 3;
	
	std::cout << v6 << std::endl;

	if (v5 == v6)
		std::cout << "v5 == v6" << std::endl;
	else
		std::cout << "v5 != v6" << std::endl;
	

	std::cin.get();
}