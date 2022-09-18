// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Postfix Evaluation"

#include <stdio.h>
#include <ctype.h>

#define MaxStack 100 
#define PostfixSize 100 

int stack[MaxStack];
int top = -1; 

void push(int item)
{

    if (top >= MaxStack - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

void eval_Postfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (ch == '^' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            A = pop();
            B = pop();

            switch (ch) 
            {
            case '^':
                val = B^A;
                break;
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
            }

            push(val);
        }
    }
    printf("\nResult of expression evaluation is : %d \n", pop());
}

int main()
{

    int i;

    char postfix[PostfixSize];
    printf(" \nEnter postfix expression,\n\n\tPress right parenthesis ')' for end expression: ");

    for (i = 0; i <= PostfixSize - 1; i++) {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')') 
        {
            break;
        } 
    }


    eval_Postfix(postfix);

    return 0;
}