#include <utility>

class X
{

};

void g(X& x)
{

}

void g(const X& x)
{

}

void g(X&& x)
{

}

void f(X& x)
{
	g(x);
}

void f(const X& x)
{
	g(x);
}

void f(X&& x)
{
	g(std::move(x));
}

int main()
{
	X x1;
	const X x2;

	f(x1);
	f(x2);
	f(X{});
	f(std::move(x1));
}