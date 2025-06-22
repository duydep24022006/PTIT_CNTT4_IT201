#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *arr;
    printf("n= ");
    scanf("%d",&n);
    if(n<0){
        printf("so luong phan tu khong duoc am\n");
    }
    else if(n==0)
    {
        printf("so luong phan tu phai lon hon 0\n");
    }else
    {
        arr=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<n;i++) printf("so thu %d = %d \n",i,arr[i]);
    }
    return 0;

}
