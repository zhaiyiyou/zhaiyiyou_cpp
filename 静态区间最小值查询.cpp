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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) st[i][0] = a[i];
    for(int j = 1;j <= 19;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int len = r - l + 1;
        int k = log2(len);
        cout << min(st[l][k],st[r - (1 << k) + 1][k]) << endl;
    }

    return 0;
}