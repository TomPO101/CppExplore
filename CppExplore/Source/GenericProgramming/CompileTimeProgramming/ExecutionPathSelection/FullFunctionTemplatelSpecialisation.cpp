// Method 2 
// Full function template specialisation

constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d <= p / 2; ++d) {
        if (p % d == 0) {
            return false;
        }
    }
    return p > 1;
}

template <bool isPrime = isPrime(4)>
constexpr const char* Do();

template <>
constexpr const char* Do<true>()
{
    return "Is Prime, so do this...";
}

template <>
constexpr const char* Do<false>()
{
    return "Is not Prime, so do this...";
}

int main()
{
    // This is fully evaluated at compile time
    // and res will just hold the value
    constexpr auto res = Do();
}