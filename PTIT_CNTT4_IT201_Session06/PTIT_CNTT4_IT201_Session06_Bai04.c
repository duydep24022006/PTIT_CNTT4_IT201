#include <stdio.h>

void moveDisks(int n, char from, char to, char temp);

int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }

    moveDisks(n, 'A', 'C', 'B');  // A: cột nguồn, C: cột đích, B: cột tạm
    return 0;
}

void moveDisks(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("dia 1 di chuyen tu %c sang %c\n", from, to);
        return;
    }
    moveDisks(n - 1, from, temp, to);
    printf("dia %d di chuyen tu %c sang %c\n", n, from, to);
    moveDisks(n - 1, temp, to, from);
}
