#include <stdio.h>

#define MAX 100

typedef struct {
    int value;
    int count;
}Element;


int findIndex(Element stats[], int size,int value) {
    for (int i = 0; i < size; i++) { //O(n):vì vòng lặp này chạy từ 0 tới n giá trị ;
        if (stats[i].value == value) {
            return i; //O(1):vì chỉ câần trả về giá trị ngay lập tức.
        }

    }
    return -1;//O(1):vì chỉ câần trả về giá trị ngay lập tức.
}
void finDuplicates(int arr[], int n) {
    Element stats[MAX];
    Element statsMax[MAX];
    int countMax = 1;
    int size = 0;
    for (int i = 0; i < n; i++) { //O(n):vì vòng lặp này chạy từ 0 tới n giá trị ;
        int index = findIndex(stats, size,arr[i]); //O(n):vì khi gội  hàm này bên tộng cũng phaải duyêt qua các ggias trị từ 0 tới n;
        if (index == -1) {
            stats[size].value = arr[i];
            stats[size].count = 1;
            size++;

        }else {
            stats[index].count++;
            if (countMax<stats[index].count) {
                statsMax[0].value = stats[index].value;
                statsMax[0].count = stats[index].count;
                countMax=stats[index].count;
            }
        }
    }
    printf("Gia tri %d xuat hien %d lan\n", statsMax[0].value, statsMax[0].count);
    //Gia tri 2 xuat hien 3 lan

}
/*-độ phức tạp thời gian là O(n^2);
* -độ phức tạp không gian là O(1);
*
*/

int main() {
    int arr[]={1,2,4,2,54,3,67,2,4,3};
    finDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
}