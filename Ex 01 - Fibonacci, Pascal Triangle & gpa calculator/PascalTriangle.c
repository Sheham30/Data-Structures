#include <stdio.h>

int main()
{
    int i, j, space, num, ncr;

    printf("Enter the Number: ");
    scanf("%d", &num);

    for (i=0; i<=num; i++)
    {
        for (space=num; space>=i; space--)
        {
            printf(" ");
        }
        for (j=0; j<=i; j++)
        {
            if (j==0 || i==0)
            {
                ncr = 1;
                printf("%d ", ncr);
            }
            else
            {
                ncr = ncr*(i-j+1)/j;
                printf("%d ", ncr);
            }

        }
        printf("\n");
    }

    return 0;
}


/*
    int i, j, k;

    for (i=1; i<=5; i++)
    {
        for (k=5; k>=i; k--)
        {
            printf(" ");
        }
        for (j=1; j<=i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
*/
