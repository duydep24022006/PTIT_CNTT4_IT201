#include <stdlib.h>

int mallocArray(int n) {
    int* arr=(int*)malloc(sizeof(int)*n); // O(n):vì nó cần cấp phát ô nhớ cho n số nguyên;
    for(int i=0;i<n;i++) {//O(n):vì nó lặp để gán giá trị từ 1 tới n-1;
        arr[i]=i;//O(1):vì nó chỉ cần gán giá trị i vào mảng;
    }
    return arr;
    //tổng kết thì độ phức tạp không gian của nó là O(n);
}
