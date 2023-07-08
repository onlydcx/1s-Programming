#include <drawlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define w DL_WIDTH
#define h DL_HEIGHT

void ufo() {
    int t, k, x, y;
    int item_x = 400;
    int cnt = 30;

    while(1) {
        if(dl_get_event(&t, &k, &x, &y) && (t == DL_EVENT_KEY) && (k == 'j')) {
            break;
        }
        
        int add = rand() % 20 + 1;
        cnt += add;
        printf("%d\n",add);
        if(cnt > (w - 30)) break;

        dl_stop();
        dl_clear(DL_C("black"));

        draw_arm(cnt,0);
        dl_circle(item_x, 450, 15, DL_RGB(0,255,0),1,1);

        dl_resume();
        dl_wait(0.08);
    }
    for(int i = 0; i < 400; i++) {
        dl_stop();
        dl_clear(DL_C("black"));
        draw_arm(cnt,i);
        dl_circle(item_x, 450, 15, DL_RGB(0,255,0),1,1);
        dl_resume();
        dl_wait(0.005);
    }

    return 0;
}


void draw_arm(int x, int y) {
    dl_line(x,0,x,y+30,DL_RGB(255,255,255),2);
    dl_line(x,y+30,x+15,y+40,DL_RGB(255,255,255),2);
    dl_line(x,y+30,x-15,y+40,DL_RGB(255,255,255),2);
    dl_line(x+15,y+40,x+15,y+50,DL_RGB(255,255,255),2);
    dl_line(x-15,y+40,x-15,y+50,DL_RGB(255,255,255),2);
}

void draw_home() {
    dl_clear(DL_C("black"));
    draw_arm(50,0);
    dl_text("Click F !!", 180, 200, 2.0, DL_C("white"), 2);
    dl_resume();
}

int main(void) {
    dl_initialize(1.0);
    int t, k, x, y;
    draw_home();
    while(1) {
        if(dl_get_event(&t, &k, &x, &y) && (t == DL_EVENT_KEY) && (k == 'f')) {
            ufo();
            break;
        }
    }

    return 0;
}