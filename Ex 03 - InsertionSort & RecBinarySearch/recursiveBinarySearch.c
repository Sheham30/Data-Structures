#include <stdio.h>


int recursiveSearch(int left, int right, int arr[], int search);

int main() {
    // BINARY SEARCH ALGORITHM
  
// ------------------------Input Elements-------------------------- 
    int toSearch, size;
    int flag = 0;
    
    printf("Enter Size of array: ");
    scanf("%d", &size);
    
    int ary[size];
    
    for (int k=0; k<size; k++)
    {
        printf("Enter index %d element: ", k );
        scanf("%d", &ary[k]);
    }
    
    // ------------------------Searching Code------------------------ 

    printf("Enter a number to Search: ");
    scanf("%d", &toSearch);
    
    int l = 0;
    int r = size-1;
    // int mp = (l+r)/2;

    int ans =  recursiveSearch(l, r, ary, toSearch);

    if (ans == -1)  printf("Value Not found");

    else    printf("Value %d found at index %d", toSearch, ans);

    return 0;
}


// -----------------------------Function--------------------------------

int recursiveSearch(int left, int right, int arr[], int search)
{
    int midPoint = (right+left)/2;

    if (left > right)   return -1;

    if (search == arr[midPoint])    return ("%d", midPoint);
    
    if (search < arr[midPoint]) {
        right = midPoint - 1;
        return recursiveSearch(left, right, arr, search);
    }
    if (search > arr[midPoint]) {
        left = midPoint + 1;
        return recursiveSearch(left, right, arr, search);
    } 
    // return 0;
}

