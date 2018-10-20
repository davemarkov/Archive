#include <iostream>
#include "bitsContainer.h"

void BitsContainer::createSpace()
{
	block1 = new char[capacity];
	block2 = new char[capacity];
}

void BitsContainer::swapBlocks()
{
	char* temp = block1;
	block1 = block2;
	block2 = temp;
}

void BitsContainer::resize()
{
	char* temp = new char[capacity *= 2];
	for (int i = 0; i < size; ++i)
		temp[i] = block1[i];
	delete[] block1;
	block1 = temp;
}

//
void BitsContainer::moveBit()
{
	if (bitPos == 8)
	{
		size += 1;
		bitPos = 0;
	}
	if (isFull()) 
	{
		swapBlocks();
		size = 0;
		writeReady = true;
	}

	block1[size] <<= 1;
	bitPos += 1;
}

void BitsContainer::addCustom(int number, int len)
{
	int mask = 1 << len - 1;
	for (int i = 0; i < len; ++i)
	{
		if (number & mask)
			addOne();
		else
			addZero();
		mask >>= 1;
	}
}

void BitsContainer::addCustom(short bits, int len)
{
	short mask = 1 << len - 1;
	for (int i = 0; i < len; ++i)
	{
		if (!(bits & mask))
			addZero();
		else
			addOne();
		mask >>= 1;
	}
}

void BitsContainer::addChar(char sign)
{
	short mask = 1 << 7;
	for (int c = 0; c < 8; ++c)
	{
		if (!(sign & mask))
			addZero();
		else
			addOne();
		mask >>= 1;
	}
}

void BitsContainer::addString(char* text)
{
	for (int i = 0; text[i] != '\0'; ++i)
	{
		short mask = 1 << 7;
		for (int c = 0; c < 8; ++c)
		{
			if (!(text[i] & mask))
				addZero();
			else
				addOne();
			mask >>= 1;
		}
	}
}

void BitsContainer::addNumber(int number)
{
	unsigned int mask = 1 << 31;
	for (int i = 0; i < 32; ++i)
	{
		if (!(number & mask))
			addZero();
		else
			addOne();
		mask >>= 1;
	}
}

void BitsContainer::addNumber(short number)
{
	unsigned short mask = 1 << 15;
	for (int i = 0; i < 16; ++i)
	{
		if (!(number & mask))
			addZero();
		else
			addOne();
		mask >>= 1;
	}
}

void BitsContainer::addOne()
{
	moveBit();
	block1[size] ^= 1;
}

void BitsContainer::addZero()
{
	moveBit();
}

void BitsContainer::setEnd()
{
	block1[size] <<= (8 - bitPos);
	swapBlocks();
	writeReady = true;
}

void BitsContainer::print(int idx)
{
	short mask = 1 << 7;
	for (int i = 0; i < 8; ++i)
	{
		if (!(block1[idx] & mask))
			std::cout << 0;
		else
			std::cout << 1;
		mask >>= 1;
	}
	std::cout << "\n";
}

void BitsContainer::printAll()
{
	for (int i = 0; i <= size; ++i)
		print(i);
}

void BitsContainer::reset()
{

}

void BitsContainer::clear()
{
	delete[] block1;
	delete[] block2;
}