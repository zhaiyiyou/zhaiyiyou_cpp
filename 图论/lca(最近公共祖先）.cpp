#include <iostream>
#include<vector>
using namespace std;

const int maxn = 500005;
int n,m,s;
vector<int>a[maxn];
int f[maxn][23];//23够用了
int dep[maxn];//当前深度
//f[i][j]表示i的第2^j个祖先

//dfs的作用是填充dep和i的父节点
void dfs(int u,int fa){//u是当前节点，fa是u的父节点
    f[u][0] = fa;//u的父节点
    dep[u] = dep[fa] + 1;//u的深度
    for(auto v:a[u]){//遍历u的所有子节点
        if(v == fa)continue;//如果v是u的父节点，跳过
        dfs(v,u);//递归
    }
}

void init(){
    for(int j = 1;(1 << j) <= n;j++){
        for(int i = 1;i <= n;i++){
            f[i][j] = f[f[i][j - 1]][j - 1];//dp转移方程
        }
    }
}

int LCA(int u,int v){
    //假设u是晚辈
    if(dep[u] < dep[v])swap(u,v);//保证u是长辈
    //先把u和v跳到同一深度
    for(int i = 22;i >= 0;i--){
        if(dep[f[u][i]] >= dep[v]){//如果u的第2^i个祖先的深度大于等于v的深度
            u = f[u][i];//u跳到u的第2^i个祖先
        }
    }
    if(u == v)return u;//如果u和v相等，说明u和v是同一个节点
    //如果u和v不相等，说明u和v不是同一个节点
    //u和v跳到同一深度
    for(int i = 22;i >= 0;i--){
        if(f[u][i] != f[v][i]){
            u = f[u][i];//u跳到u的第2^i个祖先
            v = f[v][i];//v跳到v的第2^i个祖先
        }
    }
    return f[u][0];//返回u的第1个祖先
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 1;i <= n - 1;i ++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(s,0);//从s开始，s的父节点是0
    init();//预处理
    for(int i = 1;i <= m;i ++){
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << endl;
    }
    return 0;
}