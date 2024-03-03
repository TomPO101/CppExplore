#include <string>

template<typename T>
class Klass
{
public:
	static constexpr int max = 1000;
};

template<typename T>
auto max = Klass<T>::max;

int main()
{
	max<std::string>;
}