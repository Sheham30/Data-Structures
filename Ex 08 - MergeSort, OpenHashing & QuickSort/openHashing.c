#include <stdio.h>
#include <stdlib.h>

#define size 5;
struct Node
{
    int value;
    struct Node *next;
};
struct Start
{
    struct Node *st;
};

struct Start *hashtable[size];

// for (int i = 0; i < size; i++)
// {
//     hashtable[i] = NULL;
// }

int inputArray()
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter a Number to insert: ");
    scanf("%d", &tmp->value);

    int h = tmp->value % size;

    printf(hashtable[h].st);
}

int main()
{
    // for (int i=0; i<size; i++){
    // hashtable[i] = NULL;
    // }

    inputArray();

    return 0;
}