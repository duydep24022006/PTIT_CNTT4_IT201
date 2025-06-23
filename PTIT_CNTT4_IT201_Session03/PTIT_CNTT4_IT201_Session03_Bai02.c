#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,maxValue, *arr;
    printf("n= ");
    scanf("%d",&n);
    if(n<0){
        printf("so luong phan tu khong duoc am\n");
    }
    else if(n==0)
    {
        printf("so luong phan tu phai lon hon 0\n");
    }else if (n>1000){
        printf("so luong phan tu cua ban khong dc qua 1000 phan tu\n");
    }
    else
    {
        arr=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        maxValue=arr[0];
        for(int i=0;i<n;i++)
        {
            if (maxValue<arr[i])
            {
                maxValue=arr[i];
            }
        }
        printf("max = %d \n",maxValue);
    }
    return 0;

}
