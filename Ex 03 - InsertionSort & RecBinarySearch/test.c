#include<stdio.h>

int Rbinarysearch(int l, int h, int key);
void printArray(int* array, int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d ", array[i]);
    }
}

int Rbinarysearch(int l, int h, int key){
    int array[]={11,22,25,29,32,35,37,56,74,101};
    int length= sizeof(array)/sizeof(array[0]);
    l=0; 
    h=length-1;
    printf("Your array is:\n");
    printArray(array, length);
    printf("enter key value:%d", key);
    scanf("%d", &key);
    if(l==h)
    {
        if(array[l]==key)
        {
            return l;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int mid= (l+h)/2;
        if(array[mid]==key)
        {
            return mid;
        }
        if(array[mid]<key)
        {
            return Rbinarysearch(mid+1,h,key);
        }
        else
        {
            return Rbinarysearch(l,mid-1,key);

        }

    }
}