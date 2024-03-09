/*
Perfectforwarding is to enable the the abilty to pass a r value refernce (T&&)
to another function that has the type T&&
*/

#include <utility>
#include <iostream>

class X
{
};

void g(X& x)
{
	std::cout << "g(X& x)\n";
}

void g(const X& x)
{
	std::cout << "g(const X& x)\n";
}

void g(X&& x)
{
	std::cout << "g(X&& x)\n";
}

void Forward(X& x)
{
	g(x);
}

void Forward(const X& x)
{
	g(x);
}

void Forward(X&& x)
{
	g(std::move(x));
}

// This function only works for X& and const X& Not X&& versions of g function
template<typename T>
void TemplateForward(T val)
{
	g(val);
}

// To get around this you can use perfectly forwarding
// This will instanciate a call for X&, const X& and X&& versions of g automaticly 
// This prevents you from having to overload PerfectForward function for all the types
//
// T&& here is not a r value reference
// It is a Forwrding Reference or a Universal Reference
// It can be bound to a X&, const X& and X&&
template<typename T>
void PerfectForward(T&& val)
{
	
	g(std::forward<T>(val));
}

int main()
{
	X x1;
	const X x2;

	Forward(x1); // g(X& x)
	Forward(x2); // g(const X& x)
	Forward(X{}); // g(X&& x)
	Forward(std::move(x1)); // g(X&& x)

	std::cout << "\n";

	TemplateForward(x1); // g(X& x)
	TemplateForward(x2); // g(X& x)
	TemplateForward(X{}); // g(X& x)
	TemplateForward(std::move(x1)); // g(X& x)

	std::cout << "\n";

	PerfectForward(x1); // g(X& x)
	PerfectForward(x2); // g(const X& x)
	PerfectForward(X{}); // g(X&& x)
	PerfectForward(std::move(x1)); // g(X&& x)
}