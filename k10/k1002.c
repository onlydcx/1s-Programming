#include <stdio.h>
#include <string.h>
#include <ctype.h>

// type型の変数xとyの値を入れ替える関数
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0);

// アルファベット以外を読み飛ばして辞書順を求める関数（この関数の中身を書き換える）
int stracmp(const char *s1, const char *s2) {
    /* 参考書に書いてある strcmp の実装 */
    while (*s1 == *s2) {
        if (*s1 == '\0') 
            return 0;
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// 文字列を指しているポインタの配列 str_list の要素を strcmp 関数で比較した
// ときに小さい順（辞書順）に並べ替える関数
void sort_str(char* str_list[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (stracmp(str_list[j], str_list[j+1]) > 0) {
                swap(char *, str_list[j], str_list[j+1]);
            }
        }
    }
}

// 標準入力（キーボード）から，最長nの文字列をsに読み込む関数.
// 戻り値は s と同じ値（正常に読み込めたとき）か，NULL（Ctrl+Dが押されたとき）．
char *get_string(char *s, int n) {
    char *p = fgets(s, n, stdin);
    if (p == NULL) 
        return NULL;
    while (*s != '\n' && *s != '\0')
        s++;
    *s = '\0';
    return p;
}

// 文字列の配列の要素数（最大N個の文字列まで扱う）
#define N 100 
// 各文字列の長さの最大値（文字列の長さはLENまで）
#define LEN 100

int main(void) {
    char strs[N][LEN];  // 文字列の配列
    int n;              // 入力された文字列の数

    // 最大N個の文字列を入力させる
    for (n = 0; n < N; n++) {
        printf("文字列を入力(%d番目): ", n);
        if (get_string(strs[n], LEN) == NULL) break;
    }
    putchar('\n');

    // 入力された文字列を表示しながら，
    // 各文字列の先頭要素のアドレスを，配列pに要素として代入する．
    char *p[N];
    for (int i = 0; i < n; i++) {
        printf("strs[%d] = %s\n", i, strs[i]);
        p[i] = strs[i];
    }

    // 辞書順にソートする
    sort_str(p, n);
    
    // ソートした結果を表示する
    for (int i = 0; i < n; i++) {
        printf("p[%d] = %s\n", i, p[i]);
    }

    return 0;
}
