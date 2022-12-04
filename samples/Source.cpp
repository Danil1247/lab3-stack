#include "Stack.h"
#include <iostream>
#include "Formula.h"
using namespace std;

int main()
{
  TStack<int> stack(2);
  TStack<int> stack1(4);
  stack.Push(2);
  stack1 = stack;
  cout << stack1.Pop();

}