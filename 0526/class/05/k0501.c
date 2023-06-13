#include <stdio.h>
#include <math.h>
#include <drawlib.h>

#define N 3

double cx = DL_WIDTH / 2;
double cy = DL_HEIGHT / 2;
double r = 50.0;
double ox = 0;
double oy = 0;
double t = 0.0;

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    t += 0.01;
    if (t > 2 * M_PI) t == 0.0;
    ox = cx + r * cos(t);
    oy = cy + r * sin(t);
    dl_line(ox+x1, oy+y1, ox+x2, oy+y2, DL_C("white"), 1);
    dl_line(ox+x2, oy+y2, ox+x3, oy+y3, DL_C("white"), 1);
    dl_line(ox+x3, oy+y3, ox+x1, oy+y1, DL_C("white"), 1);
}

int main(void) {

    float wait_time = 0.01;

    double p[N][3][2] = {
        {{0,0}, {0,50}, {50,0}},
        {{5,5}, {5,55}, {55,5}},
        {{10,10}, {10,60}, {60,10}},
    };

    dl_initialize(1.0);

    while (1) {
        dl_stop();
        dl_clear(DL_C("black"));

        for(int i = 0; i < N; i++) {
            draw_triangle(p[i][0][0],p[i][0][1],p[i][1][0],p[i][1][1],p[i][2][0],p[i][2][1]);
        }

        dl_resume();
        dl_wait(wait_time);        
    }
    return 0;
}
