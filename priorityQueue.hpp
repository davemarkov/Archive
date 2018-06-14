#ifndef PRIORITY_QUEUE_HEADER
#define PRIORITY_QUEUE_HEADER

template<typename T>
class PriorityQueue
{
	T *arr;
	int size;
	int capacity;

  public:
	PriorityQueue() : size(0), capacity(64)
	{
		create(capacity);
	}
	PriorityQueue(const PriorityQueue &);
	PriorityQueue operator=(const PriorityQueue &);
	~PriorityQueue()
	{
		clear();
	}

  private:
	void create(int newCapacity);
	void resize();
	void clear();
	void copy();
	void insertNew(int current);
	void swap(T &, T &);
	void rearange(int current);

  public:
	bool isEmpty() const;
	bool isFull() const;
	void insert(T toInsert);
	T peekMin() const;
	T &getMin();
	int getSize() const;
	//void remove;
};

template <typename T>
void PriorityQueue<T>::create(int newCapacity)
{
	arr = new T[newCapacity];
}

template <typename T>
void PriorityQueue<T>::resize()
{
	T *newSet = new T[capacity *= 2];
	for (int i = 0; i < size; i++)
		newSet[i] = arr[i];
	delete[] arr;
	arr = newSet;
}

template <typename T>
void PriorityQueue<T>::clear()
{
	delete[] arr;
	arr = nullptr;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return !size;
}

template <typename T>
bool PriorityQueue<T>::isFull() const
{
	return size == capacity;
}

template <typename T>
int PriorityQueue<T>::getSize() const
{
	return size;
}

template <typename T>
void PriorityQueue<T>::insert(T toInsert)
{
	if (isFull())
		resize();
	arr[size++] = toInsert;
	if (size > 1)
		insertNew(size - 1);
}

template <typename T>
void PriorityQueue<T>::insertNew(int current)
{
	if (!current)
		return;
	int prev = (current - 1) / 2;
	if (arr[current] >= arr[prev])
		return;
	swap(arr[current], arr[prev]);
	insertNew(prev);
}

template <typename T>
void PriorityQueue<T>::swap(T &value1, T &value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T PriorityQueue<T>::peekMin() const
{
	return arr[0];
}

template <typename T>
T &PriorityQueue<T>::getMin()
{
	T toReturn = arr[0];

	if (size == 1)
		arr[0] == NULL;
	else
	{
		arr[0] = arr[size - 1];
		arr[size - 1] = NULL;
		rearange(0);
	}
	size--;

	return toReturn;
}

template <typename T>
void PriorityQueue<T>::rearange(int current)
{
	int left = (current * 2) + 1;
	if (left >= size)
		return;

	int right = left + 1;

	int min = 0;
	if (right < size)
		min = (arr[left] > arr[right]) ? right : left;
	else
		min = left;

	if (arr[current] <= arr[min])
		return;

	swap(arr[current], arr[min]);
	rearange(min);
}

#endif //PRIORITY_QUEUE_HEADER