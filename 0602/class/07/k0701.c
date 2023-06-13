#include <stdio.h>
#include <math.h>

unsigned int set_bit(unsigned int x, int n) {
   int _tmp = 1 << n;
   return (x | _tmp);
}

unsigned int unset_bit(unsigned int x, int n) {
   int _tmp = 0 << n;
   return (x &~ _tmp);
}

unsigned int reverse_bit(unsigned int x, int n) {
   int _tmp = 0 << n;
   return (x ^ _tmp);
}

void print8bit(unsigned int x) {
   for (int i = 7; i >= 0; i--) {
      putchar((x & (1 << i)) ? '1' : '0');
   }
}

int main(void) {
   int val = 0b0;
   int mode, pin;
   while(1) {
      printf("モードを入力(0:セット 1:アンセット 2:反転) ");
      scanf("%u", &mode);
      if(mode < 3 && mode >= 0) {
         printf("何ビット目かを選択(0~7) "); 
         scanf("%u", &pin);
         switch(mode) {
            case 0:
               val = set_bit(val,pin);
               break;
            case 1:
               val = unset_bit(val,pin);
               break;
            case 2:
               val = reverse_bit(val,pin);
               break;
         }
         print8bit(val);
         puts("\n");
      }
      else break;
   }
   return 0;
}