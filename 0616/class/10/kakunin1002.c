#include <stdio.h>
#include <ctype.h>

// 文字列中に含まれる大文字の数を返す関数
// また，そのとき大文字の位置（インデクス）を
// 配列index中に格納する．
int count_upper(const char *str, int *index) {



}

int main(void) {
    char str[64];
    int index[64];
    int i, count;

    printf("文字列を入力: ");
    scanf("%63s", str);

    count = count_upper(str, index);

    printf("入力された文字列: %s\n", str);
    printf("含まれる大文字の数: %d\n", count);
    printf("大文字: ");
    for (i = 0; i < count; i++) {
        printf("%c ",            );
    }
    putchar('\n');

    return 0;
}

