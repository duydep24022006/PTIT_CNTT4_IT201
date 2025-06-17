#include <stdio.h>

void printDouble(int n){
    int i; //  O(1):khởi tạo biến;
    while (i<n) {   // Vòng lặp while này sẽ tiếp tục chạy miễn là i còn nhỏ hơn n
                    // Sau mỗi lần lặp, i được nhân đôi (i *= 2)
                    // Các giá trị của i sẽ là: 1, 2, 4, 8, 16, ..., < n
                    // Do đó, số lần lặp khoảng log2(n) => độ phức tạp thời gian là O(log n)

        printf("%d\n",i);// O(1):vì in ra giá trị hiện tại của biến i;
        i*=2;//O(1):nhân đôi giá trị của i;
    }
    //độ phức tạp thời gian của bài này là O(log n);
}
