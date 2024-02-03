#include <iostream>

// This needs to be declared becuase 
// when the parameter pack is empty the template Print function
// Needs to call a Print function with no paramters
// If this wasnt here it wouldnt compile becuase Print() wouldnt exist
void Print()
{
}

template<typename T, typename... Types>
void Print(T firstArg, Types... args)
{
	// firstArg is always the first argument in the template parameter pack
	// 1st call: int, 2nd call: std::string, 3rd call: const char*
	std::cout << firstArg << std::endl;
	
	// Print is called recursivly for every param in the function parameter pack 
	// Each time is called a paramter is processed then removed

	Print(args...);

	// Call progression is as follows
	// A Print<std::string, const char*> template function is instanciated
	// A Print<const char*> template function is instanciated
	// Print() a normal function is called
}

int main()
{		
	// Instantiates a template function of 
	// Print<int, std::string, const char*>
	Print(7, std::string("hi"), "hello");	
}