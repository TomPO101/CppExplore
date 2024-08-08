#include <array>
#include <iostream>

template<int N>
std::array<int, N> arr{};

// A none type template variable 
// that can be any type 
template<auto N>
constexpr decltype(N) val{ N };

int main()
{
	// Create an instance of the global template variable array with 10 elements
	// the instance is only created the first time arr<10> is used
	for (int i = 0; i < arr<10>.size(); ++i)
	{
		arr<10>[i] += i;
		std::cout << arr<10>[i] << std::endl;
	}

	// Create an instance of type char with the value t
	std::cout << val<'t'> << std::endl;
}