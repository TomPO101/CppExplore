#include <functional>

template<typename T>
void Fn(T x)
{
}

int main()
{
	int i = 5;
	Fn(std::ref(i));
	return 0;
}