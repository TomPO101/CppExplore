#include <iostream>



template<typename... T>
auto FoldSum(T... val)
{
	// You can define a fold expression to the entire parameter pack
	// You can apply any binary operator
	//
	// Note this doesnt call this function recusivly
	// it just adds every element using seperate instructions
	return (... + val); // (5 + 5 + 5 + 5.5)
}

int main()
{
	// Equavilant of FoldSum<int, int, int, double>
	const auto res = FoldSum(5, 5, 5, 5);
	std::cout << res << std::endl;
}