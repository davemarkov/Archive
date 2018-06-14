#ifndef BITS_CONTAINER_HEADER
#define BITS_CONTAINER_HEADER

class BitsContainer
{
	int integerSize;
	int capacity;

public:
	int size;
	char* allBits;
	BitsContainer() : allBits(nullptr), size(0), integerSize(0), capacity(64)
	{
		createSpace();
	}
	~BitsContainer()
	{
		clear();
	}

private:
	void createSpace();
	void resize();

public:
	bool isFull() { return size == capacity; }
	void moveBit();
	void addCustom(int number, int bitSize);
	void addCustom(short bits, int len);
	void addChar(char sign);
	void addString(char* text);
	void addNumber(int number);
	void addNumber(short number);
	void addOne();
	void addZero();
	void setEnd();
	void print(int idx);
	void print();
	void printAll();
	void clear();

};

#endif//BITS_CONTAINER_HEADER