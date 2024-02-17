#include <vector>
#include <string>
#include <iostream>

template<typename T, typename... Pack>
void Print(const T& var, const Pack&... pack)
{
	std::cout << var << std::endl;
	if constexpr (sizeof...(pack) > 0)
	{
		Print(pack...);
	}	
}

template<typename Cont, typename... Pack>
void PrintElements(const Cont& container, const Pack&... indexs)
{
	// The affect here is Print<string, string, string> is called once
	// The string [] operator is called for each index and pushed to the stack for Print
	Print(container[indexs]...);
}

int main()
{
	std::vector<std::string> vec{"hello ", "World ", "tree"};
	PrintElements(vec, 0, 2, 1);
}