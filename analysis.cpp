#include <iostream>
#include "analysis.h"

// read original file and insert bytes in binary tree to count them
void Analysis::analyseText(char* fileName)
{
	// extracts chunks of data from daq file into memory for faster reading 
	BinaryFileReader fileReader(fileName);

	while (!fileReader.isEOF())
	{
		char toAdd = fileReader.get();
		tree.add(toAdd);
		++fileReader;
		++dictionaryLength;
	}
}

void Analysis::sortByCnt()
{
	// insert the already counted elems from the binary tree
	// into a priority queue, with the key being the count of each elem 
	BinaryTree<char>::BinaryTreeIterator iter = tree.begin();

	Data* temp = new Data;
	temp->cnt = iter->cnt;
	temp->elem = iter->key;
	queue.insert(temp);

	while (!iter.endOfIterator())
	{
		Data* toInsert = new Data;
		toInsert->cnt = iter->cnt;
		toInsert->elem = iter->key;
		queue.insert(toInsert);
	}
}

