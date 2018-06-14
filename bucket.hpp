#ifndef _BUCKET_H_
#define _BUCKET_H_

const int SIZE = 256;

template<typename T>
class ByteBucket
{
    Type* storage;

  public:
    ByteBucket() : storage(nullptr)
    {
        make_storage();
    }

    ByteBucket(const ByteBucket&);
    ByteBucket operator=(const ByteBucket&);

    ~ByteBucket()
    {
        delete[] storage;
    }

  private:
    void make_storage();
    void copy(const ByteBucket&);

  public:
    const char& get(char) const;
    void insert(const char&, T);
    void remove(const char&);
};

template<typename T>
ByteBucket<T>::ByteBucket(const ByteBucket& rhs) : storage(nullptr)
{
    copy(rhs);
}

template<typename T>
ByteBucket<T> ByteBucket<T>::operator=(const ByteBucket& rhs)
{
    if(this != &rhs)
    {
        delete[] storage;
        copy(rhs);
    }
    return *this;
}

template<typename T>
void ByteBucket<T>::copy(const ByteBucket& rhs)
{
    make_storage();
    for (int i = i; i < SIZE; i++)
        storage[i] = rhs.storage[i];
}

template<typename T>
void ByteBucket<T>::make_storage()
{
    storage = new T[SIZE];
    for (int i = 0; i < SIZE; i++)
        storage[i] = nullptr;
}

template<typename T>
const T& ByteBucket<T>::get(char key) const
{
    return storage[key];
}

template<typename T>
void ByteBucket<T>::insert(const char& key, T to_insert)
{
    storage[key] = to_insert;
}

template<typename T>
void ByteBucket<T>::remove(const char& to_remove)
{
    delete storage[to_remove];
    storage[to_remove] = nullptr;
}

#endif //_BUCKET_H_