#include <vector>
#include <iostream>
#include <string>

#include "FileInput.hpp"
#include "Timer.hpp"
#include "HeapSort.hpp"

std::string obtainFilePath();

int main()
{
	FileInput file(obtainFilePath(), 500000ul); // Create a new FileInput object to get data from a file.

	/* Store the data found in the dataStorage vector. Use this when calling your sorting algorithms.
	Copy it inside the constructor to a local class member. AKA: Don't modify this one, everyone will need it.
	*/
	const std::vector<int> dataStorage = file.toVector();

	std::cout << "\n"; // Formatting for output.

	HeapSort heap(dataStorage);
	heap.sort(); 
	std::cout << "Heap sort took " << heap.getElapsedTime() << std::endl; //ths line keeps resutling in a stack overflow. 


	return 0;
}

std::string obtainFilePath()
{
	std::string path;
	std::cout << "Enter the path at which the data file is located:" << std::endl;
	std::getline(std::cin, path);
	return path;
}
