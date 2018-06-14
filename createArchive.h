#ifndef CREATE_ARCHIVE_HEADER
#define CREATE_ARCHIVE_HEADER

#include "analysis.h"
#include "bitsContainer.h"
#include "dictionary.h"

class Archive : public Analysis
{
	BitsContainer bitsContainer;

public:
	Archive(char* fileName) : Analysis(fileName) {}

public:
	//void archiveData(std::fstream& file, Byte)
	void archiveFile(char* fileName);
};

#endif//CREATE_ARCHIVE_HEADER