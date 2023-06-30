#include <stdio.h>

void scan_string(char str[], int n) {
    for(int i = 0; i < n; i++) {
        str[i] = getchar();
        if(str[i] == '\n') {
            str[i] = '\0';
            return 0;
        }
    }
    str[n - 1] = '\0';
}

int str_len(const char s[]) {
    int n = 0;
    while(s[n] != '\0') {
        n++;
    }
    return n;
}

void append_upper(char str[]) {
    int len = str_len(str);
    for(int i = 0; i < len; i++) {
        if(isupper(str[i])) {
            strcat(str, &str[i]);
        }
    }
    len = str_len(str);
    for(int i = 0; i < len; i++) {
        puts(str[i]);
    }
}

int main(void) {
    char str[100];
    printf("Enter string: ");
    scan_string(str, 100);

    append_upper(str);

    printf("result string: %s\n", str);
}