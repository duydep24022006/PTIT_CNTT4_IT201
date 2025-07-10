#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int top;
    int size;
}StackInt;
StackInt *createStackInt(int size) {
    StackInt *s = (StackInt *)malloc(sizeof(StackInt));
    s->top = -1;
    s->size = size;
    s->data=(int *)malloc(size*sizeof(int));
    return s;
}
void pushInt(StackInt *s, int data) {
    if (s->top==s->size-1) {
        printf("Stack day\n");2vw 7ui8539c6o
        return;
    }
    s->data[++s->top] = data;
}
int popInt(StackInt *s) {
    if (s->top==-1) {
        printf("Stack trong\n");
        return 0;
    }
    return s->data[s->top--];
}
int check(char *s) {
    int count=0,countNum=0;
    for (int i=0; i<strlen(s); i++) {
        if (!((s[i]>='0' && s[i]<='9')||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')) {
            printf("Khong hop le\n");
            return 0;
        }
        if (s[i]>='0' && s[i]<='9') {
            countNum++;
        }else {
            count++;
        }
    }
    if (count+1==countNum) {
        return 1;
    }
    printf("Khong hop le\n");
    return 0;
}
int total(int firstNum,int secondNum,char sign) {
    if (sign=='+') {
        return firstNum+secondNum;
    }
    if (sign=='-') {
        return firstNum-secondNum;
    }
    if (sign=='*') {
        return firstNum*secondNum;
    }
    if (sign=='/'&&secondNum!=0) {
        return firstNum/secondNum;
    }else {
        printf("Khong chia cho 0");
        exit(0);
    }
}
int postfix(char *s) {
    if (!check(s)) {
        return 0;
    }
    StackInt *forTotal = createStackInt(strlen(s));
    for (int i=0; i<strlen(s); i++) {
        if (isdigit(s[i])) {
            pushInt(forTotal, s[i]-'0');
        }else {
            int a=popInt(forTotal),b=popInt(forTotal);

            pushInt(forTotal,total(b,a,s[i]));
        }
    }
    return popInt(forTotal);
}
int main() {
    char x[100];
    printf("Nhap vao chuoi: ");
    fflush(stdin);
    fgets(x, 100, stdin);
    x[strcspn(x, "\n")]='\0';
    if (strlen(x)==0) {
        printf("Danh sach trong");
        return 0;
    }
    printf("postfix: %d",postfix(x));
    return 0;
}