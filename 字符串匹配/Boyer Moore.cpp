#include <iostream>
#include <cstring>
using namespace std;

// 构造坏字符表
int* getDelta1(const char *t) {
    int *delta1 = new int[256];
    for (int i = 0; i < 256; i++) delta1[i] = -1;
    for (int i = 0; t[i]; i++) {
        delta1[(unsigned char)t[i]] = i;
    }
    return delta1;
}

// 构造好后缀表辅助数组
int* getSuffixes(const char *t) {
    int tlen = strlen(t);
    int *suff = new int[tlen];
    suff[tlen - 1] = tlen;
    for (int i = tlen - 2; i >= 0; i--) {
        int j = 0;
        while (i - j >= 0 && t[i - j] == t[tlen - 1 - j]) j++;
        suff[i] = j;
    }
    return suff;
}

// 构造好后缀表
int* getDelta2(const char *t) {
    int tlen = strlen(t);
    int *suff = getSuffixes(t);
    int *delta2 = new int[tlen];
    for (int i = 0; i < tlen; i++) delta2[i] = tlen;
    for (int i = tlen - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (int j = 0; j < tlen - 1 - i; j++) {
                if (delta2[j] == tlen)
                    delta2[j] = tlen - 1 - i;
            }
        }
    }
    for (int i = 0; i < tlen - 1; i++) {
        delta2[tlen - 1 - suff[i]] = tlen - 1 - i;
    }
    delete[] suff;
    return delta2;
}

// Boyer-Moore主算法：利用坏字符和好后缀规则进行高效匹配
int BM(const char *s, const char *t) {
    int *delta1 = getDelta1(t);
    int *delta2 = getDelta2(t);
    int slen = strlen(s);
    int tlen = strlen(t);
    for (int j = 0; j + tlen <= slen;) {
        int i = tlen - 1;
        while (i >= 0 && t[i] == s[j + i]) i--;
        if (i < 0) {
            delete[] delta1;
            delete[] delta2;
            return j; // 匹配成功
        }
        // 计算跳跃步长
        j += max(i - delta1[(unsigned char)s[j + i]], delta2[i]);
    }
    delete[] delta1;
    delete[] delta2;
    return -1; // 未匹配到
}

int main() {
    char s[100], t[100];
    // 输入主串和模式串，输出匹配结果
    while (scanf("%s%s", s, t) == 2) {
        printf("BM(%s,%s) = %d\n", s, t, BM(s, t));
    }
    return 0;
}