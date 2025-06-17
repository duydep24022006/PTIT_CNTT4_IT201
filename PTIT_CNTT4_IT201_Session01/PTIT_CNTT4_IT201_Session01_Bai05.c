void bubbleSort(int arr[], int n) {
    for (int i=0; i < n; i++) {//O(n):vì nó chạy từ 0 tới n phần tử;
        int flag = 0; //O(1):vì khai báo biến;
        for (int j=0; j < n; j++) { //O(n):vì nó chạy từ 0 tới n phần tử;
            if (arr[j] > arr[j+1]) {//O(1):vì nó chỉ so sánh kết quả;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;

            }
        }
        if (flag == 0)break;
    }
}

/*
 *-độ phức tạp thoiwf gian:
 * th1 :O(n):khi hàm đã đc xắp xếp đc xác định bởi cắm cờ flag;
 * th2:O(n^2):khi mà hàm chưa đc xắp xếp;
 * -độ phức tạp không gian là O(1);
 */