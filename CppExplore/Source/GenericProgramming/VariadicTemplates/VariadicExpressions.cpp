
template<typename T, typename... Pack>
constexpr bool IsHomogeneous(T, Pack...)
{
	// Using the && logical and operator on the entire parameter pack
	// 
	// The result of the variadic expression is computed at compile time
    // Becuase it only involves types known at compile time
	// In disassembly this stores the result in al register
	return (std::is_same<T, Pack>::value && ...);
}

int main()
{
	// THis is called even though the function can be processed at compile time
	// Res is assigned the al register
	auto res{ IsHomogeneous("hello", 3) };

	// Everything is computed at compile time and IsHomogeneous is not called
	// res is just equal to 0 or 1 
	constexpr auto res{ IsHomogeneous("hello", 3) };
}