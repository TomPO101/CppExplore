#include <utility>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

template<typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const& ... args)
{
    while (current != end)
    {
        // Invoke doesnt perfectly forward as that might steal the data
        std::invoke(op, // Call passed callable with
            args..., // Any additional args
            *current); // Passed prime value

        ++current;
    }
}

// a class with a member function that shall be called
class MyClass
{
public:
    void memfunc(int i) const
    {
        std::cout << "MyClass::memfunc() called for: " << i << "\n";
    }
};

int main()
{
    std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

    // Pass lambda as callable and an additional argument:
    foreach(primes.begin(), primes.end(), // elements for 2nd arg of lambda
        [](std::string const& prefix, int i) {  // lambda to call

            std::cout << prefix << i << "\n";
        },
        "- value:"); // 1st arg of lambda


    // Call obj.memfunc() for/with each elements in primes passed as argument
    MyClass obj;
    foreach(primes.begin(), primes.end(), // Elements used as args
        &MyClass::memfunc, // Member function to call
        obj); // Object to call memfunc() for
}