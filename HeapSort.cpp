#include "HeapSort.hpp"
#include "Statistics.hpp"
#include <iostream>

HeapSort::HeapSort(std::vector<int> dataStorage)
	:dataStorage(dataStorage), timer("HeapSort")
{
}

void HeapSort::sort()
{
	{
		Timer timerheap; //timer for the heap sort
		timerheap.start(); //start of the timer
		int arr[500000];
		int *b = &arr[0];
		int size = dataStorage.size();
		for (int i = 0; i != NULL; i++)
		{
			arr[i] = dataStorage.at(i);
		}
		for (int h = size / 2; h >= 0; h--)
		{
			shift(b, h, size);
		}

		while (size - 1 > 0)
		{
			swap(&arr[size - 1], &arr[0]); //swaps root with the last element of the heap
			shift(b, 0, size - 1); //matains max-order
			size--; //used to keep max vaule in place
		}
		timerheap.stop(); //stops the timer
	}
}
	std:: string HeapSort::getElapsedTime()
	{
		return Statistics::convertTime(timer.getElapsedTime());
	}
	


void HeapSort::swap(int *m, int *n)
{
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
}

void HeapSort::shift(int arr[], int i, int S)
{
	while ((i * 2 + 1) < S)
	{
		int child = 2 * i + 1;

		//if two children are involved.
		if ((child + 1 < S) && (arr[child] < arr[child + 1]))
			child++;
		if (arr[i] < arr[child])
		{
			swap(&arr[child], &arr[i]);
			i = child;
		}

		else
			return;
	}
}




