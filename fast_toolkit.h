//#pragma GCC optimize("Ofast,no-stack-protector")
//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-fwhole-program")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-fstrict-overflow")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-skip-blocks")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")

//include:

#include <bits/stdc++.h>


//#define endl '\n'
#define pow fastpow
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
//unlocked WINDOWS会报错
using namespace std;
namespace fast_io{
	const int fread_cnt=(1<<20);
	const int fwrite_cnt=(1<<20);
	class fast_read{
	private:
		char buf_in[fread_cnt],*p1,*p2;
		inline char gc(){return (p1==p2&&(p2=(p1=buf_in)+fread(buf_in,1,fread_cnt,stdin),p1==p2)?EOF:*p1++);}
		inline bool read_bool(){char ch=gc();while(ch<'0'||ch>'1'){ch=gc();}return (ch=='1');}
		inline char read_ch(){char ch=gc();while(ch==' '||ch=='\r'||ch=='\n'||ch=='\t'){ch=gc();}return ch;}
		inline string read_string(){
			string s;char ch=gc();while(ch==' '||ch=='\r'||ch=='\n'||ch=='\t'){ch=gc();}
			while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!='\t'){s+=ch;ch=gc();}return s;
		}
		template <typename T>
		inline T read_int(){
			T x=0,f=1;char ch=gc();
			while(ch<'0'||ch>'9'){f=(ch=='-')?-f:f;ch=gc();}
			while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}
			return x*f;
		}
		template <typename T>
		inline T read_unsigned(){
			T x=0;char ch=gc();while(ch<'0'||ch>'9'){ch=gc();}
			while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}
			return x;
		}
		template <typename T>
		inline T read_float(){
			T x=0,f=1,c=1;char ch=gc();
			while(ch<'0'||ch>'9'){f=(ch=='-')?-f:f;ch=gc();}
			while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=gc();}
			if(ch=='.'){ch=gc();while(ch>='0'&&ch<='9'){c/=10;x+=c*(ch^48);ch=gc();}}
			return x*f;
		}
	public:
		fast_read& operator >> (bool &valx){valx=read_bool();return *this;}
		fast_read& operator >> (char &valx){valx=read_ch();return *this;}
		fast_read& operator >> (string &valx){valx=read_string();return *this;}
		fast_read& operator >> (float &valx){valx=read_float<float>();return *this;}
		fast_read& operator >> (double &valx){valx=read_float<double>();return *this;}
		fast_read& operator >> (long double &valx){valx=read_float<long double>();return *this;}
		fast_read& operator >> (short &valx){valx=read_int<short>();return *this;}
		fast_read& operator >> (int &valx){valx=read_int<int>();return *this;}
		fast_read& operator >> (long &valx){valx=read_int<long>();return *this;}
		fast_read& operator >> (long long &valx){valx=read_int<long long>();return *this;}
		fast_read& operator >> (unsigned short &valx){valx=read_unsigned<unsigned short>();return *this;}
		fast_read& operator >> (unsigned int &valx){valx=read_unsigned<unsigned int>();return *this;}
		fast_read& operator >> (unsigned long &valx){valx=read_unsigned<unsigned long>();return *this;}
		fast_read& operator >> (unsigned long long &valx){valx=read_unsigned<unsigned long long>();return *this;}
	}fin;
	class fast_write{
	private:
		char buf_out[fwrite_cnt],*p=buf_out;
		inline void write_bool(bool x){char ch=(x==1)?'1':'0';pc(ch);}
		inline void write_ch(char x){char ch=x;pc(ch);}
		inline void write_string(string s){for(string::iterator it=s.begin();it!=s.end();it=next(it)){pc(*it);}}
		template <typename T>
		inline void write_int(T x){
			if(x<(T)0){pc('-');x=-x;}
			if(x>=10){write_int(x/10);}pc((x%10)^48);
		}
		template <typename T>
		inline void write_unsigned(T x){
			if(x>=10){write_unsigned(x/10);}pc((x%10)^48);
		}
		template <typename T>
		inline void write_float(T x){
			if(x<(T)0)pc('-'),x=-x;
			write_int((int)x);pc('.');x-=(int)x;
			while(x!=0){x*=10;pc((int)x^48);x-=(int)x;}
		}
	public:
		inline void pc(char ch){if(p-buf_out==fwrite_cnt){fwrite(buf_out,1,fwrite_cnt,stdout),p=buf_out;}*p=ch;++p;}
		inline void flush(){fwrite(buf_out,1,p-buf_out,stdout);p=buf_out;}
		inline fast_write& operator << (bool valx){write_bool(valx);return *this;}
		inline fast_write& operator << (char valx){write_ch(valx);return *this;}
		inline fast_write& operator << (string valx){write_string(valx);return *this;}
		inline fast_write& operator << (float valx){write_float<float>(valx);return *this;}
		inline fast_write& operator << (double valx){write_float<double>(valx);return *this;}
		inline fast_write& operator << (long double valx){write_float<long double>(valx);return *this;}
		inline fast_write& operator << (short valx){write_int<short>(valx);return *this;}
		inline fast_write& operator << (int valx){write_int<int>(valx);return *this;}
		inline fast_write& operator << (long valx){write_int<long>(valx);return *this;}
		inline fast_write& operator << (long long valx){write_int<long long>(valx);return *this;}
		inline fast_write& operator << (unsigned short valx){write_unsigned<unsigned short>(valx);return *this;}
		inline fast_write& operator << (unsigned int valx){write_unsigned<unsigned int>(valx);return *this;}
		inline fast_write& operator << (unsigned long valx){write_unsigned<unsigned long>(valx);return *this;}
		inline fast_write& operator << (unsigned long long valx){write_unsigned<unsigned long long>(valx);return *this;}
		inline fast_write& operator << (fast_write& (*func)(fast_write&)){return func(*this);}
	}fout;inline fast_write& endl(fast_write& fastout){fastout.pc('\n');fastout.flush();return fastout;}
}using namespace fast_io;
#define int long long
int Reverse_order_pairs=0;//逆序对，个数
const int MAXN=1000001;
int a[MAXN],c[MAXN];
class Graph {//DAG有向无环图
private:
	int n;
	vector<unordered_map<int, int>> adj; // 邻接表，adj[u][v] = 初始边权w0
	vector<int> add_in;   // 每个节点的入边附加权值
	vector<int> add_out;  // 每个节点的出边附加权值
	vector<int> topo;     // 拓扑序
	vector<int> topo_index; // 节点在拓扑序中的索引
	vector<int> in_degree;  // 节点的入度
	
public:
	Graph(int num_nodes) : n(num_nodes), adj(num_nodes), add_in(num_nodes, 0), 
	add_out(num_nodes, 0), topo_index(num_nodes, -1), 
	in_degree(num_nodes, 0) {}
	
	// 添加有向边 u->v，初始权值为w
	void addedge(int u, int v, int w) {
		if (u < 0 || u >= n || v < 0 || v >= n) return;
		if (adj[u].find(v) == adj[u].end()) {
			adj[u][v] = w;
			in_degree[v]++;
		} else {
			adj[u][v] = w; // 如果边已存在，覆盖权值
		}
	}
	
	// 构建拓扑序
	void build_topo() {
		topo.clear();
		vector<int> in_deg = in_degree; // 复制入度数组
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (in_deg[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			topo.push_back(u);
			for (auto& edge : adj[u]) {
				int v = edge.first;
				if (--in_deg[v] == 0) {
					q.push(v);
				}
			}
		}
		// 设置拓扑序索引
		for (int i = 0; i < topo.size(); i++) {
			topo_index[topo[i]] = i;
		}
	}
	
	// 修改单边(u->v)的初始权值，加上delta
	void change_edge(int u, int v, int delta) {
		if (u < 0 || u >= n || v < 0 || v >= n) return;
		if (adj[u].find(v) != adj[u].end()) {
			adj[u][v] += delta;
		}
	}
	
	// 修改节点v的所有入边，每条边加上delta
	void change_in_edges(int v, int delta) {
		if (v >= 0 && v < n) {
			add_in[v] += delta;
		}
	}
	
	// 修改节点u的所有出边，每条边加上delta
	void change_out_edges(int u, int delta) {
		if (u >= 0 && u < n) {
			add_out[u] += delta;
		}
	}
	
	// 查询s到t的最短路径长度
	int shortest_path(int s, int t) {
		if (s < 0 || s >= n || t < 0 || t >= n) return INT_MIN;
		if (topo.empty() || topo_index[s] == -1) return INT_MIN;
		
		vector<long long> dist(n, LLONG_MAX / 2); // 防止溢出
		dist[s] = 0;
		int start_idx = topo_index[s];
		
		for (int i = start_idx; i < topo.size(); i++) {
			int u = topo[i];
			if (dist[u] == LLONG_MAX / 2) continue; // 不可达节点
			for (auto& edge : adj[u]) {
				int v = edge.first;
				int w0 = edge.second;
				long long actual_weight = (long long)w0 + add_out[u] + add_in[v];
				if (dist[u] + actual_weight < dist[v]) {
					dist[v] = dist[u] + actual_weight;
				}
			}
		}
		return (dist[t] >= LLONG_MAX / 2) ? INT_MIN : (int)dist[t];
	}
	
	// 查询s到t的最长路径长度
	int longest_path(int s, int t) {
		if (s < 0 || s >= n || t < 0 || t >= n) return INT_MIN;
		if (topo.empty() || topo_index[s] == -1) return INT_MIN;
		
		vector<long long> dist(n, LLONG_MIN);
		dist[s] = 0;
		int start_idx = topo_index[s];
		
		for (int i = start_idx; i < topo.size(); i++) {
			int u = topo[i];
			if (dist[u] == LLONG_MIN) continue; // 不可达节点
			for (auto& edge : adj[u]) {
				int v = edge.first;
				int w0 = edge.second;
				long long actual_weight = (long long)w0 + add_out[u] + add_in[v];
				if (dist[u] + actual_weight > dist[v]) {
					dist[v] = dist[u] + actual_weight;
				}
			}
		}
		return (dist[t] == LLONG_MIN) ? INT_MIN : (int)dist[t];
	}
};
bitset<100000010> isPrime;
int Prime[6000010];//质数
int cntPrime = 0;
void GetPrime(int n){
	isPrime.set();
	
	isPrime[1] = 0;
	
	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i])
			Prime[++cntPrime] = i; 
		
		for(int j = 1; j <= cntPrime && i*Prime[j] <= n; j++) 
		{
			isPrime[i*Prime[j]] = 0;
			
			if(i % Prime[j] == 0)
				break; 
		}
	}
}

//支持对a数组排序
void MergeSort(int beg,int end)//begin&end
{
	if(beg==end)  
		return;
	int mid=(beg+end)/2,i=beg,j=mid+1,k=beg;
	MergeSort(beg,mid),MergeSort(mid+1,end);
	while(i<=mid&&j<=end)
		if(a[i]<=a[j])
			
			c[k++]=a[i++];
	else{
		c[k++]=a[j++];
		Reverse_order_pairs+=mid-i+1;//左边即个数
	}//inplace_merge();
	
	while(i<=mid)c[k++]=a[i++];
	while(j<=end)c[k++]=a[j++];
	for(int x=beg;x<=end;x++)a[x]=c[x];
} //归并排序

struct fantastic     
{
	int len,s[9999];
	fantastic()
	{
		memset(s,0,sizeof(s));
		len=1;
	}
	fantastic operator=(const char*num)
	{
		len=strlen(num);
		for(int i=0;i<len;++i)
			s[i]=num[len-i-1]-'0';
		return *this;
	}
	fantastic operator=(const int num)
	{
		char a[9999];
		sprintf(a,"%lld",num);
		*this=a;
		return *this;
	}
	fantastic (const int num)
	{
		*this=num;
	}
	fantastic (const char * num)
	{
		*this=num;
	}
	fantastic operator+(const fantastic &a)   
	{
		fantastic c;
		c.len=max(len,a.len)+1;                
		for(int i=0,x=0;i<c.len;++i)
		{
			c.s[i]=s[i]+a.s[i]+x;
			x=c.s[i]/10;
			c.s[i]=c.s[i]%10;
		}
		if(c.s[c.len-1]==0)
			--c.len;
		return c;
	}
	fantastic operator * (const fantastic &x)           
	{
		fantastic c;
		c.len=len+x.len;                 
		for(int i=0;i<len;++i)
			for(int j=0;j<x.len;++j)
			{
				c.s[i+j]+=s[i]*x.s[j];
				c.s[i+j+1]+=c.s[i+j]/10;
				c.s[i+j]%=10;
			}
		if(c.s[c.len-1]==0)
			--c.len;
		return c;
	}
};

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x << 1) + (x << 3)+ch-48;ch=getchar();}
	return x*f;
}//快读
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}//快输
//常数较小的快输：
/*
void write(int x) {
static int sta[35];
int top = 0;
do {
sta[top++] = x % 10, x /= 10;
} while (x);
while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
*/




//另一种快读
/*
#include <bits/stdc++.h>
using lint = long long;

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
char buf[MAXSIZE], *p1, *p2;
char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
IO() : p1(buf), p2(buf), pp(pbuf) {}

~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
char gc() {
#if DEBUG  // 调试，可显示字符
return getchar();
#endif
if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
return p1 == p2 ? ' ' : *p1++;
}

bool blank(char ch) {
return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

template <class T>
T read(T &x) {
double tmp = 1;
bool sign = 0;
x = 0;
char ch = gc();
for (; !isdigit(ch); ch = gc())
if (ch == '-') sign = 1;
for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
if (ch == '.')
for (ch = gc(); isdigit(ch); ch = gc())
tmp /= 10.0, x += tmp * (ch - '0');
if (sign) x = -x;
return x;
}

void read(char *s) {
char ch = gc();
for (; blank(ch); ch = gc());
for (; !blank(ch); ch = gc()) *s++ = ch;
*s = 0;
}

void read(char &c) { for (c = gc(); blank(c); c = gc()); }

void push(const char &c) {
#if DEBUG  // 调试，可显示字符
putchar(c);
#else
if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
*pp++ = c;
#endif
}

template <class T>
void write(T x) {
if (x < 0) x = -x, push('-');  // 负数输出
static T sta[35];
T top = 0;
do {
sta[top++] = x % 10, x /= 10;
} while (x);
while (top) push(sta[--top] + '0');
}

template <class T>
void write(T x, char lastChar) {
write(x), push(lastChar);
}
} io;

int main() {
int n = io.read(n);
lint sum = 0;
for (int t; n; --n) sum += io.read(t);
io.write(sum, '\n');
return 0;
}
*/
int Mod;//支持输入模值
int fastpow(int a,int b) {
	if(b==0)return 1;
	int sum=1;
	while(b) {
		if(b&1) sum=sum*a%Mod;
		a=a*a%Mod,b>>=1;
	}
	return sum;
}
//GetPrime(MAXP);MAXP为查询范围（查询到质数的最大值<=MAXP）
void FindPrime(){//查询质数
	int k;
	k=read();
	write(Prime[k]);
	puts("");
	return;
}
signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	//TODO
	int n;//个数
	int node_cnt,edge_cnt;//节点个数
	cin>>node_cnt>>edge_cnt;
	Graph dag(node_cnt);
	while(edge_cnt--){
		int u,v,w;
		cin>>u>>v>>w;
		dag.addedge(u,v,w);
	}
	dag.build_topo();
	
//	cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	MergeSort(1,n);
	int order_pairs=n*(n-1)/2-Reverse_order_pairs;
	//顺序对（请先MergeSort）
//	cout<<order_pairs;
	return 0;
	
}