#include <stdio.h>
#include <stdlib.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};


void dfs(int d)
{
    int j;
    printf("%d", d);
    visited[d] = 1;
    
    for (j = 0; j < 7; j++)
    {
        if (a[d][j] == 1 && !visited[j])
        {
            dfs(j);
        }
    }
}

int main()
{
    dfs(0);
    return 0;
}