#include <iostream>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	/*explicit*/ String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + sizeof(char)];
		memcpy(m_Buffer, string, m_Size + sizeof(char));
	}

	//拷贝构造函数（注意参数类型和类名）,用已构造的对象去构造新对象时会自动调用
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "cpoy" << std::endl;
		m_Buffer = new char[m_Size + sizeof(char)];
		memcpy(m_Buffer, other.m_Buffer, m_Size + sizeof(char));
	} 

	~String()
	{
		delete[] m_Buffer;
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

//多使用引用传参，不会有复制；
void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{

	{
		//复制了实际的数据，a和b互不影响,引用除外
		int a = 5;
		int b = a;
		int& c = a;


	}

	{
		//复制的是指针（一个地址），这两个指针指向相同的内存
		int* a = new int();
		int* b = a;

		*a = 5;
		*b = 6;

		delete a;
	}

	{
		/*当调用默认拷贝构造函数时，会将string里的成员组成新的对象赋给other，但成员m_Buffer是指针（所以是浅拷贝）
		当析构的时候，m_Buffer指针所指的内存被会释放了两次（string和other），导致程序崩溃。
		*/

		//这里其实时隐式转换，显示调用应该是String string("Jie");
		String string = "Jie";
		String other = string;		//调用了拷贝构造函数

		other[2] = 'a';
		
		PrintString(string);
		PrintString(other);
	}
	

	std::cin.get();
}