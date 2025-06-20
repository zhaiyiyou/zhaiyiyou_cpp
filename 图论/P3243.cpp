#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100001];
int n,m;
int in[100001];
priority_queue<int,vector<int>,greater<int> > q;

void top_sort(){
    for(int i = 1;i <= n;i ++){
        int tmp;
        for(int j = 1;j <= n;j ++){
            if(in[j] == 0){
                tmp = j;
                break;
            }
        }
        q.push(tmp);
        in[tmp] = -1;
        for(int j = 0;j < a[tmp].size();j ++){
            in[a[tmp][j]] --;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for(int i = 1;i <= m;i ++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
        }
    }
    top_sort();
    while (!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}