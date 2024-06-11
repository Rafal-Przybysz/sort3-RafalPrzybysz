#pragma once
#include <algorithm>
#include <vector>

template <typename Iterator>
Iterator partition2(Iterator const& first, Iterator const& last)
{
	auto middle = first + ((last - first) / 2);
	std::swap(*middle, *first);

	auto i = last - 1;
	for (Iterator j = last - 1; j > first; --j)
		if (*j > * first)
			std::swap(*j, *(i--));
	std::swap(*i, *first);
	return i;
}

template <typename Iterator>
void quickSortNoRecursion(Iterator first, Iterator last)
{
	std::vector< std::pair<Iterator,Iterator >> stack;
	if (first < last)
	{
		stack.push_back({ first, last });
		while (!stack.empty())
		{
			auto zakres = stack.back();
			auto from = std::get<0>(zakres);
			
			auto to = std::get<1>(zakres);

			stack.pop_back();

		
			while ((std::distance(from, to)) > 1)
			{
				auto pivot = partition2(from, to);
				
				if ((std::distance(first, pivot)) > (std::distance((pivot + 1), last)))
				{
					stack.push_back({ first,pivot });
					from = pivot + 1;
				}
				else
				{
					stack.push_back({ pivot + 1,to });
					to = pivot;
				}
			}
		}
	}
	
}

