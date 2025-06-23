#include <stdio.h>
#include <stdlib.h>

void renderArr(int arr[],int n);

int main(){
    int *arr,n,n2,m;
    printf("n = ");
    scanf("%d",&n);
    if (n<0||n>1000)
    {
        printf("so luong phan tu khong hop le \n");
        return 0;
    }
    arr=(int *)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return 1;
    }
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("m = ");
    scanf("%d",&m);
    if (m<=0)
    {
        renderArr(arr,n);
        free(arr);
        return 0;
    }
    n2=m+n;
    arr=(int *)realloc(arr,m*sizeof(int));
    if (arr == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return 1;
    }
    for(int i=n;i<n2;i++) scanf("%d",&arr[i]);
    renderArr(arr,n2);

    free(arr);
    return 0;

}

void renderArr(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
