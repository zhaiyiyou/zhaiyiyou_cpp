#include<cstdio>
using namespace std;

int n,m,q,fa[100005],s[100005];
int head[100005],k=1;
struct edge
{
	int to,next,w;
}e[400005],eg[200005];//存边
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}//并查集带路径压缩的查找

void adde(int u,int v,int w)//链式前向星加边
{
	e[k].to=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k++;
}

void Produce()//求生成树
{
	for(register int i=1;i<=n;i++)fa[i]=i;//并查集初始化
	for(register int i=1;i<=m;i++)
	{
		int fu=find(eg[i].next),fv=find(eg[i].to);//一条边两个端点的父亲
		if(fu==fv)continue;//如果父亲相同，则已经联通，再连边就会成环
		fa[fu]=fv;//合并两点
		adde(eg[i].next,eg[i].to,eg[i].w);//加边
		adde(eg[i].to,eg[i].next,eg[i].w);
	}
}

void dfs(int u,int fa)//dfs预处理异或和
{
	for(register int i=head[u];i;i=e[i].next)//遍历子节点
	{
		int v=e[i].to;
		if(v==fa)continue;//父亲则跳过
		s[v]=s[u]^e[i].w;//s[i]表示i到根节点的距离
		dfs(v,u);//继续深搜
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(register int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		eg[i]=(edge){u,v,w};//先暂时存一下边
	}
	Produce();//求生成树
	dfs(1,0);//预处理
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);//读入x,y
		printf("%d\n",s[x]^s[y]);//s[x]和s[y]异或时，lca(x,y)及以上的部分就抵消掉了，只留下最短路上的点
	}
	return 0;//结束了罪恶的一生
}
