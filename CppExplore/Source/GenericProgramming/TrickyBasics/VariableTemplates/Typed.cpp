#include <iostream>

// Variable templates have to be defined in the global namespace
template<typename T = short>
T PI = 255;

int main()
{
	// Here the two instances of PI are similar to static variables as they have the life time of the program
	// and are stored in the static data section of the binary
	// They also dont have the scope this function becuase they are global
	//
	// I supose the main benefit of this is that these can be used in different transaltion units
	// becuase they are global
	// So if you were to refefnce PI<long> in another cpp file it would print 23
	PI<long> = 23;
	PI<int> = 3;

	// If we change PI<long> here it will be reflected through out the app as its just a static global varaible
	PI<long> = 4;

	// This creates a local variable with the value of PI as its default type (short)
	const auto pi = PI<>;

	// This is invalid syntax and wont compile
	// constexptr auto pi = PI; // Must have <>
	// constexpr PI<> pi1; // This just isnt valid syntax

	// Instance local variable with value of pi
	int pi1 = PI<int>;
	// You can change the value of the local variable as usual
	pi1 = 33;

	return 0;
}