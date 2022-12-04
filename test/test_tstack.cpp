#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> stack(4));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, can_get_size)
{
  TStack<int> stack(3);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  EXPECT_EQ(3, stack.GetSize());
}

TEST(TStack, can_put_item_into_stack)
{
  TStack<int> stack(4);
  ASSERT_NO_THROW(stack.Push(3));
}

TEST(TStack, can_pop_item_from_stack)
{
  TStack<int> stack(3);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  ASSERT_NO_THROW(stack.Pop());
}

TEST(TStack, can_check_for_emptiness)
{
  TStack<int> stack(4);
  EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(TStack, can_check_for_fullness)
{
  TStack<int> stack(3);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  EXPECT_EQ(stack.IsFull(), true);
}

TEST(TStack, cant_pop_item_from_empty_stack)
{
  TStack<int> stack(4);
  ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, cant_put_item_into_full_stack)
{
  TStack<int> stack(3);
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  ASSERT_ANY_THROW(stack.Push(5));
}