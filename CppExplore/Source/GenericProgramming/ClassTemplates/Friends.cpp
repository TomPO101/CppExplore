#include <iostream>
#include <string>

template<typename T>
class Klass
{
public:
	Klass(const T v) : var{ v } {};

	const T& Add(const T val)
	{
		var += val;
		return var;
	}

private:
	T var;
};

int main()
{

}