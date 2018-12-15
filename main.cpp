#include <iostream>
#include "calculator.h"
using namespace std;


void testAdditionAndSubtraction() {
	Calculator d;
	cout << "Test Addition and Subtraction: " << endl;
	cout << d.calculate("2 + 3") << endl; //test regular adding
	cout << d.calculate("-6 + -4") << endl; //test adding negs.
	cout << d.calculate("6 - 4") << endl; //test subtraction
	cout << d.calculate("-6 - 4") << endl; //test neg minus pos
	cout << d.calculate("-6 - -4") << endl; //test minus minus = +  with negative number
	cout << d.calculate("6 - -4") << endl; //test  minus minus = plus
	cout << d.calculate("0 - -4") << endl << endl; //test 0 adding
}
void testMultiplicationAndDivision() {
	Calculator c;
	cout << "Test Multiplication: " << endl;
	cout << c.calculate("2 * 3") << endl; //test pos times pos
	cout << c.calculate("-2 * 3") << endl; //testneg time pos
	cout << c.calculate("-2 * -3") << endl; //test neg times neg
	cout << c.calculate("8 * -3") << endl; //test pos times neg
	cout << "Test Divison: " << endl;
	cout << c.calculate("8 / 3") << endl; //test pos even / pos odd
	cout << c.calculate("8 / 4") << endl; //test pos even / pos even
	cout << c.calculate("-2 / 1") << endl; //test -even / pos 1
	cout << c.calculate("-3 / -2") << endl; //test -odd / -even 
	cout << c.calculate(" 8 / -4") << endl; //test pos even / -even
	cout << c.calculate(" 8 / 0") << endl << endl; //test divide by 0.
}
void testPrecedence() {
	cout << "test Precedence: " << endl;
	Calculator d;
	cout << d.calculate("3 + 4 * 3") << endl; //times before +
	cout << d.calculate("3 / 2 * 6") << endl; //equal prec.
	cout << d.calculate("-3 * 2 + 3 / 4") << endl; // * then div and last + 0.
	cout << d.calculate("-2 * -3 + 8 / 3") << endl; // * then /, then +
	cout << d.calculate("( 8 + 3 ) * 2") << endl; //first add and then multiply.
	cout << d.calculate("2000 / ( 9 * 29 + 6 ) / 2") << endl << endl; // first * then + then  8/ans and ans /2
}

// expression have to have spaces between operators and operands. Catches, / 0.
int main() {
	testAdditionAndSubtraction();
	testMultiplicationAndDivision();
	testPrecedence();
	cin.get(); //stops command prompt from exiting
	return 0;
}