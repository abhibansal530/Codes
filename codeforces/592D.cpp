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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
vvi graph;
const int MAX = 123460;
int mark[MAX],dist[MAX],deg[MAX],root;
void dfs(int p,int u){
	if(p!=u)dist[u]=dist[p]+1;
	TR(graph[u],it){
		if(*it==p)continue;
		dfs(u,*it);
	}
}
int cnt(int r,int p,int u){
	//trace2(u,p);
	if(deg[u]==1&&u!=r){
		if(mark[u])return 1;
		else return 0;
	}
	int ret=0,flag=0;
	TR(graph[u],it){
		if(*it==p)continue;
		int tmp=cnt(r,u,*it);
//		trace2(*it,tmp);
		if(tmp>0)flag=1;
		ret+=tmp;
	}
	if(flag==1||mark[u]==1)ret++;
	return ret;
}
void solve(int n){
//	trace1(cnt(root,root,root));
	int ans=2*(cnt(root,root,root)-1),cd=0,k,j;
	dist[root]=0;
	dfs(root,root);
	j=root;
	loop(i,1,n+1){
		if(mark[i]){
			if(dist[i]>cd){
				cd=dist[i];
				j=i;
			}
		}
	}
	cd=dist[j]=0;
	dfs(j,j);
	k=j;
	loop(i,1,n+1){
		if(mark[i]){
			if(dist[i]>cd){
				cd=dist[i];
				k=i;
			}
		}
	}
//	trace1(cd);
	ans-=cd;
	int ve=min(j,k);
	cout<<ve<<"\n"<<ans<<"\n";
	return;
}
int main(){
	int n,m,u,v,x;
	cin>>n>>m;
	graph=vvi(n+1);
	loop(i,1,n){
		cin>>u>>v;
		graph[u].PB(v);
		graph[v].PB(u);
		deg[u]++;deg[v]++;
	}
	loop(i,0,m){
		cin>>root;
		mark[root]=1;
	}
	solve(n);
	return 0;
}
