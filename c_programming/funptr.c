#include <stdio.h>

void fun1(int x)
{
	printf("The value passed is : %d\n", x);
}

int main(void)
{
	void (*fun_ptr) (int) = &fun1;
	(*fun_ptr)(10);
	return 0;
}
