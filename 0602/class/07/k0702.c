#include <stdio.h>

unsigned int generate_pattern(int width, int lsb) {
   int _tmp = 0b0;
   if(lsb < 0) {
      width += lsb;
      lsb = 0;
   }
   for(int i = 0; i < width; i++) {
      _tmp = (_tmp | (1 << i));
   }
   _tmp = (_tmp << lsb);
   return _tmp;
}

void print_bits(unsigned int x) { 
   for (int i = 31; i >= 0; i--) {
      putchar((x & (1 << i)) ? '1' : '0');
   }
}

int main(void) {
   const int max_width = 10;
   for(int i = 0; i < 30; i++) {
      int result = generate_pattern(max_width,i-max_width);
      print_bits(result);
      puts("");
   }
   return 0;
}