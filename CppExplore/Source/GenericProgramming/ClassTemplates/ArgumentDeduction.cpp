#include <vector>
#include <string>

template<typename T>
class Klass
{
public:
	Klass(const T& cont_) : cont{cont_} {}

private:
	T cont;
};

Klass(char const*)->Klass<std::string>;

int main()
{
	// Since c++17 you dont have to explicitly define the template argument list	
	// All the parameters must be known by the comiler unlike function templates
	
	// kls1 will deduce to Klass<int>
	Klass kls1(0);

	// Problems with raw strings
	// 
	// Becuase the constructor is reference the passed const char[6] will not decay to a pointer
	// So will deduce to Klass<const char[6]> and wont compile becuase you cant do std:::vector<const char[6]>
	//
	// If you change the constructor to be by value the array can decay to a pointer
	// and will compile becuase you can have a std::vector<const char*>
	//
	// To prevent having to make the constructor pass by value it is recomennded to use a 
	// Deduction Guide in the same namespace like above Klass(char const*)->Klass<std::string>;
	// This will now deduce to Klass<std::string>

	Klass kls2("hello");
}