#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_normalize(char *s1, const char *s2) {
    int _cnt = 0;
    for (int i = 0; s2[i] != '\0'; i++) {
        if (isalpha(s2[i])) {
            s1[_cnt] = tolower(s2[i]);
            _cnt++;
        }
    }
    s1[_cnt] = '\0';  // 文字列の終端を設定
}

int check_palindrome(const char *s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}


char *get_string(char *s, int n) {
    char *p = fgets(s, n, stdin);
    if (p == NULL) 
        return NULL;
    while (*s != '\n' && *s != '\0') {
        s++;
    }
    *s = '\0';
    return p;
}

#define LEN 100

int main(void) {
    char str[LEN];
    char str2[LEN];

    while (1) {
        printf("文字列を入力: ");
        if (get_string(str, LEN) == NULL) 
            break;

        str_normalize(str2, str);

        if (check_palindrome(str2))
            puts("回文です");
        else 
            puts("回文ではありません");
    }

    return 0;
}
