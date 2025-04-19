#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n,m,s;
vector <pair<int,int>>a[100005];
//bellman ford 优化
queue<pair<int,int>>q;
int d[100005];
bool v[100005];

void spfa(){
    memset(d, 0x3f, sizeof(d));
    d[s]=0;
    v[s] = 1;
    q.push({s,d[s]});
    while (!q.empty()) {
        int to = q.front().first;
        q.pop();
        v[to] = 0; 
        for(int i=0;i<a[to].size();i++){
            int t = a[to][i].first;
            int w = a[to][i].second;
            if (d[t] > d[to] + w) {
                d[t] = d[to] + w;
                if (!v[t]) {
                    q.push({t, d[t]});
                    v[t] = 1;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        //无向图
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    s = 1;
    spfa();
    cout << d[n] << endl;
    return 0;
}