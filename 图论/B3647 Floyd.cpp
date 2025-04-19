//Floyd算法(考虑重边)
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int a[110][110];
int n,m;

void floyd(){
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(a[i][k] != INT_MAX && a[k][j] != INT_MAX){
                    a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(i == j){
                a[i][j] = 0;
                continue;
            }
            a[i][j] = INT_MAX;
        }
    }
    for(int i = 1;i <= m;i ++){
        int x,y,z;
        cin>>x>>y>>z;
        if(z < a[x][y]) {  // 只保留较小的边权值
            a[x][y] = z;
            a[y][x] = z;
        }
    }
    floyd();
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}