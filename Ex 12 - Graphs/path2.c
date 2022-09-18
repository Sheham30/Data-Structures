// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Path"

#include <stdio.h>
#include <stdlib.h>

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
    // int data;
    struct Vertex *ver; // data
    struct Edge *nextEdge;
};

struct Vertex *start = NULL;

int createVertex()
{
    struct Vertex *tmp = (struct Vertex *)malloc(sizeof(struct Vertex));
    printf("Enter a vertex name: ");
    scanf("%d", &tmp->data);

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

int insertEdgeUndir()
{
    int a;
    int b;
    printf("Enter 1st vertex: ");
    scanf("%d", &a);
    printf("Enter 2nd vertex: ");
    scanf("%d", &b);

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


// ------------------------------------------------

int top1 = 0;
int top = 0;
struct Edge *Stack[10];
int arr[10];
void push1(int data)
{
    if (top1 == 10)
    {
        printf("Array Overflow\n");
    }
    else
    {
        arr[top1] = data;
        top1++;
    }
}
void pop1()
{
    if (top == 0)
    {
        printf("Array Underflow\n");
    }
    else
    {
        top1--;
        arr[top1] = 0;
    }
}
void push(struct Edge *edgeList)
{

    if (top == 10)
    {
        printf("Overflow");
    }
    else
    {
        Stack[top] = edgeList;
        top++;
    }
}
struct Edge *pop()
{
    struct Edge *edge;
    if (top == 0)
    {
        printf("UnderFlow");
    }
    else
    {
        top--;
        edge = Stack[top];
    }
    return edge;
}

// ------------------------------------------------
void findPath(int fromNumber, int toNumber)
{
    int flag = 0;
    struct Vertex *Vertex = start;
    while (Vertex != NULL)
    {
        if (Vertex->data == fromNumber)
        {
            Vertex = Vertex;
            break;
        }
        else
        {
            Vertex = Vertex->nextVertex;
        }
    }
    push1(fromNumber);
    struct Edge *edgeList = Vertex->edgeList;
    struct Edge *search = edgeList;
    while (edgeList != NULL)
    {

        while (search != NULL)
        {
            if (search->ver->data == toNumber)
            {

                push1(search->ver->data);
                flag = 1;
                break;
            }
            else
            {
                search = search->nextEdge;
            }
        }
        if (flag == 1)
        {
            break;
        }

        struct Vertex *tempVertex = edgeList->ver;
        push(edgeList);
        push1(edgeList->ver->data);
        edgeList = tempVertex->edgeList;
        search = edgeList;
        if (edgeList == NULL)
        {
            edgeList = pop();
            pop1();
            if (edgeList->nextEdge != NULL)
            {
                edgeList = edgeList->nextEdge;
                search = edgeList;
            }
            else
            {
                edgeList = pop();
                pop1();
                edgeList = edgeList->nextEdge;
                search = edgeList;
            }
        }
    }
    if (flag == 0)
    {
        printf("Not Found\n");
    }
}


// --------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    printf("\n*********Graphs********\n");
    int i=0;
    while (i != 7)
    {
        printf("\n1. CreateVertex\t2. CreateEdge\t3. CreateUndirEdge\t4. PrintGraph\t5. Degree\t6. Exit");
        printf("\nEnter: ");
        scanf("%d", &i);

        if (i == 1)
        {
            createVertex();
        }
        if (i == 2)
        {
            // insertEdge();
        }
        if (i == 3)
        {
            insertEdgeUndir();
        }
        if (i == 4)
        {
            printGraph();
        }
        if (i == 5)
        {
            // degreeVer();
        }
        if (i == 6)
        {
            int fromNumber;
            printf("Enter the starting number: ");
            scanf("%d", &fromNumber);
            int toNumber;
            printf("Enter the Ending number: ");
            scanf("%d", &toNumber);

            findPath(fromNumber, toNumber);
            for (int l = 0; l < 10; l++)
            {
                if (arr[l] == 0)
                {
                    break;
                }
                printf("%d\n", arr[l]);
            }
        }
    }
    
    return 0;
}

