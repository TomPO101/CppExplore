#include <type_traits>

// The first parameter of enable if is a compile time expression
// If the expression evalutas to true then fucniton will be enabled for use
// and the return type of Func will be avaluatioed to the second paramter of enable if
// If evalutaes to false beause of SFINAE the fucntion template is ignored
// Syntax 1
template<typename T>
typename std::enable_if<(sizeof(T) >= 4), void>::type
Fn()
{
}

// Syntax 2
// Since C++14 you can use the _t version of the function
// Note you can also pass T as the second paramter (this works for all enable if)
template<typename T>
std::enable_if_t<(sizeof(T) >= 4), T>
Fn()
{
	return T{};
}

// Syntax 3
// You can add the enable if as a default template argument
// This way you cant use the second pararmer to deduce the return type
// So you have to explicity add like normal
template<typename T, typename = std::enable_if_t<(sizeof(T) >= 4)>>
void Fn()
{
}

// Syntax 4
// You can use an alias template if you dont want to repeat yourself
template<typename T>
using GreaterThan4 = std::enable_if_t<(sizeof(T) >= 4)>;

template<typename T, typename = GreaterThan4<T>>
void Fn()
{
}

int main()
{
	Fn<int>(); // This will compile becuase int has a size of 4
	Fn<char>(); // This will wont compile becuase char has a size of 1
}