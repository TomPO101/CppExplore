#include <array>

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
struct Helper;

// implementation if SZ is not a prime number:
template<int SZ>
struct Helper<SZ, false>
{
};

// implementation if SZ is a prime number:
template<int SZ>
struct Helper<SZ, true>
{
};

template<typename T, unsigned int SZ>
void foo(std::array<T, SZ> const& coll)
{
	Helper<SZ> h; // implementation depends on whether array has prime number as size
}

int main()
{
	foo<int, 2>({1, 2});

    return 0;
}