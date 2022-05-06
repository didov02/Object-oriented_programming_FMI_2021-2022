#include <iostream>
#pragma warning (disable: 4996)

class String
{
	char* data;
public:
	String() = default;
	String(const char* str) //constructor
	{
		std::cout << "Created" << std::endl;
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}

	String(const String& other) //Copy constructor
	{
		std::cout << "Copied" << std::endl;
		data = new char[strlen(other.data) + 1];
		strcpy(data, other.data);
	}

	String(String&& other)
	{
		std::cout << "Move" << std::endl;
		this->data = other.data;

		other.data = nullptr;
	}

	String& operator=(String&& other)
	{
		if (this != &other)
		{
			delete[] data;
			std::cout << "Move operator" << std::endl;
			this->data = other.data;

			other.data = nullptr;
		}
		return *this;
	}

	~String()
	{
		std::cout << "Deleted" << std::endl;
		delete[] data;
	}

	void print()
	{
		std::cout << data << std::endl;
	}
};

class Entity
{
	String name;
public:
	Entity(const String& name) : 
		name(std::move(name)) {}

	void print()
	{
		name.print();
	}
};

int main()
{
	//Entity entity("MyEntity");
	//Entity entity(String("MyEntity"));
	//entity.print();

	//String str1("Example1");;
	//String str2("Example2");
	//souce = std::move("Nikola");
	//souce.print();
}