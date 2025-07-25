#include<stdio.h>
#include<stdlib.h>

int countEdge(int** matrix, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1) count++;
        }
    }
    return count / 2;
}

int main(){
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    int **matrix = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) matrix[i] = (int*)malloc(n*sizeof(int));
    printf("Nhap ma tran ke:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int numEdge = countEdge(matrix, n);
    printf("%d", numEdge);
    return 0;
}