#include "calculator.h" //includes the calculator file

int main(){

// Declaration of calculator object
	calculator x;

do{ // do-while loop to run the calculator at least once

	string s = (x.getExpression()); // asks for and returns the equation as a string
	x.calcExpression(s); // send the expression to be calculated

	
}while(x.runCalc());
	
	return 0;
}
