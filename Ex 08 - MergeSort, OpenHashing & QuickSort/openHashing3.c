#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
struct start
{
    struct Node *st;
};
int size = 10;
struct start chain[10];

int insert()
{
    int toadd, key;
    printf("Enter the number that you want to add in your hashmap\n");
    scanf("%d", &toadd);
    key = toadd % size;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = toadd;
    temp->next = NULL;

    if (chain[key].st == NULL)
    {
        chain[key].st = temp;
    }
    else
    {
        struct Node *current = chain[key].st;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void print()
{
    int i = 0;
    while (i < size)
    {
        if (chain[i].st != NULL)
        {
            // printf("%d->", chain[i].st->value);

            struct Node *current = chain[i].st;
            while (current != NULL)
            {
                printf("%d->", current->value);

                current = current->next;
            }
        }
        else
        {
            printf("NULL->");
        }
        printf("\n");
        i++;
    }
}

int main()
{
    for (int i = 0; i < size; i++)
    {
        chain[i].st = NULL;
    }

    int choice;
    while (choice != 0)
    {
        printf("\nEnter \n1.Insert \n2.Print\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        if (choice == 2)
        {
            print();
        }
    }
}