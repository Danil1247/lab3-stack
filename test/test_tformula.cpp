#include "gtest.h"
#include "Formula.h"

TEST(TFormula, can_create_formula)
{
  string s = "a+b*c";
  ASSERT_NO_THROW(TFormula f(s));
}

TEST(TFormula, cant_create_formula_with_prohibited_symbols)
{
  string s = "a~b";
  ASSERT_ANY_THROW(TFormula f(s));
}

TEST(TFormula, formula_getinfix_returns_correct)
{
  string s("a+b");
  TFormula f(s);
  EXPECT_EQ(f.GetInfix(), s);
}

TEST(TFormula, formula_getpostfix_returns_correct)
{
  string s("a+b");
  string s2("ab+");
  TFormula f(s);
  EXPECT_EQ(f.GetPostfix(), s2);
}

TEST(TFormula, formula_getoperands_returns_correct)
{
  string s("a+b");
  TFormula f(s);
  vector<char> operand;
  operand.push_back('a');
  operand.push_back('b');
  EXPECT_EQ(f.GetOperands(), operand);
}

TEST(TFormula, formula_calculate_returns_correct)
{
  string s("a+b*c");
  TFormula f(s);
  map<char, double> operand = { {'a', 2}, {'b', 2}, {'c', 2} };
  EXPECT_EQ(f.Calculate(operand), 6);
}

TEST(TFormula, formula_calculate_throw_error_with_divide_by_zero)
{
  string s("a/b");
  TFormula f(s);
  map<char, double> operand = { {'a', 1}, {'b', 0} };
  ASSERT_ANY_THROW(f.Calculate(operand));
}