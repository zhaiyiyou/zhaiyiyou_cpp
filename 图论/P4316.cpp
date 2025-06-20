#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int n,m;
vector<pair<int,double>>a[200005];
int in[200005];
vector<int> ans;
vector<double> ans2;

void top_sort(){
    queue<int>q;
    for(int i = 1;i <= n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0;i < a[x].size();i++){
            int y = a[x][i].first;
            double z = a[x][i].second;
            in[y]--;
            if(in[y] == 0){
                q.push(y);
            }
            if(in[y] == 0){
                ans.push_back(y);
                ans2.push_back(z);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int x,y;
        double z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        in[y]++;
    }
    top_sort();
    for(int i = 0;i < ans.size();i++){
        if(ans[i] == n){
            int x;
            for(int j = 1;j <= n;j++){
                x += ans2[j];
            }
            cout << fixed << setprecision(2) << x << endl;
            break;
        }
    }
    return 0;
}