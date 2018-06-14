#include <iostream>
#include "bitsReader.h"

void BitsReader::nextByte(BinaryFileReader& in)
{
	++in;
	bitPos = 0;
}

bool BitsReader::singleBit(BinaryFileReader& in)
{
	bool result = false;
	short mask = 1 << (7 - bitPos);
	if (in.get() & mask)
		result = true;
	++bitPos;
	if (bitPos == 8)
	{
		nextByte(in);
		mask = 1 << (7 - bitPos);
	}
	return result;
}

int BitsReader::readNumber(BinaryFileReader& in, int bitsNumber)
{
	int result = 0;
	short mask = 1 << (7 - bitPos);
	for (int i = 0; i < bitsNumber; ++i)
	{
		result <<= 1;
		if (in.get() & mask)
			result ^= 1;
		++bitPos;
		if (bitPos == 8)
		{
			nextByte(in);
			mask = 1 << (7 - bitPos);
		}
		else
			mask >>= 1;
	}
	return result;
}

char BitsReader::readChar(BinaryFileReader& in)
{
	char result = '\0';
	short mask = 1 << (7 - bitPos);
	for (int i = 0; i < 8; ++i)
	{
		result <<= 1;
		if (in.get() & mask)
			result ^= 1;
		++bitPos;
		if (bitPos == 8)
		{
			nextByte(in);
			mask = 1 << (7 - bitPos);
		}
		else
			mask >>= 1;
	}
	return result;
}

char* BitsReader::readString(BinaryFileReader& in, int size)
{
	char* text = new char[size + 1];
	for (int i = 0; i < size; ++i)
		text[i] = readChar(in);
	text[size] = '\0';
	return text;
}

void BitsReader::endOfBit(BinaryFileReader& in)
{
	++in;
	bitPos = 0;
}