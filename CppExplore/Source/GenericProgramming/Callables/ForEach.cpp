#include <iostream>
#include <vector>

template<typename Iter, typename Callable>
void foreach(Iter current, Iter end, Callable op)
{
    while (current != end)
    {
        op(*current);
        ++current;
    }
}

// a function to call:
void func(int i)
{
    std::cout << "func() called for:  " << i << std::endl;
}

// a function object type (for objects that can be used as functions):
class FuncObj
{
public:
    void operator() (int i) const
    {   //Note: const member function
        std::cout << "FuncObj::op() called for:      " << i << std::endl;
    }
};

int main()
{
    std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

    // Function as callable 
    // func decays to a pointer with the type void (__cdecl*)(int) becuase the parameter is by value
    // This also happens if you pass as a template argument, foreach<iter, func>
    // Foreach<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int> > >,void (__cdecl*)(int)>
    foreach(primes.begin(), primes.end(), func);

    // Function pointer as callable
    // Explicity pass a pointer of type void (__cdecl*)(int) to the function by using teh address of operator
    // foreach<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int> > >,void (__cdecl*)(int)>
    foreach(primes.begin(), primes.end(), &func);

    // Function object as callable (functor)
    // FuncObj::operator() gets called in the template fucniton
    // foreach<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int> > >,FuncObj>
    foreach(primes.begin(), primes.end(), FuncObj()); 

    // Lambda as callable
    // Lambda expressions produce functors (called closures), 
    // and therefore this case is not different from the functor case.
    // Lambdas are a more modern/shorthand syntax way of creating function callables compared to functors
    // `main'::`2'::<lambda_1>
    // foreach<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int> > >,`main'::`2'::<lambda_1> > 
    foreach(primes.begin(), primes.end(),
        [](int i) {                         
            std::cout << "lambda called for:      " << i << std::endl;
        });
}