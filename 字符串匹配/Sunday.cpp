#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sunday(const char *s, const char *t) {
    int len[256], n = strlen(s), m = strlen(t);
    for (int i = 0; i < 256; i++) len[i] = m + 1;
    for (int i = 0; t[i]; i++) len[(unsigned char)t[i]] = m - i;
    for (int i = 0; i + m <= n;) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) return i;
        if (i + m >= n) break;
        i += len[(unsigned char)s[i + m]];
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) == 2) {
        printf("sunday(%s,%s) = %d\n", s, t, sunday(s, t));
    }
    return 0;
}