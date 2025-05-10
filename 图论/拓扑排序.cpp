#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> a[110];
int in[110];
queue<int> q;

void top_sort(){
    for (int i = 1; i <= n; i++)
    {
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < a[x].size(); i++){
            int to = a[x][i];
            in[to]--;
            if(in[to] == 0) q.push(to);
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
            a[i].push_back(x);
            in[x]++;
        }
    }
    top_sort();
    return 0;
}