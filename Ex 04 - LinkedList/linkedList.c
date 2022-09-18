#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;      // Node variable(object) 


int insert()
// Required 3 node variables start, tmp, curr
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node ));

    printf("Enter a value to insert: ");
    scanf("%d", &tmp->data);

    tmp->next = NULL;

    if (start == NULL) {
        start = tmp;
    }
    else {
        struct Node *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = tmp;
    }
} 

int print()
{
    struct Node *newCur = start;

    // printf("%d\n", newCur->data);
    while (newCur != NULL)
    {
        printf("%d\n", newCur->data);
        newCur = newCur->next;
    }
    // printf("%d\n", newCur->data);

    
}

int search()
{
    int sd, flag=0, i=0;
    printf("Enter a number to search: ");
    scanf("%d", &sd);

    struct Node *searchCur = start;
    
    while (searchCur != NULL)
    {
        if (sd == searchCur->data ){
            printf("\nFound at index %d", i);
            flag=1;
            break;
        }
        searchCur = searchCur->next;
        i++;
    }
    if (flag == 0) printf("\nNot Found");

    // if ((sd == searchCur->data) && (flag==0)){
    //         printf("\nFoundd at index %d", i);
    //         flag=1;
    //     }
    
}

int delete()
{
    struct Node *prev = start;
    struct Node *curr;
    int toDelete;

    printf("Enter number to delete: ");
    scanf("%d", &toDelete);

    if (toDelete == start->data) {
        start = start->next;
        free(prev);
    }
    else {
        curr = start->next;
        prev= start;

        while (curr != NULL)
        {
            if (toDelete == curr->data){
                prev->next = curr->next;
                free(curr);
                break;
            }
            curr = curr->next;
            prev = prev->next;
        }
    }
}

int main()
{   
    int a;
    printf("************Linked List**************\n");

    while (a != 5)
    {
        printf("\nPress\t1. insert\t2. Print\t3. Search\t4. Delete\t5. Exit\nEnter: ");
        scanf("%d", &a);

        if (a == 1){
            insert();
        }
        if (a == 2){
           print();
        }
        if (a == 3){
           search();
        }
        if (a == 4){
           delete();
        }
    }
    

    return 0;
}