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
#define loop(a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef vector< vii > vvii;
const lli MOD=lli(1e9)+7;
int d;
vvi graph;
int a[2001],visited[2001],f[2001];
//int min(int a,int b) return a<b?a:b;
//int max(int a,int b) return a>b?a:b;
void dfs(int u,int root){
	visited[u]=1;
	f[u]=1;
	int s=SZ(graph[u]);
	loop(0,s){
		int v=graph[u][i];
		if(visited[v]||a[v]<a[root]||a[v]-a[root]>d)continue;
		if(a[v]==a[root]&&v>root)continue;
		dfs(v,root);
		f[u]=((f[u]%MOD)*((f[v]+1)%MOD))%MOD;
	}
}
int main(){
	int n,u,v;
	si(d);si(n);
	graph=vvi(n+1);
	loop(1,n+1)si(a[i]);
	int m=n-1;
	while(m--){
		si(u);
		si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	lli ans=0;
	loop(1,n+1){
		SET(visited,0);
		SET(f,0);
		dfs(i,i);
		ans+=f[i];
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
