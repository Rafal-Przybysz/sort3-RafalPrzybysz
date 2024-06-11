#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"
#include "../SortLib/ShellSort.h"
#include "../SortLib/CountingSort.h"
#include "../SortLib/QuickSortNoRecursion.h"

int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<size_t> s = { 5000, 10000,15000, 20000, 30000, 40000, 50000, 60000, 80000, 100000 };
	for (auto n : s)
	{
		std::vector<unsigned int> v;

		// wygenerowanie losowej zawartoœci kolekcji
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
			v.push_back(generator() /*% 1000*/);

		Benchmark<std::chrono::nanoseconds> b;
		//shellSort(v.begin(), v.end());
		//std::sort(v.begin(), v.end());
		//quickSort(v.begin(), v.end());
		//countingSort(v.begin(), v.end(), 1000);
		//insertionSort(v.begin(), v.end()/*, 1000U*/);
		quickSortNoRecursion(v.begin(), v.end());
		auto t = b.elapsed();

		std::cout << t << std::endl;
	}
}
