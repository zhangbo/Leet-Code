#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char const *argv[])
{
	stackT *stk = NULL;
	StackInit(&stk, 20);
	StackPush(&stk, "f");
	StackPush(&stk, "u");
	StackPush(&stk, "c");
	StackPush(&stk, "k");
	StackPush(&stk, " ");
	StackPush(&stk, "y");
	StackPush(&stk, "o");
	StackPush(&stk, "u");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	StackPush(&stk, "!");
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	printf("%c\n", StackPop(&stk));
	return 0;
}