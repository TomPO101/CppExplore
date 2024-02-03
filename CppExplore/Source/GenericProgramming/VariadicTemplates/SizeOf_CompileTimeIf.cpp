#include <iostream>

// We would like to avoid this anoyying empty function
// You can do using sizeof...(args) and compile time if
void Print()
{
}

template<typename T, typename... Types>
void Print(T firstArg, Types... args)
{
	// You can call sizeof… for both template parameter packs and function parameter packs.
	// Both will print the number of remaining arguments
	std::cout << sizeof...(Types) << std::endl; // Prints 3
	std::cout << sizeof...(args) << std::endl; // Prints 3

	std::cout << firstArg << std::endl;

	// You might think we could avoid having to define that empty Print function
	// by checking if the pack is empty and not instanciating Print(args...)
	// Whether the instantiated code is useful is a run-time decision,
	// The instructions to call the Print<>() are still in the binary 
	// So Print<>() is still instanciated at compile time
	// regardless of whether the code is executed at runtime due to the if
	if (sizeof...(args) > 0)
	{
		Print(args...);
	}

	// You can use this using compile time if
	// Where firstArg is "world" and the function parameter pack is now empty
	// The instruction inside the if will not be included in the binary 
	// so at compile time it wont instansiate Print<>()
	if constexpr (sizeof...(args) > 0)
	{
		Print(args...);   // Code only available if sizeof…(args)>0 (since C++17) 
	}
}

int main()
{
	Print(7, std::string("hi"), std::string("hello"), "world");
}