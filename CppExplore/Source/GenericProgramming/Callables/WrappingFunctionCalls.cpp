#include <utility>
#include <functional> 

// Commonly invoke can be wrapped in a template fucntion to allow for more control
// In this case we can auto enable move semantic and use perfect forwarding

template<typename Callable, typename... Args>
// decltype(auto) has to be used here to perfectly forward the return type, e.g a int& or int&&
// You cant just use auto like invoke returns, becuase naked auto doent support implicit references, just pointers
decltype(auto) call(Callable&& op, Args&& ... args)
{
    // We must detect whether the return type of the callable is void
    // If it is we cant use decltype(auto) because viod is a in complete type
    if constexpr (std::is_same_v<std::invoke_result_t<Callable, Args...>, void>)
    {
        // The type is void
        std::invoke(std::forward<Callable>(op), // passed callable with
            std::forward<Args>(args)...); // any additional args

        // because the callables return type is void we can just return;
        return;
    }
    else 
    {
        // To store the value correctly we must still use decltype(auto) to retain the reference return type if it is a reference
        decltype(auto) res = std::invoke(std::forward<Callable>(op), // passed callable with
            std::forward<Args>(args)...); // any additional args

        // Do something with res the return

        return res;
    }
}

int main()
{
    int i = 4;
    const int& ret = call([](int& i) -> int& { return i; }, i);

    // call with void return type
    call([](int& i) -> void { }, i);
}