#include <concepts>

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

template<unsigned int N> requires (isPrime(N))
constexpr const char* Do()
{
    return "Is Prime, so do this...";
}

template<unsigned int N> requires (!isPrime(N))
constexpr const char* Do()
{
    return "Is not Prime, so do this...";
}

int main()
{
    constexpr auto res = Do<2>();
    return 0;
}
