#include <stdio.h>
#include <conio.h>

int main()
{
    // -----------------------Input Elements of Array------------------------
    int size, choice;

    printf("\nEnter Number of Element: ");
    scanf("%d", &size);
    printf("\n");

    int ary[size];

    for (int x = 0; x < size; x++)
    {
        printf("Enter value of index %d element: ", x);
        scanf("%d", &ary[x]);
    }

    printf("Press\n\t0 to sort array in Ascending Order\n\t1 to sort array in Descending Order\n");
    scanf("%d", &choice);

    bubbleSort(ary, size);

    printArray(ary, size);
}
// ----------------------------Sorting an Array---------------------------

int bubbleSort(int arr[], int size)
{

    // int size = sizeof(arr);
    int i, j, temp;
    int minIndex = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            // Ascending Order
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // return arr;
}
// ----------------------------Printing an array------------------------------------------

int printArray(int ar[], int size)
{
    printf("\n---------Sorted Array----------\n");
    for (int k = 0; k < size; k++)
    {
        printf("%d  ", ar[k]);
    }

}


