#pragma once

const int MaxStackSize = 128;

template <class T>
class TStack
{
protected:
  T* pMem;
  int size;
  int start;

public:
  TStack(size_t _sz = MaxStackSize);
  TStack(const TStack<T>& _stack);
  TStack(TStack<T>&& _stack);
  ~TStack();

  int GetSize();
  int GetStart();

  bool IsFull();
  bool IsEmpty();

  void Push(T _elem);
  T Top();
  T Pop();
};

template<class T>
inline TStack<T>::TStack(size_t _sz)
{
  if (_sz <= 0)
    throw "Error";

  size = _sz;
  start = -1;
  pMem = new T[size];

  for (int i = 0; i < size; i++)
    pMem[i] = {};
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& _stack)
{
  if (_stack.pMem == nullptr)
    throw "Error";

  size = _stack.size;
  start = _stack.start;
  pMem = new T[size];

  for (int i = 0; i < size; i++)
    pMem[i] = _stack.pMem[i];
}

template<class T>
inline TStack<T>::TStack(TStack<T>&& _stack)
{
  size = _stack.size;
  start = _stack.start;
  pMem = _stack.pMem;

  _stack.size = 0;
  _stack.start = 0;
  _stack.pMem = nullptr;
}

template<class T>
inline TStack<T>::~TStack()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = 0;
    size = 0;
    start = 0;
  }
}

template<class T>
inline int TStack<T>::GetSize()
{
  return size;
}

template<class T>
inline int TStack<T>::GetStart()
{
  return start;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  return (start == (size - 1));
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  return (start == -1);
}

template<class T>
inline void TStack<T>::Push(T _elem)
{
  if (IsFull())
    throw "Error";

  pMem[++start] = _elem;
}

template<class T>
inline T TStack<T>::Top()
{
  return T();
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty())
    throw "Error";

  return pMem[start--];
}