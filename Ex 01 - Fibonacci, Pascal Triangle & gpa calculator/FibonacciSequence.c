#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Display a Fibonacci Sequence
int main()
{
    int entry;
    int a = 0;
    int b = 1;
    int z;

    printf("Enter the total number of series: ");
    scanf("%d", &entry);

    while (entry != 0) {
        printf("\n%d", a);
        z = a + b;
        b = a;
        a = z;

        entry -= 1;
    }

    return 0;
}


