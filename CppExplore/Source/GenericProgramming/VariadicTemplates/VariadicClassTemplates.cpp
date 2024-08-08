#include <array>
#include <string>
#include <iostream>

template<std::size_t...>
struct Indexs
{
};

template<typename T, typename... Pack>
void Print(const T& var, const Pack&... pack)
{
	std::cout << var << std::endl;
	if constexpr (sizeof...(pack) > 0)
	{
		Print(pack...);
	}
}

template<typename Cont, std::size_t... indexs>
void PrintElements(const Cont& container, Indexs<indexs...>)
{	
	// This calls std::get for each index in Indexs
	// and pushes container for each get
	// std::get<0, string>
	// std::get<1, string>
	// 
	// Calls Print<string, string>()
	Print(std::get<indexs>(container)...);
}

int main()
{
	std::array<std::string, 2> arr{ "Hello", "World" };

	// I supose one benefit of this over the prevoise exmplaes of paramater packs is
	// you can store the values of the pack in a struct variable instance
	const Indexs<0, 1> indexs;

	// Equals to PrintElements<array, 0, 1>
	PrintElements(arr, indexs);
}