
template<typename T>
class Base
{
protected:
	void Fn()
	{
	}
};

template<typename T>
class Foo : public Base<T>
{
public:
	Foo()
	{
		// This wont compile becuase base class functions are never considered
		// Fn would need to be in this class or a global function
		Fn();

		// You need to use the this pointer too access base classes
		this->Fn();
		
		// Or access Fn through the scope resolution operator and the Base type 
		Base<T>::Fn();
	}
};

void main()
{
	Foo<int> f1;
}