#include<iostream>
#include <cstring>
using namespace std;

int n,m,s;
int a[5005][5005];
bool v[5005];
int d[5005];

void prim(){
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        for (int j = 1; j <= n; j++){
            if(!v[j] && d[j] < d[t]){
                t = j;
            }
        }
        v[t] = 1;
        s += d[t];
        for(int j = 1;j <= n;j++){
            if(!v[j] && d[j] > a[t][j]){
                d[j] = a[t][j];
            }
        }
    }
    cout<<s << endl;
}

int main(){
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=min(a[x][y],z);
    }
    prim();
    return 0;
}