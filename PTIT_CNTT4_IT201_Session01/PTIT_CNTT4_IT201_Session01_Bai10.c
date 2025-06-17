#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_RANGE 256


bool isAnagram_Counting(const char *str1, const char *str2) {
    // Nếu độ dài khác nhau thì chắc chắn không phải hoán vị
    if (strlen(str1) != strlen(str2)) return false;

    int count[CHAR_RANGE] = {0};//O(256):vì nó chưa 256 phàn tử


    for (int i = 0; str1[i]; i++) {//O(n):vì mảng này nó chạy từ 0 tới n phàn tử của mảng
        count[(unsigned char)str1[i]]++;
    }


    for (int i = 0; str2[i]; i++) {//O(n):vì mảng này nó chạy từ 0 tới n phàn tử của mảng
        count[(unsigned char)str2[i]]--;
    }


    for (int i = 0; i < CHAR_RANGE; i++) {//O(n):vì mảng này nó chạy từ 0 tới n phàn tử của mảng
        if (count[i] != 0) return false;
    }

    return true;
}
/*-độ phức tạp thời gian là O(n):vì O(n) + O(n) + O(256) → O(n);
* -độ phức tạp không gian là O(1);
*/

int main() {
    char str1[100];
    char str2[100];

    printf("Moi ban nhap chuoi dau tien\n");
    fgets(str1, sizeof(str1), stdin);
    printf("Moi ban nhap chuoi thu hai\n");
    fgets(str2, sizeof(str2), stdin);

    if (isAnagram_Counting(str1 ,str2) == true ) {
        printf("True\n");
    }else {
        printf("False\n");
    }

}