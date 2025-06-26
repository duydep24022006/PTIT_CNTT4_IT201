#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringToInt(char str[], int index, int len, int *valid);
int pow10(int n);

int main() {
    char input[100];
    int valid = 1;

    printf("Nhap chuoi so: ");
    scanf("%s", input);

    int len = strlen(input);
    int start = 0;
    int negative = 0;

    if (input[0] == '-') {
        negative = 1;
        start = 1;
    }

    int result = stringToInt(input, start, len, &valid);

    if (!valid) {
        printf("Input khong hop le\n");
    } else {
        if (negative) result = -result;
        printf("Output: %d\n", result);
    }

    return 0;
}
int stringToInt(char str[], int index, int len, int *valid) {
    if (index == len) return 0;  // cơ sở dừng

    if (!isdigit(str[index])) {
        *valid = 0;
        return 0;
    }

    int digit = str[index] - '0';
    int rest = stringToInt(str, index + 1, len, valid);

    return digit * pow10(len - index - 1) + rest;
}

int pow10(int n) {
    if (n == 0) return 1;
    return 10 * pow10(n - 1);
}