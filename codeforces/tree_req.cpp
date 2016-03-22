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
#define bitcount(n) __builtin_popcount(n)
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
typedef vector<vii> vvii;
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 500005;
vii level[MAX];
vvi graph;
int st[MAX],fi[MAX],depth[MAX],ti=0;
char s[MAX];
void dfs(int u,int p){
	st[u]=++ti;
	depth[u]=depth[p]+1;
	int val=1<<(s[u]-'a');
	level[depth[u]].PB(MP(st[u],level[depth[u]].back().S^val));
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(c!=p)dfs(c,u);
	}
	fi[u]=ti;
}
int main(){
	int n,m,p,v,h,t;
	vii::iterator it,it1;
	si(n);si(m);
	graph = vvi(n+1);
	loop(2,n+1){
		si(p);
		graph[p].PB(i);
		graph[i].PB(p);
	}
	scanf("%s",s+1);
	loop(1,n+1)level[i].PB(MP(0,0));
	depth[0]=0;
	dfs(1,0);
	loop(0,m){
		si(v);si(h);
		it = lower_bound(all(level[h]),MP(st[v],-1));
		int l =it-level[h].begin()-1;
		if(it==level[h].end()){
			printf("Yes\n");
			continue;
		}
		it1 = upper_bound(all(level[h]),MP(fi[v],INT_MAX));
		int r = it1-level[h].begin()-1;
		if(l>=0)t=level[h][l].S^level[h][r].S;
		else t=level[h][r].S;
		if(bitcount(t)<=1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
