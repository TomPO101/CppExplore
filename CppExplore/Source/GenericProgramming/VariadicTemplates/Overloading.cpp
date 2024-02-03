#include <iostream>

// You can overload non variadic and variadic template functions
// This function without the variadic pack takes presidence
template<typename T>
void Print(T firstArg)
{
	std::cout << firstArg << std::endl;
}

template<typename T, typename... Types>
void Print(T firstArg, Types... args)
{
	// THis calls the overloaded non variadic template function
	Print(firstArg);
	// This calls the this variadic fucntion again with the next arg in the pack
	Print(args...);
}

int main()
{
	Print(2, "hello");
}