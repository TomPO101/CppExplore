
// Because in C++11 a constexpr funtion can only consist of a return statment
// we still have to use recursion

constexpr bool DoIsPrime(unsigned p, unsigned d)  // p: number to check, d: current divisor
{
    return d != 2 ? (p % d != 0) && DoIsPrime(p, d - 1) // check this and smaller divisors
        : (p % 2 != 0); // end recursion if divisor is 2
}

constexpr bool IsPrime(unsigned p)
{
    return p < 4 ? !(p < 2) // handle special cases
        : DoIsPrime(p, p / 2); // start recursion with divisor from p/2
}

int main()
{
    // Note if this is not constexpr it will call the fucntion at runtime
    constexpr auto res = IsPrime(11);
}