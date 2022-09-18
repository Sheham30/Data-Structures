#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

int insert()
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value to insert: ");
    scanf("%d", &tmp->data);

    tmp->next = start;

    if (start == NULL)
    {
        start = tmp;
        tmp->next = start;
    }
    else
    {
        struct Node *curr = start;

        while (curr->next != start)
        {
            curr = curr->next;
        }
        curr->next = tmp;
        tmp->next = start;
    }
}

// Method 1
// void print()
// {
//     struct Node *cur = start;

//     printf("%d\n", start);  // OR printf("%d\n", curr);

//     while (cur->next != start)
//     {
//         printf("%d\n", cur->data);
//         printf("%d\n", cur->next);
//         cur = cur->next;
//     }

//     printf("%d\n", cur->data);
//     printf("%d\n", cur->next);
// }

// Method 2     (Follow this one)
void print()
{
    struct Node *cur = start;
    struct Node *newCur = cur;

    printf("%d\n", start); // OR printf("%d\n", curr);

    do
    {
        printf("%d\n", newCur->data);
        printf("%d\n", newCur->next);
        newCur = newCur->next;
    } while (newCur != start);
}

void search()
{
    int s, i = 0, flag = 0;
    struct Node *serCur = start;
    printf("Enter number to search: ");
    scanf("%d", &s);

    while (serCur->next != start)
    {
        if (serCur->data == s)
        {
            printf("Number %d Found at index %d", serCur->data, i);
            flag = 1;
            break;
        }
        i++;
        serCur = serCur->next;
    }
    if (flag == 0 && serCur->data == s)
    {
        printf("Number %d Found at index %d", serCur->data, i);
        flag = 1;
    }
    else if (flag == 0)
    {
        printf("Not Found");
    }
}

int delete ()
{
    struct Node *prev = start;
    struct Node *cur;
    struct Node *curr = cur;
    int delValue;

    printf("Enter a number to delete: ");
    scanf("%d", &delValue);

    if (delValue == start->data)
    {
        start = start->next;
        free(prev);
    }
    else
    {
        curr = start->next;
        prev = start;

        do
        {
            if (delValue == curr->data)
            {
                prev->next = curr->next;
                free(curr);
                break;
            }
            curr = curr->next;
            prev = prev->next;
        } while (curr != start);
    }
}

int main()
{
    int a;
    printf("************Circular Linked List**************\n");

    while (a != 5)
    {
        printf("\nPress\t1. insert\t2. Print\t3. Search\t4. Delete\t5. Exit\nEnter: ");
        scanf("%d", &a);

        if (a == 1)
        {
            insert();
        }
        if (a == 2)
        {
            print();
        }
        if (a == 3)
        {
            search();
        }
        if (a == 4)
        {
            delete ();
        }
    }

    return 0;
}
