#ifndef BITS_CONTAINER_HEADER
#define BITS_CONTAINER_HEADER

const int MAX_SIZE = 4096;

class BitsContainer
{
	int bitPos;
	int capacity;
	int size;
	char* block1;
	char* block2;
	bool writeReady;

public:

public:
	BitsContainer() : block1(nullptr), block2(nullptr), size(0),
	bitPos(0), capacity(MAX_SIZE), writeReady(false)
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
	void clear();
	void swapBlocks();

public:
	bool isFull() { return size == capacity; }
	bool isReady() const { return writeReady;}
	void setDoneWritting() { writeReady = false; }
	void moveBit();
	void addCustom(int number, int bitSize);
	void addCustom(short bits, int len);
	//void addCustom(char byte, int len);
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
	char* getBlockToWrite() {return block2;}
	void reset();
	int getSize() const { return size; }

};

#endif//BITS_CONTAINER_HEADER