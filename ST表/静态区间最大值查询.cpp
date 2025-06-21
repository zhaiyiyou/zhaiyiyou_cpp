#include <iostream>
#include <cmath>
using namespace std;

int n,q;
const int N = 100006;
int a[N];
int st[N][20];

int main()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        st[i][0] = a[i];
    }
    for(int j = 1;j <= 19;j ++){
        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
            st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while(q --){
        int l,r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        cout << max(st[l][len],st[r - (1 << len) + 1][len]) << endl;
    }
    return 0;
}