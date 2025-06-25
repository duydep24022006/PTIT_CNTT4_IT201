#include <stdio.h>
#include <stdlib.h>

int mainAndSecondaryDiagonal(int **arr,int n,int *mainDiagonal,int *secondaryDiagonal);

int main(){
    int rows,cols,mainDiagonal=0,secondaryDiagonal=0;
    printf("rows = ");
    scanf("%d",&rows);
    printf("cols = ");
    scanf("%d",&cols);

    if((rows<=0 || rows>1000) && (cols<=0 || cols>1000)){
        printf("so cot va hang khong hop le\n");
    }
    else if(rows<=0)
    {
        printf("so hang khong hop le\n");
    }else if(cols<=0)
    {
        printf("so cot khong hop le\n");
    }else if(rows!=cols)
    {
        printf("khong tin tai duong cheo chinh \n khong ton tai duong cheo phu");
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
        mainAndSecondaryDiagonal(arr,rows,&mainDiagonal,&secondaryDiagonal);

        printf("tong duong cheo chinh = %d\n",mainDiagonal);
        printf(" tong duong cheo phu = %d",secondaryDiagonal);

        free(arr);
        free(data);
    }

    return 0;

}
int mainAndSecondaryDiagonal(int **arr,int n,int *mainDiagonal,int *secondaryDiagonal)
{
    for(int i=0;i<n;i++)
    {

        int j=n-1-i;
        *mainDiagonal += arr[i][i];
        *secondaryDiagonal += arr[i][j];
    }
    return 1;
}