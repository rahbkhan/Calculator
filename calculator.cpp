/* CALCULATOR.CPP
 This file is included from calculator.h*/
//STACK TEMPLATE IMPLEMENTATIONS





template <class T>
stack<T>::stack(){

	cnt = 0; top = -1;
}

template <class T>
bool stack<T>::isFull(){

	return cnt == size;
}

template <class T>
bool stack<T>::isEmpty(){

	return cnt == 0;
}

template <class T>
T stack<T>::getTop(){

	return itemArray[top];
}

template <class T>
void stack<T>::reset(){

	cnt = 0; top = -1;
}

template <class T>
bool stack<T>::pop(){

	if(!isEmpty()){
		top--; cnt--;
		return true;
	}
	else
		return false;
}

template <class T>
bool stack<T>::push(T newItem){

	if(!isFull()){
		itemArray[top+1] = newItem;
		cnt++; top++;
	}
}

template <class T>
void stack<T>::print(){

	for(int i = 0; i < cnt; i++)
		cout << itemArray[top-i] << " ";

	cout << endl;
}

template <class T>
int stack<T>::getCnt(){

	return cnt;
}

//-------------------------------------------------------------------------------------------- 
// BEGINNING OF CALCULATOR IMPLEMENTATIONS
// PART A: Looping the calculator

bool calculator::runCalc() // checks if the user wants to continue to run the calc
{
        string r = "a"; //will hold the user's response
        cout << "Run again (y/n): ";
	
	getline(cin, r);
		

        if( r[0]  == 'y' || r[0]== 'Y') // continues function if answer is y or Y
                return true;
        else if( r[0] == 'n' || r[0] == 'N') // quits function if answer is n or N
                return false;
  	else{
		cout << "Invalid input - in runCalc" << endl;
		return false;
	    }// end of else      

}

//-------------------------------------------------------------------------------------------------
//PART B: Calculating for the calculator

int calculator::calcExpression(string expression) // accepts the entered string, the postfix expression to be solved, returned by getExpression()
{

	stack<int> stack;

	for(int i = 0; i < expression.length(); i++ ) // reads through the entered string
	{
// case one: number
		if(isdigit(expression[i])) // if the char is a number
		{ 
			int temp = expression[i] - '0'; // converts the numeric character to a number

			while(isdigit(expression[i+1])) //checks if the next value is also a number
			{

				temp = temp * 10 + (expression[i+1] - '0'); // move the value up a place and add the next value to it
				i++; // force update i as we already know we've already used it
				
			} // end of while

			 stack.push(temp); // put the value onto the stack

		} // end of if digit

// case two: operator
		else if(expression[i] == '+' || expression[i] == '*' || expression[i] == '-' || expression[i] == '/' || expression[i] == '%') //if the char is a +, -, /, %, or * operator
		{ 
			if(!stack.isEmpty()) // checks if the stack is initially empty (1)
			{
				//note: input 1 is actually the second value put on stack
				setInput1((stack.getTop())); // puts the value on top of the stack in Input 1
				stack.pop(); // removes the value from the stack after it's stored


					if(!stack.isEmpty()) // checks if its empty after the first pop (2)
					{
						//note: temp 2 is actually the first value put on stack
						setInput2((stack.getTop())); // puts the value on top of the stack in Input 2
						stack.pop(); // remove value from stack


						switch(expression[i]) // used to determine the type of math done based on the operator
						{
							case '+':  stack.push((getInput1()) + (getInput2())); break; // the second entered value + the first 
							case '*':  stack.push((getInput1()) * (getInput2())); break; // the second entered value * the first
							case '-':  stack.push((getInput2()) - (getInput1())); break; // the first entered value - the second
							case '/':  stack.push((getInput2()) / (getInput1())); break; // the first entered value / the second
							case '%':  stack.push((getInput2()) % (getInput1())); break; // the first entered value % the second
						} // end of switch

					} // end of second is empty

			} // end of first is empty

		} // end of else if alpha

// case three: space
		else if(expression[i] == ' ' || expression[i] == '\n') //make it blanket else to include \n?
			{ } // do nothing

	} // end of for

	
// outputs the value of the expression if it was valid
	if(isValid(stack))
		cout << "The result of the expression is: " << (stack.getTop()) << endl;
	else
		cout << "Invalid input - in calcExp" << endl;




	stack.reset(); //clear stack in case of continuous use
} 

//-------------------------------------------------------------------------------------------------
//PART C: Character reading, input and output

string calculator::getExpression()
{
	
	string expression; // is the string that'l be used by the calcExpression function

	cout << "Enter the expression to be solved: ";

	getline(cin, expression); // allows the necessary spaces in the expression to be put int the string

  cout << "Expression string is: " << expression << endl;

	return expression; // sends the string back to be used
}

//sets inputs
void calculator::setInput1(int one)
	{
	    firstInput = one;
	}

void calculator::setInput2(int two)
	{
	   secondInput=two;
	}

//get inputs
int calculator::getInput1()
{
    return firstInput;
}

int calculator::getInput2()
{
    return secondInput;

}

bool calculator::isValid(stack<int> s) // accepts the stack used in calcExp function to determine if the stack only has the final result 
{

	if(s.getCnt() == 1)
		return true; //there is only one value (the result) on the stack
	else
		return false; // there are none or multiple values remaining on the stack	
}
//-------------------------------------------------------------------------------------------------