#include <stdio.h>

int sumInter(int n) {
    int sum=0; //O(1):vì khai bao sum;
    for(int i=1;i<=n;i++) { //O(n): vì nó chạy giá trị từ 1 tới n;
        sum+=i; //O(1):vì nó chỉ là sum + thêm giá trị i;
    }
    return sum;
    /*kết luận là: độ phức tạp của thời gian là O(n);
                   độ phức tạp của không gian là O(1);
     */
}

int arithmeticProgression(int n) {
    if (n<1)
        return 0;
    int S;
    return S=n * (n+1) / 2; //O(1):vì nó chỉ cần tính toán;
    /*kết luận là: độ phức tạp của thời gian là O(1);
                   độ phức tạp của không gian là O(1);
     */
}

int main() {
    int n=10;
    int S1,S2;

    S1 = sumInter(n);
    S2 = arithmeticProgression(n);

    printf("S1 = %d\n", S1);
    printf("S2 = %d\n", S2);

}