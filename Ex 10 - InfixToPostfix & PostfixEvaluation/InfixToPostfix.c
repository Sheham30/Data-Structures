#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>

#define size 100
int top = -1;
char stack[size];

void push(char value)
{
	if (top >= size-1)
	{
		printf("\n**Stack Overflow**\n");
	}
	else
	{
		top++;
		stack[top] = value;
	}
}

char pop()
{
	char a;

	if (top < 0)
	{
		printf("\n**Stack Underflow**\n");
		getchar();
		exit(1);
	}
	else
	{
		a = stack[top];
		top--;
		// stack[top] = 0;
		return a;
	}
}

// int printStack()
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d\t", stack[i]);
// 	}
// }

int operator(char opr)
{
	if (opr == '^' || opr == '*' || opr == '/' || opr == '+' || opr == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char symbol)
{
	if (symbol == '^')
		return 3;

	else if (symbol == '/' || symbol == '*')
		return 2;

	else if (symbol == '+' || symbol == '-')
		return 1;

	else
		return 0;
}

void InfixToPostfix(char infix_Arr[], char postfix_Arr[])
{
	int i, j;
	char value;
	char x;

	push('(');
	strcat(infix_Arr, ")");

	i = 0;
	j = 0;
	value = infix_Arr[i];

	while (value != '\0') // loop will stop when array value is 0
	{
		if (value == "(")
		{
			push(value);
		}
		else if (isdigit(value) || isalpha(value))
		{
			postfix_Arr[j] = value;
			j++;
		}

		else if (operator(value) == 1)
		{
			x = pop();
			while (operator(x) == 1 && precedence(x) >= precedence(value))
			{
				postfix_Arr[j] = x;
				j++;
				x = pop();
			}
			push(x);

			push(value);
		}

		else if (value == ')')
		{
			x = pop();
			while (x != '(')
			{
				postfix_Arr[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("Invalid Infix Expression");
			getchar();
			exit(1);
		}

		i++;
		value = infix_Arr[i];
	}

	postfix_Arr[j] = "\0";
}

int main()
{
	char infix[size];
	char postfix[size];

	printf("\n********Infix to postfix******");

	printf("\nEnter Infix expression: ");
	gets(infix);

	InfixToPostfix(infix, postfix);

	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}
