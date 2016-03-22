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
const int MAX = 100005,MAX2 = log2(MAX);
vvi graph(MAX);
int h[MAX],P[MAX][MAX2],root;
void dfs(int u,int p){
	h[u]=h[p]+1;
	for(auto k:graph[u]){
		if(k!=p)dfs(k,u);
	}
}
void init(){
	for(int j=1;(1<<j)<=MAX2;++j){
		for(int i=0;i<MAX;++i){
			if(P[i][j-1]!=-1)
				P[i][j]=P[P[i][j-1]][j-1];
		}
	}
	h[root]=-1;
	dfs(root,root);
}
int query(int x,int k){
	if(P[x][0]==-1||h[x]<k)return 0;
	int l = log2(k);
	for(int i=l;i>=0;--i){
		if(k-(1<<i)>=0&&P[x][i]!=-1)x=P[x][i];
	}
	return x;
}
void update(int u,int p){
	P[u][0]=p;
	h[u]=h[p]+1;
	for(int j=1;(1<<j)<=h[u];++j){
		if(P[u][j-1]!=-1)P[u][j]=P[P[u][j-1]][j-1];
	}
}
void del(int u){
	P[u][0]=-1;
}
int main(){
	int n,x,y,q,op,k;
	si(n);
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX2;++j)P[i][j]=-1;
	}
	loop(i,0,n){
		si(x);si(y);
		P[x][0]=y;
		if(y==0)root=x;
		else{
			graph[x].PB(y);
			graph[y].PB(x);
		}
	}
	init();
	si(q);
	while(q--){
		si(op);
		if(op==0){
			si(y);si(x);
			update(x,y);
		}
		else if(op==1){
			si(x);
			del(x);
		}
		else{
			si(x);si(k);
			printf("%d\n",query(x,k));
		}
	}
	return 0;
}
