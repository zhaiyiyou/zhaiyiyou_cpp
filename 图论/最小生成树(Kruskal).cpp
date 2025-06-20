#include <iostream>
#include <algorithm>
using namespace std;

int n,m,s;
struct edge{
    int begin_,end_,data_;
}e[200005];
int uf[100005];

int find(int i){
    if(uf[i] != i){
        uf[i] = find(uf[i]);//路径压缩
    }
    return uf[i];
}

void union_set(int i,int j){
    uf[find(i)] = find(j);
}

bool cmp(edge q,edge r){
    return q.data_ < r.data_;
}

//最小生成树
void MST(){
    sort(e+1,e+1+m,cmp);
    for(int i = 1;i <= m;i++){
        int u = e[i].begin_,v = e[i].end_,w = e[i].data_;
        if(find(u)!=find(v)){
            union_set(u,v);
            s += w;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> e[i].begin_ >> e[i].end_ >> e[i].data_;
    }
    for(int i = 1;i <= n;i++){
        uf[i] = i;
    }
    MST();
    if(s == 0){
        cout << "orz" << endl;
    }else{
        cout << s << endl;
    }
    return 0;
}