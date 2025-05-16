#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> a[100001];
int in[100001];
queue<int> q;

void top_sort(){
    bool flag = true;
    for(int i = 1;i <= n;i ++){
        int tmp = 0;
        for(int j = 1; j <= n;j ++){
            if(in[j] == 0){
                if(tmp != 0){
                    flag = false;
                    break;
                }
                tmp = j;
            }
        }
        in[tmp] = -1;
        q.push(tmp);
        for(int j = 0;j < a[tmp].size();j ++){
            in[a[tmp][j]] --;
        }
    }
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    if(!flag){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        in[y] ++;
    }
    top_sort();
    return 0;
}