
template<typename Derived>
class Base
{
public:
	void func()
	{
		static_cast<Derived*>(this)->func();
	}	
};

class DerivedClass : public Base<DerivedClass>
{
public:
	void func()
	{
		// Do something
	}
};

int main()
{
	DerivedClass d1;
	Base<DerivedClass>* base = &d1;

	// Calls the base function first that then calls the derived
	base->func();
}