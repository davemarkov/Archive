#include <iostream>
#include "dictionary.h"

void Dictionary::create()
{
	table = new Data*[MAX_SIZE];
}

int Dictionary::getIndex(Data& process)
{
	return (int)process.elem;
}

void Dictionary::insert(Data*& toInsert)
{
	table[getIndex(*toInsert)] = toInsert;
}

Data* Dictionary::search(char byte)
{
	return table[(int)byte];
}