#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,*arr,k,flag=-1;
    printf("n = ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("k = ");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        if (k==arr[i])
        {
            flag=1;
            printf("%d,",i);

        }
    }
    if(flag==-1)
    {
       printf("phan tu khong co trong mang\n");
    }
    free(arr);
    return 0;
}
