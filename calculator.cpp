#include "calculator.h"



Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

//calculates the answer to the given expression.
//precond: The expression must have a space after every operator and operand
//if a negative number, the negative sign must be right next to the number.
//Can't handle divide by zero exception.
//postcond: Returns integer value result.
string Calculator::calculate(const string & expres)
{
	map<string, int> prec;
	prec["*"] = 3; prec["/"] = 3; prec["+"] = 2; prec["-"] = 2; prec["("] = 1;
	string token = "";
	stack<string> operations;
	string postFix ="";
	istringstream iss(expres);
	while (iss >> token) {
		if (isdigit(token[0]) || (token.length() >1 && isdigit(token[1]))) {
			postFix += token + " ";
		}
		else if (token == "(") {
			operations.push(token);
		}
		else if (token == ")") {
			string top = operations.top();
			operations.pop();
			while (top != "(") {
				postFix += top + " ";
				top = operations.top();
				operations.pop();
			}
		}
		else {
			while (!operations.empty() && (prec[operations.top()] >= prec[token])) {
				postFix+= operations.top() + " "; 
				operations.pop();
			}
			operations.push(token);
		}
	}
	while (!operations.empty()) {
		postFix += operations.top() + " ";
		operations.pop();
	}
	//just a vector check.
	/*while (!postFix.empty()) {
		cout << postFix.top() << endl;
		postFix.pop();
	} */
	return computeResult(postFix);
}


//helper method that takes the calulate functions postfix notation of the expression
//and solves it. 
//preCond: The postFix must have a space between every operator and operand, exceptions include negative numbers
string Calculator::computeResult(string & postNotation)
{
	stack<int> operands;
	istringstream iss(postNotation);
	string token = "";
	while (iss >> token) {
		if (isdigit(token[0]) || (token.length() >1 && isdigit(token[1]))) {
			operands.push(stoi(token));
		}
		else {
			int operand2 = operands.top(); 
			operands.pop();
			int operand1 = operands.top();
			operands.pop();
			string result = doMath(token, operand1, operand2);
			if (result[0] == 'E') {
				return result;
			}
			operands.push(stoi(result));
		}
	}
	return to_string(operands.top());
}

//helper method for doing single calculations, used by the compute Result method to make things
//less complicated.
string Calculator::doMath(const string& token, const int & operand1, int & operand2)
{
	if (token == "*") {
		return to_string((operand1 * operand2));
	}
	else if (token == "/") {
		if (operand2 == 0) {
			return "Error, can't Divide by 0.";
		}
		return to_string((operand1 / operand2));
	}
	else if (token == "+") {
		return to_string((operand1 + operand2));
	}
	else {
		return to_string((operand1 - operand2));
	}
}
