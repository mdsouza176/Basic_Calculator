#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;
class Calculator
{
public:
	Calculator();
	~Calculator();
	//this will convert the given expression from infix to postFix. 
	//precond: The expression has to have spaces between operator and operands
	//poscond: returns string that has the expression in postfix notation
	string calculate(const string& expres);

	//this method takes the postfix notation string from teh infixToPostfix method and
	//does all the operations and returns result.
	//precond: the postfix notation 
	string computeResult(string& postNotation);

	//calculate individual operations.
	string doMath(const string& token, const int& operand1, int& operand2);
};

