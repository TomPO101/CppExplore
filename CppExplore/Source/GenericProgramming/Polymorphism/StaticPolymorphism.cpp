#include <iostream>

// Becuase you cant have a base interface with virtual fucnitons
// You can use a concpet instead as an interface to denote what fucnitons are expected to be used in the shape classes
// This will give you something to program against (an obvoise guide) and also the compiler will give better error messages
// If the client calls fucntions that arnt in the shape classes
template<typename T>
concept IShape = requires(T shape) {
	{ shape.Draw() };
};

class Line
{
public:
	void Draw()
	{
		std::cout << "Drawing Line" << std::endl;
	}
};

class Circle
{
public:
	void Draw()
	{
		std::cout << "Drawing Circle" << std::endl;
	}
};

template<typename Shape>
requires IShape<Shape> // Require the IShape concept to give better error messages
void DrawShape(Shape shape)
{
	shape.Draw();
}

int main()
{
	// an instace of DrawShape is instantaited for each Shape type at compile time
	// this is the static polymorphism part of this

	DrawShape(Line{});
	DrawShape(Circle{});

	// Hetrogenous containers are not possible
	// becuase tehre is no base class and virtual fucntions
}