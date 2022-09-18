// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Undirected Graph"

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
int insertEdge()
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

int inDegreeVer()
{
    int degVer;
    int flag = 0;
    int degree = 0;
    printf("Enter vertex for degree: ");
    scanf("%d", &degVer);
    struct Vertex *curr = start;

    while (curr != NULL)
    {
        struct Edge *cur2 = curr->edgeList;
        while (cur2 != NULL)
        {
            // if (curr->data == degVer)
            // {
            //     degree += 1;
            // }
            if (cur2->ver->data == degVer)
            {
                degree += 1;
            }
            cur2 = cur2->nextEdge;
        }
        curr = curr->nextVertex;
        // printf("\n");
    }
    printf("\nInDegree of %d: %d", degVer, degree);
}

int outDegreeVer()
{
    int degVer;
    int flag = 0;
    int degree = 0;
    printf("Enter vertex for degree: ");
    scanf("%d", &degVer);
    struct Vertex *curr = start;

    while (curr != NULL)
    {
        struct Edge *cur2 = curr->edgeList;
        while (cur2 != NULL)
        {
            if (curr->data == degVer)
            {
                degree += 1;
            }
            // else if (cur2->ver->data == degVer)
            // {
            //     degree += 1;
            // }
            cur2 = cur2->nextEdge;
        }
        curr = curr->nextVertex;
        // printf("\n");
    }
    printf("\noutDegree of %d: %d", degVer, degree);
}

// --------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    printf("\n*********Graphs********\n");
    int i = 0;
    while (i != 6)
    {
        printf("\n1. CreateVertex\t2. CreateEdge\t3. PrintGraph\t4. inDegree\t5. outDegree\t6. Exit");
        printf("\nEnter: ");
        scanf("%d", &i);

        if (i == 1)
        {
            createVertex();
        }
        if (i == 2)
        {
            insertEdge();
        }
        if (i == 3)
        {
            printGraph();
        }
        if (i == 4)
        {
            inDegreeVer();
        }
        if (i == 5)
        {
            outDegreeVer();
        }
    }

    return 0;
}
