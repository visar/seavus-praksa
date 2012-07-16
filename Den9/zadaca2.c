#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	char data;
	struct stack * next;
} stack;

void push(stack **, char);
char pop(stack **);
int empty(stack *);

int main(int argc, char * argv[])
{
	char ch;
	stack * s;

	while ((ch = getchar()) != '\n')
	{
		push(&s, ch);
	}

	while (!empty(s))
	{
		putchar(pop(&s));
	}
	putchar('\n');

	return EXIT_SUCCESS;
}

int empty(stack * top)
{
	return top == NULL;
}

void push(stack **top, char val)
{
	stack *node = (stack *)malloc(sizeof(stack));

	if (node == NULL)
	{
		printf("Nema memorija!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		node->data = val;
		if (empty(*top))
		{
			node->next = NULL;
		}
		else
		{
			node->next = *top;
		}
		*top = node;
	}
}

char pop(stack **top)
{
	if (empty(*top))
	{
		printf("Provalija!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		stack *tmp = *top;
		char val = tmp->data;
		*top = tmp->next;
		free(tmp);
		return val;
	}
}
