#ifndef HUFFMAN_HEADER
#define HUFFMAN_HEADER

#include "binaryTree.hpp"
#include "priorityQueue.hpp"
#include "stack.hpp"
#include "binaryFileReader.h"
#include "data.h"
#include "bucket.hpp"
#include "vector.hpp"

class Compression 
{
protected:
	PriorityQueue<Data*> queue;
	BinaryTree<char> tree;

	Data* root;
	bool savedEncodedData;
	ByteBucket<Data*> bucket;
	Vector<Data*> arr;

public:
	Compression(): root(nullptr), savedEncodedData(false) {}

	//it fills the encoded data ??where?? with the first walkthrough
	//then it is filled and just returns 
	class CompressionIterator
	{
		Data* current;
		bool leftSide, rightSide;
		bool isEmpty;

		struct Recursive
		{
			Data* prev;
			bool leftSide, rightSide;
			Recursive(Data* toSave, bool left, bool right)
				: prev(toSave), leftSide(left), rightSide(right) {}
		};

		Stack<Recursive*> prevData;

	public:
		CompressionIterator(Data* node) : current(node),
			leftSide(true), rightSide(true), isEmpty(false) {}

		bool endOfIterator()
		{
			return isEmpty;
		}

		CompressionIterator& operator++() //++tree
		{
				if (!leftSide && !rightSide)
					setToPrevious();

				if (!(current->left) && !(current->right))
				{
					leftSide = rightSide = false;
					return *this;
				}

				if (rightSide)
				{
					Recursive* newElem = new Recursive(current, leftSide, false);
					prevData.push(newElem);
					current = current->right;
					leftSide = rightSide = true;
					return ++(*this);

				}
				
				if (leftSide)
				{
					Recursive* newElem = new Recursive(current, false, rightSide);
					prevData.push(newElem);
					current = current->left;
					leftSide = rightSide = true;
					return ++(*this);
				}

				isEmpty = true;
						
		}

		Data* operator->()
		{
			return current;
		}

	private:
		void setToPrevious()
		{
			if (!prevData.empty())
			{
				current = prevData.peek()->prev;
				leftSide = prevData.peek()->leftSide;
				rightSide = prevData.peek()->rightSide;
				prevData.pop();
			}
		}

	};

	CompressionIterator begin() const { return CompressionIterator(root); }

private:
	Data* encode(bool attachToLeft, Data*& lastNode);
	void saveEncodedData(Data*& current, short value = 0, int cnt = 0);

public:
	void encode();
	void encodeWithQueue();
};

#endif//HUFFMAN_HEADER