
#include <stdio.h>
int dp[100][100]; // mảng nhớ

int countPaths(int i,int j,int m,int n)
{
    if (i>=m || j>=n) return 0;
    if (i==m-1 || j==n-1) return 1;

    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=countPaths(i+1,j,m,n)+countPaths(i,j+1,m,n);
    return dp[i][j];
}

int main()
{

    int m,n;
    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    if (m<0||n<0) return 0;


    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    int result = countPaths(0, 0, m, n);
    printf("%d", result);
    return 0;
}