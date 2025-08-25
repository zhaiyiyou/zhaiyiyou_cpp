#include <iostream>
using namespace std;

// 暴力匹配算法：逐个比较主串和模式串，找到第一个匹配位置
int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) { // 遍历主串
        int flag = 1; // 标记是否完全匹配
        for (int j = 0; t[j]; j++) { // 遍历模式串
            if (s[i + j] == t[j]) continue; // 当前字符匹配则继续
            flag = 0; // 有不匹配则标记为0
            break;
        }
        if (flag == 1) return i; // 找到匹配位置
    }
    return -1; // 未找到匹配
}

int main() {
    char s[100], t[100];
    // 输入主串和模式串，输出匹配结果
    while (scanf("%s%s", s, t) == 2) {
        printf("brute_force(%s,%s) = %d\n", s, t, brute_force(s, t));
    }
    return 0;
}