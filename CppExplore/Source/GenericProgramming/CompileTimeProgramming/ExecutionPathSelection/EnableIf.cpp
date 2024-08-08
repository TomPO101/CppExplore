#include <type_traits>

// This is similar to the full function specliation 
// but is probably worse performace as isPrime is probably called twice
// Benefit is that you dont need to specify the defualt version of isPrime

// Note that each use of enable_if's template arguments must be different 
// E.g declaring std::enable_if<isPrime(N), bool> for each function when isPrime() returns the same result for each would result in a compile error
// So you could have one with the not operator std::enable_if<!isPrime(N), bool> so the result would be diffrernt


constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d <= p / 2; ++d)
    {
        if (p % d == 0)
        {
            return false;
        }
    }
    return p > 1;
}

template<unsigned int N, typename std::enable_if<isPrime(N), bool>::type = true>
constexpr const char* Do()
{
    return "Is Prime, so do this...";
}

template<unsigned int N, typename std::enable_if<!isPrime(N), bool>::type = true>
constexpr const char* Do()
{
    return "Is not Prime, so do this...";
}

int main()
{
    constexpr auto res = Do<2>();
    return 0;
}
