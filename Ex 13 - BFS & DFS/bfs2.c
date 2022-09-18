// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Breadth First Search"


#include <stdio.h>
#include <stdlib.h>

// Queue implementation in C

#define SIZE 100
int items[SIZE], front = -1, rear = -1;

void enQueue(int value)
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        // printf("\nInserted -> %d", value);
    }
}

void deQueue()
{
    if (front == -1)
        printf("\nQueue is Empty!!");
    else
    {
        // printf("\nDeleted : %d", items[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to print the queue
void displayQ()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}

// -----------------------------------------

// Vertex Node
struct Vertex
{
    int data;
    struct Vertex *nextVertex;
    struct Edge *edgeList;
};

// Vertex Edge
struct Edge
{
    struct Vertex *ver; // data
    struct Edge *nextEdge;
};

struct Vertex *start = NULL;

int createVertex(int a)
{
    struct Vertex *tmp = (struct Vertex *)malloc(sizeof(struct Vertex));
    tmp->data = a;

    tmp->nextVertex = NULL;
    tmp->edgeList = NULL;

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct Vertex *cur = start;
        while (cur->nextVertex != NULL)
        {
            cur = cur->nextVertex;
        }
        cur->nextVertex = tmp;
    }
}

int insertEdgeUndir(int a, int b)
{
    struct Vertex *cur1 = start;
    int flag = 0;
    while (cur1 != NULL)
    {
        if (a == cur1->data)
        {
            struct Vertex *cur2 = start;
            while (cur2 != NULL)
            {
                if (b == cur2->data)
                {
                    struct Edge *tmp = (struct Edge *)malloc(sizeof(struct Edge));
                    flag = 1;

                    tmp->ver = cur2;
                    tmp->nextEdge = NULL;
                    if (cur1->edgeList == NULL)
                    {
                        cur1->edgeList = tmp;
                    }
                    else
                    {
                        struct Edge *cur3 = cur1->edgeList;
                        while (cur3->nextEdge != NULL)
                        {
                            cur3 = cur3->nextEdge;
                        }

                        cur3->nextEdge = tmp;
                    }

                    struct Edge *tmp2 = (struct Edge *)malloc(sizeof(struct Edge));

                    tmp2->ver = cur1;
                    tmp2->nextEdge = NULL;
                    if (cur2->edgeList == NULL)
                    {
                        cur2->edgeList = tmp2;
                    }
                    else
                    {
                        struct Edge *cur3 = cur2->edgeList;
                        while (cur3->nextEdge != NULL)
                        {
                            cur3 = cur3->nextEdge;
                        }

                        cur3->nextEdge = tmp2;
                    }
                }
                cur2 = cur2->nextVertex;
            }
        }
        cur1 = cur1->nextVertex;
    }
    if (flag == 0)
    {
        printf("Vertex not found");
    }
}

int printGraph()
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        printf("\nList of vertex %d", curr->data);
        printf("\nHead: ");

        struct Edge *cur2 = curr->edgeList;
        while (cur2 != NULL)
        {
            printf("%d", cur2->ver->data);
            printf(" -> ");
            cur2 = cur2->nextEdge;
        }
        curr = curr->nextVertex;
        printf("\n");
    }
}

// --------------------------------------------------------------------
#define sz 7
int visited[sz];

int bfs()
{
    for (int i = 0; i < sz; i++)
    {
        visited[i] = 9;
    }

    // struct Vertex *qf;
    int k = 0;
    struct Vertex *curr = start;
    // printf("\nList of vertex %d", curr->data);
    // printf("\nHead: ");
    int j = 0;
    while (j <= 1)
    {
        printf("A");
        curr = start;
        while (curr != NULL)
        {
            // printf("%d", k);
            if (k == curr->data)
            {
                curr = curr;
                break;
            }
            curr = curr->nextVertex;
        }
        printf("**%d\n", curr->data);
        struct Edge *cur2 = curr->edgeList;
        while (cur2 != NULL)
        {

            int flagV = 0;
            // printf("%d", cur2->ver->data);
            // printf(" -> ");

            for (int i = 0; i < sz; i++)
            {
                if (visited[i] == cur2->ver->data)
                    flagV = 1;
            }

            if (flagV == 0)
            {
                enQueue(cur2->ver->data);
            }
            cur2 = cur2->nextEdge;
        }

        visited[j] = curr->data;
        k = items[front]; // first element of queue
        deQueue();
        j++;
    }

    for (int i = 0; i < sz; i++)
    {
        printf("%d", visited[i]);
    }

    displayQ();
}

int main(int argc, char const *argv[])
{
    createVertex(0);
    createVertex(1);
    createVertex(2);
    createVertex(3);
    createVertex(4);
    createVertex(5);
    createVertex(6);

    insertEdgeUndir(0, 1);
    insertEdgeUndir(0, 2);
    insertEdgeUndir(0, 3);
    insertEdgeUndir(1, 2);
    insertEdgeUndir(2, 3);
    insertEdgeUndir(2, 4);
    insertEdgeUndir(3, 4);
    insertEdgeUndir(4, 5);
    insertEdgeUndir(4, 6);

    printGraph();
    bfs();

    return 0;
}
