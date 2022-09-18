#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int data;
    struct vertex * next;
    struct edge * edgelist;
};

struct edge
{
    struct edge * next;
    struct vertex * v;
};

struct vertex * Graph = NULL;

void addVertex()
{
    printf("\n//// Adding a vertex ////\n");
    struct vertex * temp = (struct vertex*)malloc(sizeof(struct vertex));
    int data;
    printf("Enter the data that you want your vertex to hold\n");
    scanf("%d" , &data);
    temp->data = data;
    temp->edgelist = NULL;
    temp->next = NULL;
    if(Graph == NULL)
    {
        Graph = temp;
    }
    else
    {
        struct vertex * current = Graph;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void displayVertex()
{
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

void addEdge()
{
    int vertex1;
    int vertex2;
    printf("Adjecnt From?:\t");
    scanf("%d" , &vertex1);
    printf("Adjecnt to?:\t");
    scanf("%d" , &vertex2);
    struct vertex * current = Graph;
    while(current != NULL)
    {
        if(current->data == vertex1)
        {
            struct vertex * current2 = Graph;
            struct vertex * Avertex2;
            while(current2 != NULL)
            {
                if(current2 ->data == vertex2)
                {
                    Avertex2 = current2;
                    struct edge * temp = (struct edge*)malloc(sizeof(struct edge));
                    temp->v = Avertex2;
                    temp->next = NULL;
                    if(current->edgelist == NULL)
                    {
                        current->edgelist = temp;
                    }
                    else
                    {
                        struct edge * current3 = current->edgelist;
                        while(current3->next != NULL)
                        {
                            current3 = current3->next;
                        }
                        current3->next = temp;
                    }
                    break;
                }
                current2 = current2->next;
            }
            break;
        }
        current = current->next;
    }
}

void findOutDegree()
{
    int data;
    int count = 0;
    printf("Enter the data you want to find the Outdegree of\n");
    scanf("%d" , &data);
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        if(current->data == data)
        {
            struct edge * current2 = current->edgelist;
            while(current2!=NULL)
            {
                count = count+1;
                current2 = current2->next;
            }
            break;
        }
        current = current->next;
    }
    printf("The out degree of %d is %d" , data , count);
}

void findInDegree()
{
    int data;
    int count = 0;
    printf("Enter the data you want to find the Indegree of\n");
    scanf("%d" , &data);
    struct vertex* current = Graph;
    while(current!= NULL)
    {
        struct  edge* current2 = current->edgelist;
        while(current2 != NULL)
        {
            if(current2->v->data == data)
            {
                count = count +1;
                break;
            }
            current2 = current2->next;
        }
        current = current->next;
    }
    printf("The indegree of %d is %d" , data , count);

}

void displayEdges()
{
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        printf("\n%d\n" , current->data);
        if(current->edgelist!=NULL)
        {
            struct edge * current2 = current->edgelist;
            printf("The neighbours are");
            while(current2!=NULL)
            {
                printf("\t%d\t->" , current2->v->data);
                current2 = current2->next;
            }
        }
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    int choice = -1;
    while(choice!= 0)
    {
        printf("\nEnter \n1.To add \n2.To Display \n3.Add Edge \n4.Display Edges \n5.OutDegree \n6.Indegree \n0.Exit\n");
        scanf("%d" , &choice);
        if(choice == 1)
        {
            addVertex();
        }
        if(choice == 2)
        {
            displayVertex();
        }
        if(choice == 3)
        {
            addEdge();
        }
        if(choice == 4)
        {
            displayEdges();
        }
        if(choice == 5)
        {
            findOutDegree();
        }
        if(choice == 6)
        {
            findInDegree();
        }
    }
    return 0;
}