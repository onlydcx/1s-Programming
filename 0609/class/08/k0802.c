#include <stdio.h>

int fibo(int n) {
    if(n < 2) return n;
    else return fibo(n - 1) + fibo(n - 2);
}

int main(void) {
    for(int i = 0; i < 10; i++) {
        printf("%d ",fibo(i));
    }
    printf("\n");
    return 0;
}