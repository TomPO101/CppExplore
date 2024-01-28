#include <string_view>
#include <ranges>
#include <iostream>

int main()
{
	auto strings = std::string_view("hello my name is tom") | std::ranges::views::split(' ');
	for (const auto& string : strings)
	{
		std::cout << std::string_view(string) << std::endl;
	}

	return 0;
}