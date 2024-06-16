#include <iostream>

template<typename T, typename... Types>
void print(T const& firstArg, Types const&... args)
{
    std::cout << firstArg << "\n";
    // Using constexpr if here prevents us from needing the create a compatable
    // print() function overload for when there is no elements in the pack
    //
    // This produces a "discarded statement" which is not intanciated
    // So only the first translation phase (the definition time) is performed,
    // which checks for correct syntax and names that don’t depend on template parameters
    // So therefore will still compile beause it doenst check the missingn argument
    if constexpr (sizeof...(args) > 0)
    {
        print(args...); 
    }
}

int main()
{
    print<int>(1, 2, 3, 4, 5);
}