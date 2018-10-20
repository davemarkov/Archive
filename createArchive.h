#ifndef CREATE_ARCHIVE_HEADER
#define CREATE_ARCHIVE_HEADER

#include "analysis.h"
#include "writeToBinary.h"

class Archive : public Analysis
{
public:
	Archive(char* fileName) : Analysis(fileName) {}

public:
	//void archiveData(std::fstream& file, Byte)
	void archiveFile(char* fileName);
};

#endif//CREATE_ARCHIVE_HEADER