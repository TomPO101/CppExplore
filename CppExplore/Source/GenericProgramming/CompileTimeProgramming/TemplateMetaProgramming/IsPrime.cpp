#include <iostream>

// p: number to check, d: current divisor
template<unsigned p, unsigned d> 
struct DoIsPrime
{
	constexpr static bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};

// This is a partial specialisation struct
// to end the recursion if the divisor is 2
// Note it ends it by value not instacniting another DoIsPrime
template<unsigned p>
struct DoIsPrime<p, 2>
{
	constexpr static bool value = (p % 2 != 0);
};

template<unsigned p> // primary template
struct IsPrime
{
	// start recursion with divisor from p/2:
	constexpr static bool value = DoIsPrime<p, p / 2>::value;
};

// Full specialitaion (to avoid endless recursion with template instantiation):
template<>
struct IsPrime<0> { 
	constexpr static bool value = false;
};

template<>
struct IsPrime<1> { 
	constexpr static bool value = false;
};

template<>
struct IsPrime<2> { 
	constexpr static bool value = true;
};

template<>
struct IsPrime<3> { 
	constexpr static bool value = true;
};

int main()
{
	// An instance of IsPrime<11> instanciated
	// and the static variable value is referenced 
	// Making the compiler initialsies it
	IsPrime<9>::value;

	// Recursion flow id
	// IsPrime<9>::value
	// DoIsPrime<9,4>::value
	// 9%4!=0 && DoIsPrime<9,3>::value
	// 9%4!=0 && 9%3!=0 && DoIsPrime<9,2>::value
	// 9%4!=0 && 9%3!=0 && 9%2!=0.

	// Interesting note if you remove the constexpr on the values and replace with constexpr
	// (only needed to get around the one definition rule)
	// Then the static values are inited before main starts as usual
	// You can put a break point on the value and it shows the instrusitions to start the recursion
	// So it is evaluated at run time
	// So basicly the constexpr is needed for it to be evalutaed at compile time

	return 0;
}