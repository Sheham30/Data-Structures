#include <stdio.h>
#include <stdlib.h>


struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};
struct DLLNode *start = NULL;

int insert()
{
    struct DLLNode *tmp = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    int a;

    printf("Enter a number to insert: ");
    scanf("%d", &tmp->data);

    tmp->next = NULL;
    tmp->prev = NULL;

    if (start == NULL) {
        start = tmp;
        // tmp->prev = NULL;
    }
    else {
        struct DLLNode *curr = start;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = tmp;
        tmp->prev = curr;
    }
}

int print()
{
    struct DLLNode *prCurr = start;

    while (prCurr != NULL)
    {
        printf("%d\n", prCurr->data);
        // prCurr->prev = prCurr;
        prCurr = prCurr->next;       
    }
}

int revPrint()
{
    struct DLLNode *prCurr = start;

    while (prCurr->next != NULL)
    {
        prCurr = prCurr->next;       
    }
    while (prCurr != NULL)
    {
        printf("%d\n", prCurr->data);
        prCurr = prCurr->prev;
    } 
}

int search()
{
    struct DLLNode *serCurr = start;
    int toSearch, i, flag=0;

    printf("\nEnter a number to search: ");
    scanf("%d", &toSearch);

    while (serCurr != NULL)
    {
        if (toSearch == serCurr->data) {
            printf("\nNumber %d Found at index %d\n",  toSearch, i);
            flag = 1;
            break;
        }
        serCurr = serCurr->next;       
        i++;
    }
    if (flag==0) {
        printf("Number %d Not Found",  toSearch);
    }
}

int delete()
{
    // struct DLLNode *prevv = start;
    struct DLLNode *cur;

    int toDelete;

    printf("\nEnter a number to delete: ");
    scanf("%d", &toDelete);

    if (toDelete == start->data) {
        start = start->next;
    }
    else
    {
        cur = start->next;
        // prev = start;

        while (cur != NULL)
        {
            if (toDelete == cur->data)
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                free(cur);
                break;
            }
            cur = cur->next;
            // prev = prevv->next;
        }
    }
}

// --------------------------------------------------------
int main()
{   
    int a;
    printf("************Double Linked List**************\n");

    while (a != 6)
    {
        printf("\nPress\t1. insert\t2. Print\t3. Reverse Print\t4. Search\t5. Delete\t6. Exit\nEnter: ");
        scanf("%d", &a);

        if (a == 1){
            insert();
        }
        if (a == 2){
           print();
        }
        if (a == 3){
            revPrint();
        }
        if (a == 4){
           search();
        }
        if (a == 5){
           delete();
        }
    }
    

    return 0;
}