#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #define Size 10
int Size = 10;
int arr[10];
int indx = 0;

// Parent = floor((i-1)/2)
// Left Child = 2i + 1
// Right Child =  2i + 2
void insert()
{
    // int index = 0;
    while (indx < Size)
    {
        int elem;
        printf("\n");
        printf("Enter the element you want in your heap\n");
        scanf("%d", &elem);
        if (indx != Size)
        {
            arr[indx++] = elem;
            int lastUpdated = arr[indx - 1];
            int i = indx - 1;
            while (lastUpdated > arr[(int)floor((i - 1) / 2)])
            {
                int swap = arr[(int)floor((i - 1) / 2)];
                arr[i] = swap;
                arr[(int)floor((i - 1) / 2)] = lastUpdated;
                i = floor((i - 1) / 2);
            }
        }
        else
        {
            printf("Array Full");
        }

        for (int i = 0; i < Size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}

int *heapify(int arr[Size], int src)
{
    printf("Hi4\n");
    int childRight = (2 * src) + 2;
    int childLeft = (2 * src) + 1;
    while (src < Size)
    {
        printf("Hi5\n");
        int swap;
        if (arr[src] < arr[childLeft] && childLeft < Size)
        {
            swap = arr[src];
            arr[src] = arr[childLeft];
            arr[childLeft] = swap;
            if (arr[src] < arr[childRight] && childRight < Size)
            {
                swap = arr[src];
                arr[src] = arr[childRight];
                arr[childRight] = swap;
                src = childRight;
            }
            src = childLeft;
        }
        else if (childRight < Size && arr[src] < arr[childRight])
        {
            swap = arr[src];
            arr[src] = arr[childRight];
            arr[childRight] = swap;
            src = childRight;
        }
        else
        {
            src = childLeft;
        }

        childRight = (2 * src) + 2;
        childLeft = (2 * src) + 1;
    }
    return arr;
}
void delete ()
{
    int todel;
    printf("Enter the element that you want to delete\n");
    scanf("%d", &todel);
    for (int i = 0; i < Size; i++)
    {
        if (arr[i] == todel)
        {
            printf("Hi1\n");
            int swap = arr[i];
            arr[i] = arr[Size - 1];
            Size = Size - 1;
            printf("Hi2\n");
            heapify(arr, i);
            printf("Hi3\n");
            break;
        }
    }

    for (int i = 0; i < Size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main(int argc, char const *argv[])
{

    int choice = -1;
    while (choice != 0)
    {
        printf("Enter \n1.To insert \n2.To del\n1");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        if (choice == 2)
        {
            delete ();
        }
    }
}