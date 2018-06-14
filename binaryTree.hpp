#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER

#include "stack.hpp"

template<typename Type>
class BinaryTree
{
	struct Node
	{
		Type key;
		int cnt;
		Node *left, *right;
		Node() :
			left(nullptr), right(nullptr), cnt(1){}
	};

	Node* root;
	int size;

public:
	BinaryTree() : root(nullptr), size(0) {}
	~BinaryTree()
	{
		clear(root);
	}

	class BinaryTreeIterator
	{
		friend class BinaryTree;
		Node* current;
		bool leftSide, rightSide;
		struct Route
		{
			Node* prev;
			bool leftSide, rightSide;
			Route(Node* toSave, bool left, bool right) :
				leftSide(left), rightSide(right), prev(toSave) {}
		};

		Stack<Route*> prevNodes;

	public:
		BinaryTreeIterator(Node* root) : current(root),
			leftSide(true), rightSide(true) {}

		bool endOfIterator()
		{
			if (prevNodes.getSize() == 1)
			{
				Route* check = prevNodes.peek();
				if (check->leftSize == false && check->rightSide == false)
					return true;
			}

			return false;
		}

		BinaryTreeIterator& operator++() //++tree
		{	
			if (current->left && leftSide)
			{
				Route* newElem = new Route(current, false, rightSide);
				prevNodes.push(newElem);
				current = current->left;
				leftSide = rightSide = true;
				return *this;
			}

			if (current->right && rightSide)
			{
				Route* newElem = new Route(current, leftSide, false);
				prevNodes.push(newElem);
				current = current->right;
				leftSide = rightSide = true;
				return *this;
			}

			if (prevNodes.empty())
			{
				BinaryTreeIterator* iter = nullptr;
				return *iter;
			}

			current = prevNodes.peek()->prev;
			leftSide = prevNodes.peek()->leftSide;
			rightSide = prevNodes.peek()->rightSide;
			prevNodes.pop();
			return (++*this);

		}

		Node* operator->()
		{
			return &current;
		}

	};

	BinaryTreeIterator begin() const { return BinaryTreeIterator(root); }

private:
	void createNode(Node*& elem);
	void clear(Node* current);

private:

	Type* searchTree(Node* current, Type& key);
	Node* findTree(Node* current, Type& key);
	void printTree(Node* current);

public:
	void print() { printTree(root); }
	void add(Type& key);
	Type* search(Type& key) { return searchTree(root, key); };


private:
	void findFreeSpot(Node*& current, Type& key);

public:
	void balanceTree(); // DSW

private:
	Node* toList(Node* current, Node* midBeg);
	Node* arrangeList(Node*& current, int newSize);
	void printList(Node* current);

private:
	BinaryTree(const BinaryTree&) = delete;
	BinaryTree& operator=(const BinaryTree&) = delete;

};


template<typename Type>
void BinaryTree<Type>::createNode(Node*& elem)
{
	elem = new Node;
}

template<typename Type>
void BinaryTree<Type>::findFreeSpot(Node*& current, Type& key)
{
	if (!current)
	{
		createNode(current);
		current->key = key;
		++size;
	}

	if (current->key == key)
	{
		++cnt;
		return;
	}

	key < current->key ? findFreeSpot(current->left, key) :
		findFreeSpot(current->right, key);
}

template<typename Type>
void BinaryTree<Type>::add(Type& key)
{
	findFreeSpot(root, key);
}

template<typename Type>
Type* BinaryTree<Type>::searchTree(Node* current, Type& key)
{
	if (!current) return nullptr;
	if (current->key == key)
		return &current->key;
	return key < current->key ? searchTree(current->left, key) :
		searchTree(current->right, key);
}

template<typename Type>
typename BinaryTree<Type>::Node* BinaryTree<Type>::findTree(Node* current, Type& key)
{
	if (!current) return current;
	if (current->key == key)
		return current;
	return key < current->key ? searchTree(current->left, key) :
		searchTree(current->right, key);
}

template<typename Type>
typename BinaryTree<Type>::Node* BinaryTree<Type>::toList(Node* current, Node* midBeg)
{
	if (!current) return current;
	if (current->left)
	{
		current->left = toList(current->left, midBeg);
		current->left->right = current;
	}
	else
	{
		if (midBeg)
		{
			current->left = midBeg;
			midBeg->right = current;
		}
	}
	if (current->right)
	{
		midBeg = current;
		return toList(current->right, midBeg);
	}

	return current;
}

template<typename Type>
void BinaryTree<Type>::balanceTree()
{
	Node* middle = nullptr;
	root = toList(root, middle);

	int newSize = size / 2;
	for (int i = 0; i < newSize; ++i)
		root = root->left;

	root = arrangeList(root, size);
}

template<typename Type>
void BinaryTree<Type>::printList(Node* current)
{
	if (!current) return;
	std::cout << current->key << " ";
	printList(current->left);
}

template<typename Type>
typename BinaryTree<Type>::Node* BinaryTree<Type>::arrangeList(Node*& current, int newSize)
{
	if (current)
	{
		Node*left, *right;
		left = right = current;

		int offset = newSize / 2;
		if ((offset % 2) != 0) offset += 1;
		offset /= 2;
		if (!offset) offset += 1;
		for (int i = 0; i < offset; ++i)
		{
			left = left->left;
			right = right->right;
		}

		if (current->left)
		{
			int leftSize = newSize / 2;
			current->left->right = nullptr;
			if (!(newSize % 2)) leftSize -= 1;
			current->left = arrangeList(left, leftSize);
		}

		if (current->right)
		{
			current->right->left = nullptr;
			current->right = arrangeList(right, newSize / 2);
		}
	}
	return current;
}

template<typename Type>
void BinaryTree<Type>::printTree(Node* current)
{
	if (!current) return;

	printTree(current->left);

	std::cout << current->key;
	std::cout << "-----------------------------------\n";

	printTree(current->right);
}

template<typename Type>
void BinaryTree<Type>::clear(Node* current)
{
	if (current)
	{

		clear(current->left);
		clear(current->right);
		delete current;
	}
}

#endif//BINARY_TREE_HEADER