#include <string>

template<typename T>
void Fn(const T&& c)
{
}

void Fn1(std::string x)
{
}

int main()
{
	auto s = std::string("hello");
	Fn(std::string("hello"));
	//Fn1(std::move(s));
	return 0;
}