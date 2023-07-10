#include <drawlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define w DL_WIDTH
#define h DL_HEIGHT

int points = 0;

void draw_arm(int x, int y) {
    dl_line(x,0,x,y+30,DL_RGB(255,255,255),2);
    dl_line(x,y+30,x+15,y+40,DL_RGB(255,255,255),2);
    dl_line(x,y+30,x-15,y+40,DL_RGB(255,255,255),2);
    dl_line(x+15,y+40,x+15,y+50,DL_RGB(255,255,255),2);
    dl_line(x-15,y+40,x-15,y+50,DL_RGB(255,255,255),2);
}

void ufo() {
    int t, k, x, y;
    int item_x = 100 + rand() % 500 + 1;
    while(1) {
        int arm_x = 30;

        while(1) {
            if(dl_get_event(&t, &k, &x, &y) && (t == DL_EVENT_KEY) && (k == 'j')) {
                break;
            }

            int add = rand() % 20 + 1;
            arm_x += add;
            printf("%d\n",add);
            if(arm_x > (w - 30)) break;

            dl_stop();
            dl_clear(DL_C("black"));

            draw_arm(arm_x,0);
            dl_circle(item_x, 450, 15, DL_RGB(0,255,0),1,1);

            char tmp[64];
            sprintf(tmp,"Score %3d",points);
            dl_text(tmp, 350, 50, 1.5, DL_C("blue"), 2);
            dl_text("press J to ctach", 200, 300, 1, DL_RGB(11*add,11*add,11*add), 2);

            dl_resume();
            dl_wait(0.08);
        }
        for(int i = 0; i < 400; i++) {
            dl_stop();
            dl_clear(DL_C("black"));
            draw_arm(arm_x,i);
            dl_circle(item_x, 450, 15, DL_RGB(0,255,0),1,1);
            char tmp[64];
            sprintf(tmp,"Score %3d",points);
            dl_text(tmp, 350, 50, 1.5, DL_C("blue"), 2);
            dl_resume();
            dl_wait(0.005);
        }

        if((arm_x > (item_x - 15)) && (arm_x < (item_x + 15))) {
            points++;
            for(int i = 400; i > 0; i--) {
                dl_stop();
                dl_clear(DL_C("black"));
                draw_arm(arm_x,i);
                dl_circle(item_x, i+60, 15, DL_RGB(0,255,0),1,1);
                char tmp[64];
                sprintf(tmp,"Score %3d",points);
                dl_text(tmp, 350, 50, 1.5, DL_C("blue"), 2);
                dl_resume();
                dl_wait(0.003);
            }
            for(int i = arm_x; i > 30; i--) {
                dl_stop();
                dl_clear(DL_C("black"));
                draw_arm(i,0);
                dl_circle(i, 60, 15, DL_RGB(0,255,0),1,1);
                char tmp[64];
                sprintf(tmp,"Score %3d",points);
                dl_text(tmp, 350, 50, 1.5, DL_C("blue"), 2);
                dl_resume();
                dl_wait(0.003);
            }
            for(int i = 60; i < (h - 20); i++) {
                dl_stop();
                dl_clear(DL_C("black"));
                draw_arm(30,0);
                dl_circle(30, i, 15, DL_RGB(0,255,0),1,1);
                char tmp[64];
                sprintf(tmp,"Score %3d",points);
                dl_text(tmp, 350, 50, 1.5, DL_C("blue"), 2);
                dl_resume();
                dl_wait(0.003);
                item_x = 100 + rand() % 500 + 1;
            }
        }
        else break;
    }

    return 0;
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
    dl_clear(DL_C("black"));
    dl_text("GAME OVER", 150, 200, 2.0, DL_C("white"), 2);
    char __tmp_points[64];
    sprintf(__tmp_points,"Score : %d",points);
    dl_text(__tmp_points, 150, 300, 1.5, DL_C("white"), 2);
    dl_resume();
    dl_wait(10);
    
    return 0;
}