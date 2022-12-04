#ifndef __Formula_H__
#define __Formula_H__

#include <iostream>
#include <vector>
#include <map>
#include "Stack.h"

using namespace std;

class TFormula
{
private:
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;

	void Parse();
	void ToPostfix();

public:
	TFormula(string _infix);
	string GetInfix() const;
	string GetPostfix() const;

	vector<char> GetOperands() const;
	double Calculate(const map<char, double>& _value);
};
#endif


inline void TFormula::Parse()
{
	for (char c : infix)
		if ((c == '!') || (c == '@') || (c == '_') || (c == '&') || (c == '~') || (c == '$') || (c == '?') || (c == ':'))
		{
			throw "Error";
		}
		else
			lexems.push_back(c);
}

inline void TFormula::ToPostfix()
{
	Parse();
	TStack<char> stack;
	char stackItem;
	for (char item : lexems)
	{
		switch (item)
		{
		case '(':
			stack.Push(item);
			break;
		case ')':
			stackItem = stack.Pop();
			while (stackItem != '(')
			{
				postfix += stackItem;
				stackItem = stack.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!stack.IsEmpty())
			{
				stackItem = stack.Pop();
				if (priority[item] <= priority[stackItem])
					postfix += stackItem;
				else
				{
					stack.Push(stackItem);
					break;
				}
			}
			stack.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}
	}
	while (!stack.IsEmpty())
	{
		stackItem = stack.Pop();
		postfix += stackItem;
	}
}

inline TFormula::TFormula(string infix) : infix(infix)
{
	priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
	ToPostfix();
}

inline string TFormula::GetInfix() const
{
	return infix;
}

inline string TFormula::GetPostfix() const
{
	return postfix;
}

inline vector<char> TFormula::GetOperands() const
{
	vector<char> operand;
	for (const auto& item : operands)
		operand.push_back(item.first);
	return operand;
}

inline double TFormula::Calculate(const map<char, double>& _value)
{
	for (auto& val : _value)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e)
		{}
	}
	TStack<double> stack;
	double leftOperand, rightOperand;
	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			rightOperand = stack.Pop();
			leftOperand = stack.Pop();
			stack.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = stack.Pop();
			leftOperand = stack.Pop();
			stack.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = stack.Pop();
			leftOperand = stack.Pop();
			stack.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = stack.Pop();
			leftOperand = stack.Pop();
			if (rightOperand == 0)
			{
				throw "Error";
			}
			else
			{
				stack.Push(leftOperand / rightOperand);
				break;
		default:
			stack.Push(operands[lexem]);
			}
		}
	}
	return stack.Pop();
}
