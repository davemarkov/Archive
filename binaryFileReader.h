#ifndef BINARY_FILE_READER_HEADER
#define BINARY_FILE_READER_HEADER

#include <iostream>
#include <fstream>

const int blockSize = 4096;

class BinaryFileReader
{
	char* block;
	int pos;
	int end;

	std::ifstream in;

public:
	BinaryFileReader(char* fileName)
		: block(nullptr), pos(0), end(blockSize),
		in(fileName, std::ios::binary)
	{
		createBlocks();
		startReading();
	}

	~BinaryFileReader()
	{
		delete[] block;
	}

	void createBlocks()
	{
		block = new char[blockSize];
	}

	void startReading()
	{
		if (isOpen())
		{
			readBlock();
		}
		else
		{
			std::cout << "reading failed\n";
			end = 0;
		}
	}

	bool isEOF()
	{
		return pos == end;
	}

	void reset()
	{
		in.seekg(0);
	}

	bool isOpen()
	{
		return in.is_open();
	}

	void closeFile()
	{
		in.close();
	}

	void readBlock()
	{
		in.read(block, blockSize);
		if (in.eof())
		{
			int end = in.gcount();
		}
	}

	void reset()
	{
		in.seekg(0);
	}

	void next()
	{
		if (pos == blockSize - 1)
		{
			readBlock();
		    pos = 0;
		}
		else
		{
			pos++;
		}
	}

	char& operator++() //++A
	{
		next();
		return block[pos];
	}

	char operator++(int) //A++
	{
		char toReturn = block[pos];
		next();
		return toReturn;
	}

	char get()
	{
		return block[pos];
	}

};

#endif//BINARY_FILE_READER_HEADER