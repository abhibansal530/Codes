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
typedef struct edge{
	int u,v,w;
}edge;
edge edges[100004];
vvi graph;
int n,size[100004],depth[10005];
void dfs(int u,int p){
	size[u]=1;
	depth[u]=depth[p]+1;
	TR(graph[u],it){
		if(*it==p)continue;
		dfs(*it,u);
		size[u]+=size[*it];
	}
}
double solve(){
	int x;
	double ret=0,tot=double((n*(n-1)))/double(2);
	loop(i,0,n-1){
		if(depth[edges[i].u]>depth[edges[i].v])x=edges[i].u;
		else x=edges[i].v;
		double n1=size[x];
		double n2=n-n1;
		double tmp=n1*n2*double(edges[i].w);
		ret+=tmp;
	}
	printf("%.6lf\n",ret/tot);
}
int main(){
	int t;
	si(t);
	while(t--){
		si(n);
		graph=vvi(n+1);
		loop(i,0,n-1){
			si(edges[i].u);
			si(edges[i].v);
			si(edges[i].w);
			graph[edges[i].u].PB(edges[i].v);
			graph[edges[i].v].PB(edges[i].u);
		}
		depth[0]=-1;
		dfs(0,0);
		solve();
	}
	return 0;
}

