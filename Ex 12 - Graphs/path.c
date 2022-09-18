// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Path"


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Vertex *root = NULL;

struct Edge
{
    int data;
    struct Vertex *vertex;
    struct Edge *edgeNext;
};

struct Vertex
{
    int data;
    struct Vertex *vertexNext;
    struct Edge *edgeRoot;
};
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

void InsertVertex(int data)
{

    struct Vertex *newVertex;
    newVertex = (struct Vertex *)malloc(sizeof(struct Vertex));
    newVertex->data = data;
    newVertex->vertexNext = NULL;
    newVertex->edgeRoot = NULL;

    if (root == NULL)
    {

        root = newVertex;
    }

    else
    {

        struct Vertex *currVertex = root;

        while (currVertex->vertexNext != NULL)
        {
            currVertex = currVertex->vertexNext;
        }
        currVertex->vertexNext = newVertex;
    }
}
void InsertEdge(int tosearch, int number, int toaddVertex)
{

    struct Edge *newEdge;
    struct Vertex *Vertex = root;
    struct Vertex *AddVertex = root;

    struct Vertex *searchedVertex;
    struct Vertex *searchedVertexOfAdd;
    while (AddVertex != NULL)
    {
        if (toaddVertex == AddVertex->data)
        {
            searchedVertexOfAdd = AddVertex;
            break;
        }
        else
        {
            AddVertex = AddVertex->vertexNext;
        }
    }

    newEdge = (struct Edge *)malloc(sizeof(struct Edge));
    newEdge->edgeNext = NULL;
    newEdge->data = number;
    newEdge->vertex = searchedVertexOfAdd;
    while (Vertex != NULL)
    {
        if (tosearch == Vertex->data)
        {
            searchedVertex = Vertex;
            break;
        }
        else
        {
            Vertex = Vertex->vertexNext;
        }
    }

    if (searchedVertex->edgeRoot == NULL)
    {
        searchedVertex->edgeRoot = newEdge;
    }
    else
    {
        struct Edge *curr = searchedVertex->edgeRoot;
        while (curr->edgeNext != NULL)
        {
            curr = curr->edgeNext;
        }
        curr->edgeNext = newEdge;
    }
}
void PrintEdge(int toSearchVertex)
{
    struct Vertex *Vertex = root;
    struct Vertex *tempVertex;
    while (Vertex != NULL)
    {
        if (Vertex->data == toSearchVertex)
        {
            tempVertex = Vertex;
            break;
        }
        else
        {
            Vertex = Vertex->vertexNext;
        }
    }

    struct Edge *curr = tempVertex->edgeRoot;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->edgeNext;
    }
}
void PrintVertex()
{
    struct Vertex *curr = root;

    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->vertexNext;
    }
}

void findPath(int fromNumber, int toNumber)
{
    int flag = 0;
    struct Vertex *Vertex = root;
    while (Vertex != NULL)
    {
        if (Vertex->data == fromNumber)
        {
            Vertex = Vertex;
            break;
        }
        else
        {
            Vertex = Vertex->vertexNext;
        }
    }
    push1(fromNumber);
    struct Edge *edgeList = Vertex->edgeRoot;
    struct Edge *search = edgeList;
    while (edgeList != NULL)
    {

        while (search != NULL)
        {
            if (search->data == toNumber)
            {

                push1(search->data);
                flag = 1;
                break;
            }
            else
            {
                search = search->edgeNext;
            }
        }
        if (flag == 1)
        {
            break;
        }

        struct Vertex *tempVertex = edgeList->vertex;
        push(edgeList);
        push1(edgeList->data);
        edgeList = tempVertex->edgeRoot;
        search = edgeList;
        if (edgeList == NULL)
        {
            edgeList = pop();
            pop1();
            if (edgeList->edgeNext != NULL)
            {
                edgeList = edgeList->edgeNext;
                search = edgeList;
            }
            else
            {
                edgeList = pop();
                pop1();
                edgeList = edgeList->edgeNext;
                search = edgeList;
            }
        }
    }
    if (flag == 0)
    {
        printf("Not Found\n");
    }
}

int main()
{

    int choose;
    int i = 0;
    printf("1: Insert\n2: Exit\n3: Print\n4: Insert Edge\n5: Print Edge\n6: Find Path\n");
    while (i <= 1)
    {
        printf("Choose the function: ");
        scanf("%d", &choose);
        if (choose == 1)
        {
            int number;
            printf("Enter the number: ");
            scanf("%d", &number);
            InsertVertex(number);
        }
        if (choose == 2)
        {
            printf("Your Program is finished");
            break;
        }
        if (choose == 3)
        {
            PrintVertex();
        }
        if (choose == 4)
        {
            int toSearchInVertex;
            printf("Enter the Vertex in which you want to add: ");
            scanf("%d", &toSearchInVertex);
            int toSearchAddVertex;
            printf("Enter the Vertex you want to add: ");
            scanf("%d", &toSearchAddVertex);
            int number;
            printf("Enter the Edge data: ");
            scanf("%d", &number);

            InsertEdge(toSearchInVertex, number, toSearchAddVertex);
        }
        if (choose == 5)
        {
            int toSearch;
            printf("Enter the vertex of which you want to print Edge List: ");
            scanf("%d", &toSearch);
            PrintEdge(toSearch);
        }
        if (choose == 6)
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
                printf("%d\n", arr[l]);
            }
        }
    }
}