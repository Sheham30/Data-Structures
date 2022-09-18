#include <stdio.h>

int size;
int setPivot(int L, int R, int arr[])
{
    // L = 0;
    // R = size - 1;
    int pivIn = (L+R)/2;
    int pivot = arr[pivIn];
    int temp;
    
    while (L < R)
    {
        while (pivot != arr[R]){
            if (pivot > arr[R])
            {
                // Swap
                temp = arr[pivIn];
                arr[pivIn] = arr[R];
                arr[R] = temp;
                
                pivot = arr[R];
                pivIn = R;
                break;
            }
            else {
                R--;
            }
        }

        while (pivot != arr[L])
        {   
            if (pivot < arr[L])
            {
                // Swap
                temp = arr[pivIn];
                arr[pivIn] = arr[L];
                arr[L] = temp;
                
                pivot = arr[L];
                pivIn = L;
                break;
            }
            else {
                L++;
            }           
        }
    }
    
    return pivIn;
}

int quickSort(int Lf, int Rt, int ar[])
{    
    if (Lf < Rt){
        int pi = setPivot(Lf, Rt, ar);

        quickSort(Lf, pi-1, ar);    
        quickSort(pi+1, Rt, ar);   
    }
}

int main()
{
    printf("******************Quick Sort*****************");
    // int size;
    printf("\nEnter size of array: ");
    scanf("%d", &size);
    int arr[size];
    
    for (int i=0; i<size; i++){
        printf("Enter %d value: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("*************Unsorted Array***********\n");
    for (int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    
    printf("\n");
    
    int left = 0;
    int right = size-1;

    quickSort(left, right, arr);

    printf("*************Sorted Array***********\n");
    for (int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}

