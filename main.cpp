#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,m,Q;
vector<int> a[200001];
int in[200001];
set<int> s;
vector<int> path;

void top_sort(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            s.emplace(i); 
        }
    }
    while(!s.empty()){
        int x = *s.begin(); 
        s.erase(s.begin()); 
        path.emplace_back(x);
        for(auto y:a[x]){
            in[y]--;
            if(in[y]==0){
                s.emplace(y); 
            }
        }
    }
}

int main()
{
    cin >> n >> m >> Q;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        in[y]++;
    }
    top_sort();
    while(Q--){
        int x,y;
        int t1 = 0,t2 = 0;
        cin >> x >> y;
        for(int i=0;i<path.size();i++){
            if(path[i] == x){
                t1 = i;
                continue;
            }if(path[i] == y){
                t2 = i;
                continue;
            }
        }
        if(t1<t2){
            cout << t2 - t1 << endl;
        }else{
            cout << t1 - t2 << endl;
        }
    }
    return 0;
}