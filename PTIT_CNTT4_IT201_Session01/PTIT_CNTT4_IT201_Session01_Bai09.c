#include <stdio.h>

int main() {
    int arr[5][5]={0,0};
    int n=5;

    printfArr( arr,n);

    mainDiagonal(arr,n);
}

void printfArr(int arr[5][5],int n) {
    printf("toan bo ma tran \n"); //O(1):vì nó chỉ cần hiện ra
    for (int i = 0; i < n; i++) { //o(n): vì vòng lặp này chạy ừ 0 tới n-1 giá trị
        for (int j = 0; j < n; j++) { //o(n): vì vòng lặp này chạy ừ 0 tới n-1 giá trị
            printf("%d ", arr[i][j]);//O(1):vì nó chỉ cần hiện ra
        }
        printf("\n");
    }
}
/*-độ phức tạp thời gian là O(n^2):vì có 2 vòng lặp lồng nhau nên nó là O(n)*O(n)=O(n^2);
* -độ phức tạp không gian là O(1);
*/

void mainDiagonal(int arr[5][5],int n) {

    printf("\n duong cheo chinh cua ma tran");//O(1):vì nó chỉ cần hiện ra
    for (int i = 0; i < n; i++) {//o(n): vì vòng lặp này chạy ừ 0 tới n-1 giá trị
        for (int j = 0; j < n; j++) {//o(n): vì vòng lặp này chạy ừ 0 tới n-1 giá trị
            if (i == j) { //kiểm tra giá trị i và j có bằng nhau không nn nó là O(1);
                printf("%d ", arr[i][j]);//O(1):vì nó chỉ cần hiện ra
            }
            else {
                printf(" ");//O(1):vì nó chỉ cần hiện ra
            }

        }
        printf("\n");
    }

}
/*-độ phức tạp thời gian là O(n^2):vì có 2 vòng lặp lồng nhau nên nó là O(n)*O(n)=O(n^2);
* -độ phức tạp không gian là O(1);
*/