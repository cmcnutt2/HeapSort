#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include <string>

#include "Timer.hpp"

class HeapSort
{
public:
	HeapSort(std::vector<int> dataStorage);
	void sort();
	void swap(int*, int*);
	void shift(int [], int, int);
	std::string getElapsedTime();

private:
	std::vector<int> dataStorage;
	Timer timer;
};

#endif
