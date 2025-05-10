#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
vector<int> a[110];
int in[110];
set<int> q;

void top_sort(){
    for (int i = 1; i <= n; i++)
    {
        if(in[i] == 0) q.emplace(i);
    }
    while(!q.empty()){
        int x = *q.begin();
        cout << x << " ";
        q.erase(q.begin());
        for (int i = 0; i < a[x].size(); i++){
            int to = a[x][i];
            in[to]--;
            if(in[to] == 0) q.emplace(to);
        }
    }
}

int main(){
    cin >> n;
    //存图
    for (int i = 1; i <= n; i++)
    {
        int x;
        while(1){
            cin >> x;
            if(x == 0) break;
            a[i].emplace_back(x);
            in[x]++;
        }
    }
    top_sort();
    return 0;
}