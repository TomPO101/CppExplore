
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
	DerivedClass obj;
	obj.func();
	return 0;
}