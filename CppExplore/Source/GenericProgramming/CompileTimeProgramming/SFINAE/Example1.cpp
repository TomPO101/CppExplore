#include <vector>

// number of elements in a raw array:
template<typename T, unsigned N>
std::size_t len(T(&)[N])
{
	return N;
}

// number of elements for a type having size_type:
template<typename T>
typename T::size_type len(T const& t)
{
	return t.size();
}

// fallback for all other types:
std::size_t len(...)
{
	return 0;
}

int main()
{
	// Both call to len below will be sucessfully substitited to len(T(&)[N])
	// They could be sucessfully substitited to len(T const& t) but there would be problems with the return type
	// So substitution fails
	// But becuase of SFINAE this is not counted as an error it is just ignored
	const int a[10]{};
	const auto res1 = len(a);
	const auto res2 = len("tmp");

	// THis will be sucessfully substitited to len(T const& t)
	const auto res3 = len(std::vector<int>{});

	// The compiler will not be able to subsitute the int pointer to any len overload 
	// So will throw an compile error
	// but becuase we have the general len fucniton with the elipsis paramter
	// It will use that and compile
	int* i{};
	const auto res4 = len(i);
}