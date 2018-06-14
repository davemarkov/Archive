#ifndef STACK_HEADER
#define STACK_HEADER

template<class Type>
class Stack
{
	Type* storrage;
	int top;
	int capacity;

public:
	Stack() : storrage(nullptr), top(0), capacity(0) {}
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

private:
	void createSpace();
	void resize(int);
	void stackCopy(const Stack&);
	bool stackExist();
	bool tooBig() const;

public:
	bool full() const;
	bool empty() const;
	Type peek() const;
	void pop();
	void push(Type);
	void clear();
	void print() const;
	int getSize() { return top; }

};

template<class Type>
void Stack<Type>::print() const
{
	for (int i = 0; i < top; i++)
		std::cout << storrage[i];
	std::cout << "\n";
}

template<class Type>
Stack<Type>::Stack(const Stack& obj) :
storrage(nullptr), top(0), capacity(0)
{
	stackCopy(obj);
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& obj)
{
	if (this != &obj)
	{
		clear();
		copyStack(obj);
	}
	return *this;
}

template<class Type>
Stack<Type>::~Stack()
{
	clear();
}

template<class Type>
void Stack<Type>::createSpace()
{
	storrage = new Type[capacity = 8];
}

template<class Type>
void Stack<Type>::resize(int value)
{
	if (value == 1)  capacity *= 2;
	else if (value == -1) capacity /= 2;
	else return;

	Type* temp = new Type[capacity];
	for (int i = 0; i <= top; i++)
		temp[i] = storrage[i];
	delete[] storrage;
	storrage = temp;
}

template<class Type>
void Stack<Type>::stackCopy(const Stack<Type>& obj)
{
	capacity = obj.capacity;
	top = obj.top;

	storrage = new Type[capacity];
	for (int i = 0; i < top; i++)
		storrage[i] = obj.storrage[i];
}

template<class Type>
bool Stack<Type>::stackExist()
{
	return !!capacity;
}

template<class Type>
bool Stack<Type>::full() const
{
	return top == capacity;
}

template<class Type>
bool Stack<Type>::empty() const
{
	return !top;
}

template<class Type>
bool Stack<Type>::tooBig() const
{
	return (top < (capacity / 2) && top >= 8);
}

template<class Type>
Type Stack<Type>::peek() const
{
	if (empty())
		throw;
	return storrage[top - 1];
}

template<class Type>
void Stack<Type>::push(Type obj)
{
	if (!stackExist()) createSpace();
	if (full()) resize(1);

	storrage[top++] = obj;
}

template<class Type>
void Stack<Type>::pop()
{
	if (empty())
		throw;

	top--;

	if (tooBig())
	{
		Type temp = storrage[top];
		resize(-1);
		delete temp;
	}
	delete storrage[top];
}

template<class Type>
void Stack<Type>::clear()
{
	delete[] storrage;
	storrage = nullptr;
	capacity = 0;
	top = 0;
}

#endif//STACK_HEADER