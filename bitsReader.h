#ifndef BITS_READER_HEADER
#define BITS_READER_HEADER

#include "binaryFileReader.h"

class BitsReader
{
	short bitPos;
public:
	BitsReader() : bitPos(0) {}

	virtual void extractDictionary(BinaryFileReader& in) = 0;
	virtual void generateFile(BinaryFileReader& in, char* fileName) = 0;

public:
	void nextByte(BinaryFileReader& in);
	bool singleBit(BinaryFileReader& in);
	int readNumber(BinaryFileReader& in, int bitsNumber);
	char readChar(BinaryFileReader& in);
	char* readString(BinaryFileReader& in, int size);
	void endOfBit(BinaryFileReader& in);

};

#endif//BITS_READER_HEADER