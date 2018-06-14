#include <iostream>
#include "huffman.h"

void Compression::encode()
{
	Data* newNode = queue.getMin();
	root = encode(false, newNode);
}

Data* Compression::encode(bool attachedToLeft, Data*& lastNode)
{
	if (queue.isEmpty()) return lastNode;
	Data* newNode = new Data;

	newNode->right = lastNode;
	
	Data* toInsert = queue.getMin();
		
	if (newNode->right->cnt <= toInsert->cnt)
		newNode->left = toInsert;
	else
	{
		do
		{
			newNode->left = encode(true, toInsert);
			if (queue.isEmpty()) break;
		} while (newNode->right->cnt > newNode->left->cnt);
	}
	
	newNode->cnt = newNode->left->cnt + newNode->right->cnt;

	if(attachedToLeft)
		return newNode;
	
	return encode(false, newNode);
}

void Compression::encodeWithQueue()
{
	if (queue.isEmpty()) return;
	
	while (queue.getSize() != 1)
	{
		Data* newNode = new Data;
		newNode->right = queue.getMin();
		newNode->left = queue.getMin();
		newNode->cnt = newNode->right->cnt + newNode->left->cnt;
		queue.insert(newNode);
	}

	root = queue.getMin();
}

void Compression::saveEncodedData(Data*& current, short value = 0, int cnt = 0)
{
	if (!current) return;

	if (!(current->left) && !(current->right))
	{
		current->encoded = value;
		current->codeLength = cnt;
		bucket.insert(current->elem, current);
		current = nullptr;
		return;
	}

	value <<= 1;
	saveEncodedData(current->left, value, cnt + 1);
	saveEncodedData(current->right, value + 1, cnt + 1);
}
