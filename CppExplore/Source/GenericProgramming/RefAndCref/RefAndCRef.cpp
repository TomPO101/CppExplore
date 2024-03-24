// The difference between std::cref and std::ref is that cref is for const 


#include <functional>
#include <string>
#include <iostream>

void Print(const std::string& str)
{
	std::cout << str << std::endl;
}

template<typename T>
void PrintT(T x)
{
	// x is a reference_wrapper instance
	// 
	// This calls the overloaded () operator in reference_wrapper
	// Which returns the std::string* managed by the reference_wrapper by reference
	// Which is then passed to Print
	Print(x);
}

int main()
{
	std::string str{ "hello" };

	PrintT(std::cref(str));

	return 0;
}