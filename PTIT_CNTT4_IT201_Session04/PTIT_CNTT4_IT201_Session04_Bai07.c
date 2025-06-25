#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr,n;
    printf("n = ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for (int i=0;i<n/2;i++)
    {
        if (arr[i]==arr[n-1-i]) printf("cap doi xung:(%d,%d)\n", arr[i],arr[i]);

    }
    free(arr);
    return 0;
}


