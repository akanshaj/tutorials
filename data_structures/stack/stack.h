/*
 *	Stack implementation header file
 */
struct stack {
	int data;
	struct stack *next;
};

typedef stack STACK;

// function declerations
void push(int data);
int pop();
int peek();
