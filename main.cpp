#include <iostream>

#include "priorityQueue.hpp"

int main()
{
	PriorityQueue<int> test;
	test.insert(7);
	test.insert(5);
	test.insert(9);
	test.insert(2);
	test.insert(1);
	test.insert(12);
	test.insert(8);


	while (!test.isEmpty())
	{
		std::cout << test.getMin() << std::endl;
	}
	
	return 0;
}