#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void insert(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}

int display()
{
    for (int i=0; i<MAX; i++)
    {
        printf("%d\t", intArray[i]);
    }
}
// ---------------------------------------

int main()
{


    printf("\n***********Queue (Array)**********");
    int j;
    while (j != 4)
    {
        printf("\nEnter\n   1. enQueue     2. deQueue      3. Print       4. Exit\n");
        scanf("%d", &j);

        if (j == 1){
            int i;
            printf("\nEnter a value to Enqueue: ");
            scanf("%d", &i);
            insert(i);
        }
        if (j == 2){
            removeData();
        }
        if (j == 3){
            display();
        }
    }
    return 0;
}