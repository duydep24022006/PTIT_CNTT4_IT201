#include <stdio.h>
//c1
#define MAX_VALUE 1000  // Giới hạn giá trị phần tử trong mảng (giả sử < 1000)
#define MAX 100
void countOccurrences(int arr[], int n) {
    int frequency[MAX_VALUE] = {0}; // Mảng đếm tần suất, khởi tạo toàn 0

    // Duyệt mảng ban đầu → tăng đếm cho từng giá trị arr[i] → O(n)
    for (int i = 0; i < n; i++) { //O(n):vì vòng lặp duyệt qua từ 1 tới n phần tư;
        frequency[arr[i]]++;//nó côi arr[i] là index để tìm phần tử giống nhau
    }

    // In ra các phần tử xuất hiện (chỉ cần duyệt từ 0 → MAX_VALUE) → O(MAX_VALUE)
    for (int i = 0; i < MAX_VALUE; i++) {
        if (frequency[i] > 0) {
            printf("Phan tu %d xuat hien %d lan\n", i, frequency[i]);
            /*
                Phan tu 1 xuat hien 1 lan
                Phan tu 2 xuat hien 3 lan
                Phan tu 3 xuat hien 2 lan
                Phan tu 4 xuat hien 2 lan
                Phan tu 54 xuat hien 1 lan
                Phan tu 67 xuat hien 1 lan

             */
        }
    }
}
/*-độ phức tạp thời gian là O(n);
* -độ phức tạp không gian là O(1);
*/

//c2
typedef struct {
    int value;
    int count;
}Element;
int findIndex(Element stats[], int size,int value) {
    for (int i = 0; i < size; i++) {//O(n):vì vòng lặp này chạy từ 0 tới n giá trị ;
        if (stats[i].value == value) {
            return i; //O(1):vì chỉ câần trả về giá trị ngay lập tức.
        }

    }
    return -1;
}
void finDuplicates(int arr[], int n) {
    Element stats[MAX];
    int size = 0;
    for (int i = 0; i < n; i++) {
        int index = findIndex(stats, size,arr[i]);
        if (index == -1) {
            stats[size].value = arr[i];
            stats[size].count = 1;
            size++;

        }else {
            stats[index].count++;
        }


    }
    for (int i = 0; i < size; i++) {
        if (stats[i].count > 1) {
            printf("Gia tri %d xuat hien %d lan\n", stats[i].value, stats[i].count);
        }
    }
}
/*-độ phức tạp thời gian là O(n^2);
* -độ phức tạp không gian là O(1);
*/


int main() {
    int arr[]={1,2,4,2,54,3,67,2,4,3};
    countOccurrences(arr, sizeof(arr) / sizeof(arr[0]));
        finDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
}