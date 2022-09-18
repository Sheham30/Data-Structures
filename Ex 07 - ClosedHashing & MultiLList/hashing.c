#include <stdio.h>
#include <stdlib.h>

// int size = 10;
#define size 5
int arr[size];

int printArray()
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int inputArray()
{
    int a, b, c, flag = 0;
    printf("\nEnter a number to input: ");
    scanf("%d", &a);
    c = 0;
    b = a % size;

    while (arr[b] != 0)
    {
        b = b + 1;
        b = b % size;
        c += 1;

        if (c == (size - 1))
        {
            flag = 1;
            printf("\nArray is full");
            break;
        }
    }
    if (flag == 0)
    {
        arr[b] = a;
    }
}

int main()
{
    printf("\n**********Hashing*********\n");
    int x;
    while (x != 3)
    {
        printf("\nEnter\n1. Input\t2. Print\t3. Exit\n");
        scanf("%d", &x);

        if (x == 1)
        {
            inputArray();
        }
        if (x == 2)
        {
            printArray();
        }
    }

    return 0;
}
