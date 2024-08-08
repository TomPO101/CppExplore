#include "Library.h"

int main()
{
	const double i = 4.67;
	// This will compile but
	/*
	The reason for this error is that the definition of the function template printTypeof() has not been instantiated. 
	In order for a template to be instantiated, the compiler must know which definition should be instantiated 
	and for what template arguments it should be instantiated. in this example,
	these two pieces of information are in files that are compiled separately. Therefore, 
	when our compiler sees the call to func() but has no definition in sight to instantiate this function for double,
	it just assumes that such a definition is provided elsewhere and creates a reference (for the linker to resolve) to that definition.
	On the other hand, when the compiler processes the file Library.cpp,
	it has no indication at that point that it must instantiate the template definition it contains for specific arguments.
	*/
	func(i);
}