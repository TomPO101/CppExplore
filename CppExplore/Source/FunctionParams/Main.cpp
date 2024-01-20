#include <iostream>
#include <string>

struct String
{
	String() {
		std::cout << "String Default Constructor\n";
	}

	String(const char* str_)
		:
		str{ str_ }
	{
		std::cout << "String Constructor\n";
	}

	~String() {
		std::cout << "String De Constructor\n";
	}

	String(const String& rhs) {
		std::cout << "String Copy Constructor\n";
	}

	String(String&& rhs) noexcept {
		std::cout << "String Move Constructor\n";
	}

	std::string str;
};

struct Klass
{
	Klass(const char* str_)
		:
		str{ str_ }
	{
		std::cout << "Klass Constructor\n";
	}

	~Klass() {
		std::cout << "Klass De Constructor\n";
	}

	Klass(const Klass& rhs) : str(rhs.str) {
		std::cout << "Klass Copy Constructor\n";
	}

	Klass(Klass&& rhs) noexcept : str(std::move(rhs.str)) {
		std::cout << "Klass Move Constructor\n";
	}

	void PrintString() const {
		std::cout << str.str << std::endl;
	}

	String str;
};

void Fn(Klass kls)
{
	kls.PrintString();
}

int main()
{
	Klass kls1("Klass1");
	Fn(kls1);

	return 0;
}
