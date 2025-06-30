#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[],int left,int right);
void printMatrix(int **matrix,int rows,int cols);

int main(){
    int rows,cols,k;
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
        printf("k = ");
        scanf("%d",&k);
        if (k<=0||k>cols) return 0;
        printf("before: \n");
        printMatrix(arr,rows,cols);
        printf("\n");

        for (int j = 0; j <k; j++) {
            int col[rows];
            for (int i = 0; i < rows; i++) {
                col[i] = arr[i][j];
            }
            quickSort(col, 0, rows -1);
            for (int i = 0; i < rows; i++) {
                arr[i][j] = col[i];
            }
        }
        printf(" after: \n");
        printMatrix(arr,rows,cols);

        free(arr);
        free(data);
    }

    return 0;
}


void quickSort(int arr[],int left,int right)
{
    if (left>=right) return;
    int pivot = arr[(left+right)/2];
    int i=left, j=right;
    while (i<j)
    {
        while (arr[i]<pivot) i++;
        while (arr[j]>pivot) j--;
        if (i<=j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void printMatrix(int **matrix,int rows,int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
