#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTACK 100
int top = -1;

struct node
{
    char elem;
    struct node *leftchild;
    struct node *rightchild;
};

struct node *stack[MAXSTACK];
int isOperand(char ch)
{

    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
struct node *push(struct node *node)
{
    stack[++top] = node;
    return stack;
}
struct node *pop()
{
    return (stack[top--]);
}
void preorder(struct node *Node)
{
    if (Node != NULL)
    {
        printf("%c", Node->elem);
        preorder(Node->leftchild);
        preorder(Node->rightchild);
    }
}

void Inorder(struct node *Node)
{

    if (Node != NULL)
    {
        Inorder(Node->leftchild);
        printf("%c", Node->elem);
        Inorder(Node->rightchild);
    }
}

// incase of operand, push the node into stack, declare right and left child as null
// incase of operatpr, pop two nodes from stack and decclare them as their right and left child
void postfixExpressiontree(char *ch)
{
    int len = (strlen(ch));
    for (int i = 0; i < len; i++)
    {
        if (isOperand(ch[i]))
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->elem = ch[i];
            temp->leftchild = NULL;
            temp->rightchild = NULL;
            push(temp);
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->elem = ch[i];
            temp->rightchild = pop();
            temp->leftchild = pop();
            push(temp);
        }
    }
}
int main(int argc, char const *argv[])
{
    char exp[50];
    printf("Enter Infix Expression : ");
    gets(exp);
    postfixExpressiontree(exp);

    Inorder(stack[top]);
}

