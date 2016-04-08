/*--------------------------------------------------------------------------------------
CS 2413	: Data Structures
PROJECT 1
Presented by:	TEAM "WESLEY": Wesley Ford (Leader), Robert Conner & Akinola Akinlawon
Due Date:		February 16, 2015
Project Name:	Postfix Calculator
Description: 	our postfix calculator submission is a program that would ask the user
				to input numbers that would be operated on mathematically using postfix 
				expressions to get numerical answers.
----------------------------------------------------------------------------------------*/

#include <iostream>
#include <cctype> 
#ifndef _stackTemp_h
#define _stackTemp_h
#define size 10
using namespace std;

template <class T>
class stack {

	T itemArray[size];
	int cnt, top;

  public:

	stack();
	bool isFull();				//returns if the count is size after being tested
	bool isEmpty();				//returns if the count is 0 after being tested 
	T getTop();					//returns where the top of the stack is
	void print();				//performs loop to display all items in the stack
	bool push(T newItem);		//checks that the stack is not full and then pushes an item on to the stack		
	bool pop();					//checks that the stack is not empty 
	int getCnt();				//returns the count value
	void reset();				//resets the stack
};


class calculator {

// the operands for the calculator will be stored here
	int firstInput;
	int secondInput;

   public:
	
// puts values into the operand variables
	void setInput1(int input1);
	void setInput2(int input2);

// returns the values in the operands for use
	int getInput1();
	int getInput2();

	bool runCalc(); // asks if the user wants to continue using the calculator
	int calcExpression(string expression); //accepts the entered expression and calculates the resulting value
	string getExpression(); // asks for the postfix expression to be entered
	bool isValid(stack<int> s); // checks if the entered expression is valid
	
};


#include "calculator.cpp"
#endif

