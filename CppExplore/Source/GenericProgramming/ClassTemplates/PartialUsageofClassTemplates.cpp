#include <iostream>
#include <string>

// You can still define/compile a template class with a type that doesnt support the operators that are used in the class
// But you will get a compile error if you call the function that uses the operators with a type that doesnt support them
// Note there are complicated ways using type traits and SFINAE pre c++17 and you can use concepts to solve this

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
	// We can create a template class with const char* type that wont work with += and it will compile
	Klass<const char*> kCharP("2");

	// But if we call the fcniton that uses the += operator then it wont compile
	// We will get a very hard to read error (use concepts to get around this)
	//std::cout << kCharP.Add("4") << std::endl;

	Klass<int> kInt(3);
	std::cout << kInt.Add(4) << std::endl; // Will compile fine becuase += works with int
}