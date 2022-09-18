// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Infix to Postfix"


// Precedence
// 1. ()
// 2. ^	 	R - L
// 3 / *	L - R
// 4. + -	L - R
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define size 200

char stack[size];
int top = -1;

// ***01***
void push(char value)
{
	if (top >= size - 1)
	{
		printf("\n********Stack Overflow**********");
	}
	else
	{
		top = top + 1;
		stack[top] = value;
	}
}

// ***02***
char pop()
{
	char value;

	if (top < 0)
	{
		printf("*******Stack under flow********");
		getchar();
		exit(1);
	}
	else
	{
		value = stack[top];
		top = top - 1;
		return (value);
	}
}

// ***03***
int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// ***04***
int precedence(char symbol)
{
	if (symbol == '^') 
	{
		return (3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return (2);
	}
	else if (symbol == '+' || symbol == '-') // lowest precedence
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// Pass the Operand
// Push Operator into stack and check precedence of existing operator in stack
// If precedence is higher then simply push the operator.
// In precedence is lower then pop out last element of stack and then check again
// if precedence is same then check assciativity (R-L or L-R). 
	// In (L-R) pop out last element of stack and then check again
	// In (R-L) simply push operator in stack
// if ( comes then simply push it in stack
// if ) comes then we pop out each element from stack until ( is found. 

// ***05***
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char value;
	char x;

	push('(');
	strcat(infix_exp, ")");

	i = 0;
	j = 0;
	value = infix_exp[i];

	while (value != '\0')
	{
		if (value == '(')
		{
			push(value);
		}
		else if (isdigit(value) || isalpha(value))
		{
			postfix_exp[j] = value;
			j++;
		}
		else if (is_operator(value) == 1)
		{
			x = pop();
			while (is_operator(x) == 1 && precedence(x) >= precedence(value))
			{
				postfix_exp[j] = x;
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
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;

		value = infix_exp[i];
	}

	postfix_exp[j] = '\0';
}

// ----------------------Main----------------------
int main()
{
	char infix[size], postfix[size];

	printf("\n*********Infix to Postfix (By Sheham Hassan [B20103070])********\n");

	printf("\nEnter Infix Expression: ");
	gets(infix);

	InfixToPostfix(infix, postfix);

	printf("\nPostfix Expression: ");
	puts(postfix);
	printf("\n\n");

	return 0;
}