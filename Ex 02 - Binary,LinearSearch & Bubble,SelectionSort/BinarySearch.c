#include <stdio.h>

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
    
    int left = 0;
    int right = size-1;
    int midPoint;

    while (left<=right)
    {
        midPoint = (right+left)/2;
        
        if (toSearch == ary[midPoint])
        {
            printf("Number %d found at Index %d", toSearch, midPoint);
            flag = 1;
            break;
        }
        else if (toSearch < ary[midPoint])
        {
            right = midPoint - 1;
        }
        else
        {
            left = midPoint + 1;
        }
        
    }
    
     if (flag == 0)
        {
            printf("Value not found");           
        }
    
    
    return 0;
}
