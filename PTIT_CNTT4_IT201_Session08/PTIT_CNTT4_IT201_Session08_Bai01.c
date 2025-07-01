#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int n,int number);

int main()
{
       int n ,*arr,k;
       printf("n = ");
       scanf("%d",&n);
       if(n<=0||n>1000) return 0;
       arr=(int*)malloc(n*sizeof(int));
       for (int i=0;i<n;i++) scanf("%d",&arr[i]);
       printf("k = ");
       scanf("%d",&k);
       int resuch= linearSearch( arr, n,k);
       if (resuch!=-1) printf("vi tri thu %d",resuch);
       else printf("khong ton tai phan tu");
       free(arr);
       return 0;
}

int linearSearch(int arr[],int n,int number)
{
       for (int i=0;i<n;i++)
       {
              if (number==arr[i]) return i;
       }
       return -1;
}
