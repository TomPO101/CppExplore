#include <vector>

template<typename T>
class Stack
{
public:
	void push(const T& elem) {
		elems.push_back(elem);
	}

	void pop()
	{
		elems.pop_back();
	}

	static T StaticFn(const T a) { return a; }

	const T& top() const
	{
		return elems.back();
	}

private:
	std::vector<T> elems;
};

int main()
{
	Stack<int> intStack;
	//Stack<double> doubleStack;

	intStack.push(2.9);

	return 0;
}