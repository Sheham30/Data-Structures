// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Expression Trees"


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#include <math.h>

#define size 100
#define POSTFIXSIZE 100

int top = -1;
char stack[size];

void push(char value)
{
    if (top >= size - 1)
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

void EvalPostfix(char postfix_Arr[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix_Arr[i] != ')'; i++)
    {
        ch = postfix_Arr[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;

            case '^':
                // val = pow(B, A);
                val = B^A;
                break;
            }

            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{

    int i;

    char postfix_Arr[POSTFIXSIZE];
    printf(" \nEnter postfix_Arr expression,\n\tPress right parenthesis ')' for end expression : ");

    for (i = 0; i <= POSTFIXSIZE - 1; i++)
    {
        scanf("%c", &postfix_Arr[i]);

        if (postfix_Arr[i] == ')')
        {
            break;
        }
    }

    EvalPostfix(postfix_Arr);

    return 0;
}