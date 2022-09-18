#include <stdio.h>

// ***01***
void merge_sort(int ar[], int length)
{
    merge_sort_recursion(ar, 0, length - 1);
}

// ***02***
void merge_sort_recursion(int ar[], int l, int r) // (array, left, right)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // middle index

        merge_sort_recursion(ar, l, m);     // From first element to middle
        merge_sort_recursion(ar, m + 1, r); // From middle next element to last

        merge_sorted_arrays(ar, l, m, r); // sort splitted arrays
    }
}

// ***03***
void merge_sorted_arrays(int ar[], int l, int m, int r) // (array, left, middle, right)
{
    int leftLength = m - l + 1; // length of left array
    int rightLength = r - m;    // length of right array

    int tempLeft[leftLength];   // temporary left array
    int tempRight[rightLength]; // temporary right array

    int i, j, k;

    // Splitting Array
    // Copying first half of array in tempLeft
    for (int i = 0; i < leftLength; i++)
    {
        tempLeft[i] = ar[l + i];
    }

    // Copying second half of array in tempLeft
    for (int i = 0; i < rightLength; i++)
    {
        tempRight[i] = ar[m + 1 + i];
    }

    // --------Merging and Sorting both arrays----------------------

    for (i = 0, j = 0, k = l; k <= r; k++)
    // k will keep track of ar[]
    { // end of right and left arrays      // checking which arr has next smallest element
        if ((i < leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j]))
        {
            ar[k] = tempLeft[i];
            i++;
        }
        else
        {
            ar[k] = tempRight[j];
            j++;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("\n*****************Merge Sort**************\n");
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }

    return 0;
}
