#include <stdio.h>
#include <conio.h>

// *************************************SELECION SORT************************************
int main()
{
    // -----------------------Input Elements of Array------------------------
    int size, choice;

    printf("\nEnter Number of Element: ");
    scanf("%d", &size);
    printf("\n");

    int arr[size];

    for (int x=0; x<size; x++)
    {
        printf("Enter value of index %d element: ", x);
        scanf("%d", &arr[x]);
    }

    printf("Press\n\t0 to sort array in Ascending Order\n\t1 to sort array in Descending Order\n");
    scanf("%d", &choice);


// ----------------------------Sorting an Array---------------------------

    int i, j, temp;
    int minIndex = 0;

    for (i=0; i<size-1; i++)
    {
        minIndex = i;
        for (j=i+1; j<size; j++)
        {
            // Ascending Order
            if (arr[minIndex] > arr[j] && choice == 0)
            {
                minIndex = j;
            }
            // Descending Order
            if (arr[minIndex] < arr[j] && choice == 1)
            {
                minIndex = j;
            }
         }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

    }

// ----------------------------Printing an array------------------------------------------

printf("\n---------Sorted Array----------\n");
for (int k=0; k<size; k++)
{
    printf("%d  ", arr[k]);
}

    return 0;
}