#include <type_traits>

class Klass
{
public:

	// Needed to create the passed class
	Klass() = default;

	// Use enable if to Ensure that the type past is not of type Klass
	// This ensures that the copy confnstructor is called
	//
	// Note that std::decay_t<T> is used to remove all references and constness to make the type be as plain as possible
	// to ensure that the check is as valid as possible
	template<typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, Klass>>>
	Klass(T arg)
	{
		// normal construct
	}

	template<typename T>
	Klass(const Klass& rhs)
	{
		// copy construct
	}
};

int main()
{
	// In the overload subistution stage both fucntions will be sucesuly substitued
	// Then at the overload resolution stage becuase the enable if will fail
	// The copy construcotr will used as the resolution fucniton
	auto kls = Klass(Klass{});
}