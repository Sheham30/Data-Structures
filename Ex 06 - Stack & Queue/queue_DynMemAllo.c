#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int enQueue()
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a number to insert: ");
    scanf("%d", &tmp->data);
    
    tmp->next = NULL;
    
    if (rear == NULL){
        rear = tmp;
        front = tmp;
    }
    else {
        rear->next = tmp;
        rear = rear->next;
    }

} 

int delQueue(){
    if (front == NULL){
        printf("Stack Underloaded");
    }
    else{
        struct Node *cur = front;
        front = front->next;
        free(cur);
    }
}

int print() {
    struct Node *curr =  front;
    
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

// ------------------------------------
int main()
{
    printf("***Queue****");
    int a;
    while (a != 4) {
        printf("\nEnter\n1. enQueue\t2. delQueue\t3. print\t4. Exit");
        scanf("\n%d", &a);
        if (a == 1) {
            enQueue();
        }
        if (a == 2) {
            delQueue();
        }
        if (a == 3) {
            print();
        }
    }
    
    return 0;
}