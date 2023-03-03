/////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Eddie G. Pineda										   //
//Date: 12/01/2022										   //
//Program Statement: Create a template that will create a static stack of any type of data.        //
//                   Also create a template that will create a dynamic stack of integers.          //
//                   Test both stacks with a driver program.                                       //
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

//Static Stack
template <typename T> //Template header
class StaticStack { //Class definition
public:
	StaticStack(); //Default constructor
	StaticStack(int); //Overloaded constructor
	~StaticStack(); //Destructor
	void push(T); //Pushes a value into the stack
	void pop(T&); //Pops a value out of the stack
	bool isEmpty(); //Checks if the stack is empty

private:
	T* stackArr; //Stack array
	int capacity; //Capacity of stack
	int top; //Top of stack
};

template <class T> //Template header
StaticStack<T>::StaticStack() { //Default constructor
	capacity = 0; //Sets capacity to 0
	top = NULL; //Sets top to NULL
}

template <class T>
StaticStack<T>::StaticStack(int capacity) { //Overloaded constructor
	this->capacity = capacity; //Sets the capacity to the integer in the function
	stackArr = new T[capacity]; //Creates a new stack array
	top = 0; //Sets the top equal to 0
}

template <class T>
StaticStack<T>::~StaticStack() { //Destructor
	delete[] stackArr; //Deletes the array to prevent memory leaks
}

template <class T>
void StaticStack<T>::push(T val) { //Pushes a value into the stack
	if (top == capacity) { //If the top equals capacity
		cout << "Stack Overflow"; //Throw an overflow exception
		exit(1);
	}
	stackArr[top] = val; //Sets the top value to the new T value
	top++; //Adds one to the top value
}

template <class T>
void StaticStack<T>::pop(T& val) { //Pops a value out of the stack
	if (isEmpty()) { //If stack is empty
		cout << "Stack Underflow"; //Throw underflow excetion
		exit(1);
	}
	top--; //Take away the stack top
	val = stackArr[top]; //Set val to the stack top
}

template <class T>
bool StaticStack<T>::isEmpty() { //Checks if the stack is empty
	if (top == 0) { //If top is empty
		return true;
	}
	else {
		return false;
	}
}

//Dynamic Stack
template <class T>
class DynStack {
public:
	DynStack(); //Defaultconstructor
	void push(T); //Pushes a value into the stack
	void pop(T&); //Pops a value out of the stack
	bool isEmpty(); //Checks if the stack is empty

private:
	class node { //Node class
		friend class DynStack; //Gives access to all members of class DynStack
		T value; //Value of node
		node* next; //Moves onto the next node
		node(T val1, node* next1 = NULL) { //Overloaded constructor
			value = val1; //Sets value to the overloaded input
			next = next1; //Moves onto the next node
		}
	};
	node* top; //Top node
};

template <class T>
DynStack<T>::DynStack() {
	top = NULL; //Sets top to NULL
}

template <class T>
void DynStack<T>::push(T val) {
	top = new node(val, top); //Pushes a new node in with the pushed val
}

template <class T>
void DynStack<T>::pop(T& val) {
	if (isEmpty()) { //Checks if the stack is empty
		cout << "Stack is empty" << endl;
		exit(1);
	}
	else {
		node* temp; //Creates a temporary node
		val = top->value; //Sets val to the current top value
		temp = top; //Sets temp to the top node
		top = top->next; //Moves top to the next node
		delete temp; //Deletes temp with the previous node value
	}
}

template <class T>
bool DynStack<T>::isEmpty() {
	if (top == NULL) { //If the top node is empty
		return true;
	}
	else {
		return false;
	}
}
int main() {
	///////Static Stack
	StaticStack<double> dobStack(5); //Creates a new stack
	double dVal; //Pop value
	double dVals[] = { 1.2,2.3,3.4,4.5,5.6 }; //List of doubles to push into the stack
	////////Dynamic Stack
	StaticStack<char> charStack(5); //Creates a new stack
	char currChar; //Pop value
	char chars[] = {'a','b','c','d','e'}; //List of doubles to push into the stack

	cout << "Static Stack work: " << endl;
	cout << "Static Push value test: " << endl;
	for (int i = 0; i < 5; i++) { //For loop to parse through all values to push into stack
		cout << dVals[i] << " " << flush;
		dobStack.push(dVals[i]); //Pushes value of current index into the stack
	}

	cout << endl << "Static Pop test: " << endl;
	while (!dobStack.isEmpty()) { //While loop to parse through the entire stack to pop each value
		dobStack.pop(dVal); //Pops a value in stack and stores it into dVal
		cout << dVal << " " << flush;
	}

	cout << endl << endl << "Dynamic Stack work: " << endl;
	cout << "Dynamic push test: " << endl;
	for (int i = 0; i < 5; i++) { //For loop to parse through all values to push into stack
		cout << chars[i] << " " << flush;
		charStack.push(chars[i]); //Pushes value of current index into the stack
	}

	cout << endl << "Dynamic Pop test: " << endl;
	while (!charStack.isEmpty()) { //While loop to parse through the entire stack to pop each value
		charStack.pop(currChar); //Pops a value in stack and stores it into dVal
		cout << currChar << " " << flush;
	}

	return 0;
}
