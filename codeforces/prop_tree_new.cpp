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
//***********************************END OF TEMPLATE*********************************************************************
int ti=0;
const int MAX = 200005;
vvi graph;
int lvl[MAX],st[MAX],fi[MAX];
typedef struct BIT{
	int sz;
	lli tree[MAX];
	void init(int n){
		sz=n;
		SET(tree,0);
	}
	void update(int i,int v){
		while(i<=sz){
			//trace1(i);
			tree[i]+=1ll*v;
			i+=(i&(-i));
		}
		return;
	}
	int query(int i){
		int sum=0;
		while(i>0){
			sum+=tree[i];
			i-=(i&(-i));
		}
		return sum;
	}
}BIT;
void dfs(int u,int p){
	st[u]=++ti;
	lvl[u]=lvl[p]+1;
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(c==p)continue;
		dfs(c,u);
	}
	fi[u]=ti;
}
int main(){
	BIT odd,even;
	int n,m,a[MAX],op,u,v,x,val;
	si(n);si(m);
	odd.init(MAX);
	even.init(MAX);
	graph=vvi(n+1);
	loop(1,n+1)si(a[i]);
	loop(1,n){
		si(u);si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	lvl[0]=-1;
	dfs(1,0);
	while(m--){
		si(op);
		if(op==1){
			si(x);si(val);
			if(lvl[x]&1){
				odd.update(st[x],val);
				odd.update(fi[x]+1,-1*val);
				even.update(st[x],-1*val);
				even.update(fi[x]+1,val);
			}
			else{
				even.update(st[x],val);
				even.update(fi[x]+1,-1*val);
				odd.update(st[x],-1*val);
				odd.update(fi[x]+1,val);
			}
		}
		else{
			si(x);
			if(lvl[x]&1){
				cout<<a[x]+odd.query(st[x])<<endl;
			}
			else cout<<a[x]+even.query(st[x])<<endl;
		}
	}
	return 0;
}

