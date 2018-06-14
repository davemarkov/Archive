#ifndef ANALYSIS_HEADER
#define ANALYSIS_HEADER

#include "huffman.h"


class Analysis : public Compression
{
protected:
	int dictionaryLength;
		
public:
	Analysis(char* fileName) : dictionaryLength(0)
	{
		analyseText(fileName);
	}

	
protected:
	void analyseText(char* fileName);
	void sortByCnt();

protected:
	
	


};

#endif//ANALYSIS_HEADER