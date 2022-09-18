// Name: Syed Sheham Hassan
// Seat Number: B20103070
// Content: "Adjacency Matrix"

#include <stdio.h>
#define V 10
int arr[][];

// Initialize the matrix to zero
void init(int arr[V][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[][V], int i, int j)
{
    int weight;
    printf("Enter the weight\n");
    scanf("%d", &weight);
    arr[i][j] = weight;
    arr[j][i] = weight;
}

// Print the matrix
void printAdjMatrix(int arr[][V])
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[V][V];

    init(adjMatrix);
    int choice = -1;
    while (choice != 0)
    {
        printf("Select\n 1.To add Edge \n2.Print");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int vertex1;
            int vertex2;
            printf("Enter the first vertex\n");
            scanf("%d", &vertex1);
            printf("Enter the second vertex\n");
            scanf("%d", &vertex2);
            addEdge(adjMatrix, vertex1, vertex2);
        }
        if (choice == 2)
        {
            printAdjMatrix(adjMatrix);
        }
    }
}