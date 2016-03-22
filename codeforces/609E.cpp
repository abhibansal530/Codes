//Abhishek Bansal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 200005,MAX2 = log2(MAX);
int n,m;
vector<vii> graph;
typedef struct node{
	int p,w;
}node;
typedef struct edge{
	int u,v,w,i;
	bool operator < (const edge& rt) const
	{
		return w<rt.w;
	}
}edge;
edge edges[MAX];
node P[MAX][MAX2];
int parent[MAX],rrank[MAX]={1},par[MAX]={-1},present[MAX],h[MAX],start;
int find(int u){
	if(parent[u]==u)return u;
	parent[u]=find(parent[u]);
	return parent[u];
}
void Union(int a,int b){
	int aa,bb;
	aa=find(a);
	bb=find(b);
	if(rrank[aa]<rrank[bb])parent[aa]=bb;
	else if(rrank[bb]<rrank[aa])parent[bb]=aa;
	else{
		parent[aa]=bb;
		rrank[bb]++;
	}
}
void print(){
	loop(i,1,n+1){
		printf("%d:\n",i);
		for(auto c:graph[i])printf("%d ",c.F);
		printf("\n");
	}
}
void dfs(int u,int p){
	h[u]=h[p]+1;
	par[u]=p;
	for(auto k:graph[u]){
		if(k.F==p)P[u][0].w=k.S;
		else dfs(k.F,u);
	}
}
void pre(){
	for(int i=1;i<=n;++i){
		for(int j=1;(i<<j)<=n;++j)P[i][j].p=-1;
	}
	for(int i=1;i<=n;++i){
		if(par[i]!=-1)P[i][0].p=par[i];
	}
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i<=n;++i){
			if(P[i][j-1].p!=-1){
				P[i][j].p=P[P[i][j-1].p][j-1].p;
				P[i][j].w=max(P[i][j-1].w,P[P[i][j-1].p][j-1].w);
			}
		}
	}
}
int  lca(int u,int v){
	if(h[u]>h[v])swap(u,v);
	int l =log2(h[v]);
	for(int i=l;i>=0;i--){
		if(h[v]-(1<<i)>=h[u])v=P[v][i].p;
	}
	//now u and are at same level
	if(u==v)return u;
	l =log2(h[u]);
	for(int i=l;i>=0;i--){
		if(P[u][i].p!=P[v][i].p){
			u=P[u][i].p;
			v=P[v][i].p;
		}
	}
	return par[u];
}
int findmax(int u,int p){
	//p is ancestor of u
//	trace2(u,p);
	if(u==p)return 0;
	int l = h[u]-h[p];
	int tm = log2(l),ret = -1;
	for(int i=tm;i>=0;i--){
		int up = 1<<i;
		if(up<=l){
			ret=max(ret,P[u][i].w);
			u=P[u][i].p;
		}
	}
//	trace1(ret);
	return ret;
}
int maxwt(int u,int v){
	int lc=lca(u,v);
	return max(findmax(u,lc),findmax(v,lc));
}
lli kruskal(){
	int u,v,uu,vv,w;
	lli ret=0;
	loop(i,0,m){
		u = edges[i].u;
		v = edges[i].v;
		uu = find(u);
		vv = find(v);
		w = edges[i].w;
		if(uu!=vv){
			Union(uu,vv);
			graph[u].PB(MP(v,w));
			graph[v].PB(MP(u,w));
			ret+=1ll*w;
			present[edges[i].i]=1;
		}
	}
	return ret;
}
void solve(){
	lli ans[MAX];
	sort(edges,edges+m);
	start = edges[0].u;
	lli mst = kruskal();
	h[start]=-1;
	dfs(start,start);
	pre();
	loop(i,0,m){
		if(present[edges[i].i])ans[edges[i].i]=mst;
		else{
			int tm = maxwt(edges[i].u,edges[i].v);
			ans[edges[i].i]=mst-tm+edges[i].w;
		}
	}
	loop(i,0,m)printf("%lld\n",ans[i]);
}
int main(){
	si(n);si(m);
	graph = vector<vii>(n+1);
	loop(i,0,m){
		si(edges[i].u);
		si(edges[i].v);
		si(edges[i].w);
		edges[i].i=i;
		parent[edges[i].u]=edges[i].u;
		parent[edges[i].v]=edges[i].v;
	}
	solve();
	return 0;
}
