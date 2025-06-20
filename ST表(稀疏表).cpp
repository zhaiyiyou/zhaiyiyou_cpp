#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 30, M = 1000006;
int n, m;
int dp[N][M];

int main()
{
    cin >> n >> m;
    int len = log2(n) + 1;
    for(int i = 1;i <= n;i ++){
        cin >> dp[0][i];
    }
    for(int i = 1;i <= len;i ++){
        for(int j = 1;j <= m - (1 << i) + 1;j ++){
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j + (1 << (i - 1))]);
        }   
    }
    while(m --){
        int l,r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        cout << max(dp[len][l],dp[len][r - (1 << len) + 1]) << endl;
    }
    return 0;
}