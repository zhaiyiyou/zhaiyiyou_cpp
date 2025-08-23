#include <iostream>
using namespace std;

#define TEST(func,s,t){\
    printf("%s(%s,%s) = %d\n",#func , s , t , func(s,t));\
}

int brute_force(const char *s,const char *t){//传入文本串和模式串
    for (int i = 0;s[i]; i++)//文本串
    {
        int flag = 1;//标记
        for(int j = 0;t[j];j++)//模式串
        {
            if(s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return i;
    }
    
    return -1;//找不到
}

int main(){
    char s[100],t[100];
    while(scanf("%s%s",&s,&t)){
        TEST(brute_force,s,t);
    }
    return 0;
}