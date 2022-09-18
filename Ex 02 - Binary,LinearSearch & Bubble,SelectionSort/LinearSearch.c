#include <stdio.h>

int main() {
    // LINEAR SEARCH ALGORITHM

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
    
// ------------------------Searching Code----------------------------------------

    printf("Enter a number to Search: ");
    scanf("%d", &toSearch);
    
    for (int i=0; i<size; i++)
    {
        if (toSearch==ary[i])
        {
            printf("\n\nNumber %d is found at Index %d", toSearch, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Value %d Not Found", toSearch);
    }

    return 0;
}