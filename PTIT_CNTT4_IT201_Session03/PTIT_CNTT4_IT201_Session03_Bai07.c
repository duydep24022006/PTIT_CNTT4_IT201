#include <stdio.h>
#include <stdlib.h>

int sumRowsFun(int **arr,int n,int k);


int main(){
    int rows,cols,k,sumRows;
    printf("rows = ");
    scanf("%d",&rows);
    printf("cols = ");
    scanf("%d",&cols);

    if(rows<=0 && cols<=0){
        printf("so cot va hang khong hop le\n");
    }
    else if(rows<=0)
    {
        printf("so hang khong hop le\n");
    }else if(cols<=0)
    {
        printf("so cot khong hop le\n");
    }
    else
    {
        int **arr=(int **)malloc(rows * sizeof(int*));
        int *data=(int *)malloc(rows * cols * sizeof(int));
        for(int i=0;i<rows;i++)
        {
            arr[i]=data+ i *cols;
        }
        printf("moi ban nhap gia tri cho mang: \n");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                printf("[%d] [%d]: " ,i,j);
                scanf("%d",&arr[i][j]);
            }
        }
        printf("k = ");
        scanf("%d",&k);
        if (k>rows-1||k<0)
        {
            printf("hang tinh khong hop le");
        }else
        {
            sumRows=sumRowsFun(arr,cols,k);
            printf("sum = %d\n",sumRows);

        }
        free(arr);
        free(data);
    }

    return 0;
}
int sumRowsFun(int **arr,int n,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[k-1][i];
    }
    return sum;
}
