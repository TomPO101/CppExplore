#include <vector>

template<typename T, typename cont>
class Stack1
{
	void Push(const T& val)
	{
		container.push_back(val);
	}
	cont container;
};

template<typename T, template<typename> typename cont>
class Stack2
{
private:
	void Push(const T& val)
	{
		container.push_back(val);
	}
	cont<T> container;
};

int main()
{
	// We must pass the type (int) twice here
	const auto s1 = Stack1<int, std::vector<int>>();

	// You can get around this by using a template template parameter
	// 
	// you can just pass a std::vector here without a specfic type 
	// because its not creating an instance here so it doenst need it.
	// The instance is created in the Stack2
	const auto s2 = Stack2<int, std::vector>();
}