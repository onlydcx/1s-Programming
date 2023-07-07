#include <drawlib.h>
#include <math.h>
#include <stdio.h>

int main(void) {
    dl_initialize(1.0);
    while(1) {
        dl_stop();
        dl_clear(DL_C("black"));
        dl_resume();
        dl_wait(0.01);
    }
    return 0;
}