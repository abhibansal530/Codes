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
const int MAX = 100005;
const lli MOD = lli(1e9) + 7;
vvi graph,rgraph;
vi temp;
int visited[MAX],cost[MAX];
lli mi,cnt,ans=0,ways=1;
stack<int> st;
void dfs(int u){
	visited[u]=1;
	TR(graph[u],it){
		if(!visited[*it])dfs(*it);
	}
	st.push(u);
}
void rdfs(int u){
	visited[u]=1;
	temp.PB(u);
	if(cost[u]<mi)mi=cost[u];
	TR(rgraph[u],it){
		if(!visited[*it])rdfs(*it);
	}
}
int main(){
	int n,m,u,v;
	si(n);
	graph=vvi(n+1);
	rgraph=vvi(n+1);
	loop(i,0,n)si(cost[i+1]);
	si(m);
	while(m--){
		si(u);si(v);
		graph[u].PB(v);
		rgraph[v].PB(u);
	}
	SET(visited,0);
	loop(i,1,n+1){
		if(!visited[i])dfs(i);
	}
	SET(visited,0);
	while(!st.empty()){
		u=st.top();st.pop();
		if(!visited[u]){
			cnt=0;mi=INT_MAX;
			rdfs(u);
			TR(temp,it)if(cost[*it]==mi)cnt++;
			ways=(ways*cnt)%MOD;
			ans+=mi;
			temp.clear();
		}
	}
	printf("%lld %lld\n",ans,ways);
	return 0;
}
