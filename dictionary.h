#ifndef DICTIONARY_HEADER
#define DICTIONARY_HEADER

#include "data.h"

const int MAX_SIZE = 256;

class Dictionary
{
	Data** table;
	
public:
	Dictionary() : table(nullptr) {}

private:
	void create();
	int getIndex(Data& precess);

public:
	void insert(Data*& toInsert);
	Data* search(char byte);
	
};

#endif//DICTIONARY_HEADER
