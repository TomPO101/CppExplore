#include <memory>

// Make sure len is ignored when arguments of a type that has a size_type member but not a size() member function.
// decltype(condition1, condition2, desired return value)
template<typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
	return t.size();
}

void len(...)
{
	// fall back
}

int main()
{
	// Will fall back to len(...)
	std::allocator<int> x;
	len(x);
}