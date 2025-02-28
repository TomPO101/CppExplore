#include <ranges>


int main()
{
	template<std::ranges::random_access_range R, typename Comp = std::ranges::less>
		requires std::sortable<std::ranges::iterator_t<R>, Comp>
	... sort(R && r, Comp comp = {});

	return 0;
}

