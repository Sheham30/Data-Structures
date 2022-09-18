#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char value;
    struct Node *next;
};
struct start
{
    struct Node *st;
};
int size = 5;
struct start chain[5];

int insert()
{
    char toadd;
    int key;
    printf("Enter the number that you want to add in your hashmap\n");
    scanf("%s", &toadd);
    printf("Enter key: ");
    scanf("%d", &key);
    // key = toadd % size;
    // key = 0;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = toadd;
    temp->next = NULL;

    if (chain[key].st == NULL)
    {
        chain[key].st = temp;
        key++;
    }
    else
    {
        struct Node *current = chain[key].st;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        key++;
    }
}

void print()
{
    int i = 0;
    printf("\n");
    while (i < size)
    {
        if (chain[i].st != NULL)
        {
            // printf("%d->", chain[i].st->value);

            // struct Node *current = chain[i].st->next;
            struct Node *current = chain[i].st;
            while (current != NULL)
            {

                // if (current != NULL)
                // {
                // printf("hi\n");
                printf("%c->", current->value);
                // }
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

void printBigInt()
{
    int i = 0;
    printf("\n");
    while (i < size)
    {
        if (chain[i].st != NULL)
        {
            // printf("%d", chain[i].st->value);
            char num[5] = {};
            struct Node *current = chain[i].st;
            while (current != NULL)
            {
                strncat(num, &current->value, 1);
                // printf("%c", current->value);
                current = current->next;
            }
            printf("\n%s    (At index %d)", num, i);

        }
        // printf("\n");
        i++;
    }
}

void addBigInt(int ind1, int ind2)
{
    int i = 0;
    int j, k;
    printf("\n");
    while (i < size)
    {
        if (chain[i].st != NULL)
        {
            // printf("%d", chain[i].st->value);
            char num[5] = {};
            struct Node *current = chain[i].st;

            while (current != NULL)
            {
                strncat(num, &current->value, 1);

                current = current->next;
            }
            // printf("%s", num);
            // converting string into integer
            if (i == ind1) {
                j = atoi(num);
            }
            if (i == ind2) {
                k = atoi(num);
            }
        }
        i++;
    }
    printf("Sum of %d and %d: %d", j, k, j+k);
    printf("\nProduct of %d and %d: %d", j, k, j*k);
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
        printf("\n\nEnter \n\t1.Insert \t2.PrintHashmap \t3. PrintBigInt\t4. Add/Multiply BigInt\t0. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        if (choice == 2)
        {
            print();
        }
        if (choice == 3)
        {
            printBigInt();
        }
        if (choice == 4)
        {
            int a;
            int b;
            printf("Enter first index: ");
            scanf("%d", &a);
            printf("Enter second index: ");
            scanf("%d", &b);
            addBigInt(a, b);
        }
    }
}

// To Convert integer into String
// itoa(number,string,10);