#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)
#define NUM 10

int find_min(double array[], int n) {
    int min = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[min]) {
            min = i;
        }
    }
    return min;
}

int main(void) {
    double array[NUM];
    
    for(int i = 0; i < NUM; i++) {
        scanf("%lf",&array[i]);
    }

    for(int i = NUM; i > 1; i--) {
        int min = find_min(array,i);
        if(min != (i - 1)) {
            swap(double,array[min],array[i-1]);
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("%lf ",array[i]);
    }

    puts("");

    return 0;
}