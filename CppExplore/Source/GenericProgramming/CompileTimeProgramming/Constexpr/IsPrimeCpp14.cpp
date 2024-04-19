
// In C++14 we can now use for loops so can avoid the recursion

constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d <= p / 2; ++d)
    {
        if (p % d == 0)
        {
            return false; // found divisor without remainder
        }
    }
    return p > 1; // no divisor without remainder found
}

bool ElevenIsPrime()
{
    return isPrime(11);
}

int main()
{
    unsigned int i = 11;
    //constexpr auto res = isPrime(i); // Compile error: Will not compile in VS becuase it is not const or constepr

    // Compile error: You cant call a contexpr function inside a normal function at compile time
    //constexpr auto res1 = ElevenIsPrime();

    // You can a runtime
    auto res2 = ElevenIsPrime();
}