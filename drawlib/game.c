#include <drawlib.h>
#include <stdio.h>

#define rgb(r,g,b) dl_color_from_rgb(r,g,b)
#define w DL_WIDTH
#define h DL_HEIGHT

#define debug

void draw_back(void) {
    dl_line(0, h-50, w/2-30, 30, rgb(127,127,127), 1);
    dl_line(w, h-50, w/2+30, 30, rgb(127,127,127), 1);
    dl_line(w/7, h, w/2-20, 30, rgb(127,127,127), 1);
    dl_line(w-w/7, h, w/2+20, 30, rgb(127,127,127), 1);
    dl_line(w/7*2, h+50, w/2-10, 30, rgb(127,127,127), 1);
    dl_line(w-w/7*2, h+50, w/2+10, 30, rgb(127,127,127), 1);
    dl_line(w/7*3, h+100, w/2-5, 30, rgb(127,127,127), 1);
    dl_line(w-w/7*3, h+100, w/2+5, 30, rgb(127,127,127), 1);
}

void draw_bar(int id) {
    int lineX[6] = {0,90,195,280,360,548,w};
    dl_rectangle(lineX[2],h-2,lineX[3],h-5,rgb(255,255,0),1,1);
}

int main(void) {
    dl_initialize(1.0);
    float wait_time = 0.01;
    int cnt = 0;

    while(1) {
        cnt++;
        if(cnt > h) cnt = 0;

        dl_stop();
        dl_clear(DL_C("black"));

        draw_back();

        // dl_line(180, h+100, w/2-5, 30, rgb(127,127,127), 1);
        // dl_line(w-180, h+100, w/2+5, 30, rgb(127,127,127), 1);


        draw_bar(2);

        dl_circle(w/2, cnt, 10, dl_color_from_name("red"), 1, 1);
        dl_resume();
        dl_wait(wait_time);

    }
    return 0;
}
