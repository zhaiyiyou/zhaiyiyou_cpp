#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// Sunday算法：利用主串下一个字符的位置信息进行跳跃匹配
int sunday(const char *s, const char *t) {
    int len[256], n = strlen(s), m = strlen(t);
    // 初始化每个字符的跳跃步长
    for (int i = 0; i < 256; i++) len[i] = m + 1;
    for (int i = 0; t[i]; i++) len[(unsigned char)t[i]] = m - i;
    // 主串匹配循环
    for (int i = 0; i + m <= n;) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) return i; // 匹配成功
        if (i + m >= n) break; // 已到主串末尾
        i += len[(unsigned char)s[i + m]]; // 跳跃到下一个位置
    }
    return -1; // 未匹配到
}

int main() {
    char s[100], t[100];
    // 输入主串和模式串，输出匹配结果
    while (scanf("%s%s", s, t) == 2) {
        printf("sunday(%s,%s) = %d\n", s, t, sunday(s, t));
    }
    return 0;
}