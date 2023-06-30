#include <stdio.h> 
#include <float.h>

#define NUM 10

void calc_max_min_ave(const double *array, int n, double *max, double *min, double *ave) {
    *max = -DBL_MAX;
    *min = DBL_MAX;
    *ave = 0.0;

    for (int i = 0; i < n; i++) {
        if (array[i] > *max) {
            *max = array[i];
        }
        else if (array[i] < *min) {
            *min = array[i];
        }
        *ave += array[i];
    }
    *ave /= n;
}

int main(void) {
    double values[NUM] = {4.3, 3.3, 8.2, 2.5, 4.6, 5.1, 8.4, 2.2, 9.2, 1.3}; 
    double max, min, ave;
    calc_max_min_ave(values, NUM, &max, &min, &ave);
    printf("最大値: %f\n", max);
    printf("最小値: %f\n", min);
    printf("平均値: %f\n", ave);
    return 0;
}