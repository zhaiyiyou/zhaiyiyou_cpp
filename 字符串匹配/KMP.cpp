#include <iostream>
#include <cstring>
using namespace std;

// 计算模式串的 next 数组
// next[i] 表示 t[0...i] 的最长前缀后缀长度
void get_next(const char *t, int *next) {
    int m = strlen(t);
    next[0] = -1; // 第一个位置特殊处理
    int j = -1;
    for (int i = 1; i < m; i++) {
        // 回溯到前一个最长前后缀
        while (j >= 0 && t[j + 1] != t[i])
            j = next[j];
        if (t[j + 1] == t[i])
            j++;
        next[i] = j;
    }
}

// KMP算法主函数：在主串 s 中查找模式串 t 的首次出现位置
int KMP(const char *s, const char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int *next = new int[m];
    get_next(t, next); // 构造 next 数组
    int j = -1;
    for (int i = 0; i < n; i++) {
        // 匹配失败时根据 next 数组回溯
        while (j >= 0 && t[j + 1] != s[i])
            j = next[j];
        if (t[j + 1] == s[i])
            j++;
        if (j == m - 1) { // 匹配成功
            delete[] next;
            return i - m + 1;
        }
    }
    delete[] next;
    return -1; // 未匹配到
}

int main()
{
    char s[100], t[100];
    // 输入主串和模式串，输出匹配结果
    while (scanf("%s%s", s, t) == 2) {
        printf("KMP(%s,%s) = %d\n", s, t, KMP(s, t));
    }
    return 0;
}