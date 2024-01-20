#pragma optimize("", off)

#include <optional>
#include <vector>
#include <ranges>

namespace {
	const std::vector<int> vec{ 1, 2, 3, 4 };
}

[[nodiscard]]
inline const std::optional<size_t>&
GetIndexByValue(const int value) noexcept
{
	const auto it = std::ranges::find(vec, value);
	if (it != vec.end())
	{
		return std::distance(it, vec.end());
	}
	return std::nullopt;
}

int main()
{
	auto i = GetIndexByValue(3);
	*i = 4;
}
