#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,average,count , *arr;
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
        average =0;
        count=0;
        for(int i=0;i<n;i++)
        {
            if (arr[i]%2==0)
            {
                average +=arr[i];
                count++;
            }
        }
        printf("average  = %d \n",average/count );
    }
    return 0;

}
