#include <stdio.h>
#include <conio.h>

// ***********************INSERSION SORTING***********************************
int main()
{
// ---------------------Input Elements of array----------------------------
    int size;

    printf("Enter number of Elements in an array: ");
    scanf("%d", &size);

    char arr[size];

    for (int i=0; i<size; i++)
    {
        printf("Enter element %d of array: ", i);
        scanf("%d", &arr[i]);
    }

// ------------------------Sorting an Array------------------------------------
    int current, i, j;

    for (i=1; i<size; i++)
    {
        current = arr[i];
        j = i - 1;

        while (arr[j] > current && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = current;
    }


// ---------------------Printing an array----------------------------
    printf("\nSorted Array\n");
    for (int j=0; j<size; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}