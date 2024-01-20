#include <string>

class Klass
{
	std::string str = "hello";
};

void Fn(Klass a)
{
}

int main()
{
	Klass kls;
	Fn(kls);
}