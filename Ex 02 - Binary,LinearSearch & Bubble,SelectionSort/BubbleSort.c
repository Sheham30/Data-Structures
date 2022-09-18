#include <stdio.h>
#include <conio.h>

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
        for (j=0; j<size-i-1; j++)
        {
            // Ascending Order
            if (arr[j] > arr[j+1] && choice == 0)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

            // Descending Order
            if (arr[j] < arr[j+1] && choice == 1)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

// ----------------------------Printing an array------------------------------------------

printf("\n---------Sorted Array----------\n");
for (int k=0; k<size; k++)
{
    printf("%d  ", arr[k]);
}

    return 0;
}