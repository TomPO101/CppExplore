#include <iostream>
#include <span>
#include <vector>

class IShape
{
public:
	virtual void draw() const = 0;
};

class Line final : public IShape
{
	void draw() const final
	{
		std::cout << "Drawing Line" << std::endl;
	}
};

class Circle final : public IShape
{
	void draw() const final
	{
		std::cout << "Drawing Circle" << std::endl;
	}
};

void DrawShape(std::span<IShape*> shapes)
{
	for (const auto& shape : shapes)
	{
		// Will use the virtual dynamic dispatch mechanism to invoke the draw fucntion of the most derived class
		shape->draw();
	}	
}

int main()
{
	// Hetrogrneois containers allowed
	std::vector<IShape*> shapes{ new Line, new Circle };

	DrawShape(shapes);
}