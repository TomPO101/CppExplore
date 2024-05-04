// Compile time branch/execution path selection
// Method 1
// Partialy specialised classes with static members/funtions

constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d <= p / 2; ++d) {
        if (p % d == 0) {
            return false;  // found divisor without remainder
        }
    }
    return p > 1;
}

template<int SZ, bool = isPrime(SZ)>
struct Helper
{
    static constexpr const char* Do();
};    

template<int SZ>
struct Helper<SZ, true>
{
    static constexpr const char* Do()
    {
        return "Is Prime, so do this...";
    }
};

template<int SZ>
struct Helper<SZ, false>
{
    static constexpr const char* Do()
    {
        return "Is not Prime, so do this...";
    }
};

int main()
{       
    // At compile time this first processes the defualt Helper becuase
    // It has two template arguments but one of those has a defualt value (the isPrime() func)
    // So is the only match for the Helper<2>::IsPrime to call
    // Then it must look for any matching partial specialisations available that match the return value of isPrime
    // It will then instanciate that at compile time instead of the default
    // At runtime res is just the result of whatever Do funciton is a called
    // So completely processed at compile time and no instanciation is made at run time
    constexpr auto res = Helper<4>::Do();

    return 0;
}