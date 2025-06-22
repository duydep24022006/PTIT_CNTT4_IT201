#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows,cols,maxValue,minValue;
    printf("rows = ");
    scanf("%d",&rows);
    printf("cols = ");
    scanf("%d",&cols);

    if(rows<0 && rows==0 || cols<0 && cols==0){
        printf("so cot va hang khong hop le\n");
    }
    else if(rows<0 && rows==0)
    {
        printf("so hang khong hop le\n");
    }else if(cols<0 && cols==0)
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
        maxValue=arr[0][0];
        minValue=arr[0][0];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if (maxValue<arr[i][j]) maxValue=arr[i][j];
                if (minValue>arr[i][j]) minValue=arr[i][j];
            }
        }
        printf("max = %d \n min = %d",maxValue,minValue);
        free(arr);
        free(data);
    }

    return 0;

}
