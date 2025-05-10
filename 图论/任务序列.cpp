#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
vector<int> a[110];
queue<int> q;
int in[110];

void top_sort(){
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.emplace(i);
    }
    while(!q.empty()){
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int i = 0; i < a[x].size(); i++){
            int to = a[x][i];
            in[to]--;
            if(in[to] == 0) q.emplace(to);
        }
    }
}

int main()
{
    while(cin >> n >> m){
        for(int i = 1; i <= m; i++){
            int x,y;
            cin >> x >> y;
            a[x].emplace_back(y);
            in[y]++;
        }
        top_sort();
        cout << endl;
        memset(in,0,sizeof(in));
        for(int i = 1; i <= n; i++){
            a[i].clear();
        }
        while(!q.empty()){
            q.pop();
        }
    }
    return 0;
}