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
const int MAX=200005;
//***********************************END OF TEMPLATE*********************************************************************
lli val[MAX];  //contains val added added to each node
lli current[MAX];  //stores current val of each node
int dist[MAX]; //distance from root of each node
int st[MAX],fi[MAX],visited[MAX];  //starting and finishing time of each node
int ti=0;
vii buff;      //buffer for update query
int cursz=0;   //current size of buffer
vvi graph;
void dfs(int u,int p){         //to cal. dist,st and fi arrays
	dist[u]=dist[p]+1;
	st[u]=ti++;
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(dist[c]==-1)dfs(c,u);
	}
	fi[u]=ti++;
}
void update_tree(int r){
	SET(visited,0);
	loop(0,cursz)val[buff[i].F]+=1ll*buff[i].S;
	queue<int> q;
	int c,top,s;
	current[r]+=val[r];
	q.push(r);
	visited[r]=1;
	while(!q.empty()){
		top=q.front();
		q.pop();
		s=SZ(graph[top]);
		loop(0,s){
			c=graph[top][i];
			if(visited[c])continue;
			val[c]-=val[top];
			current[c]+=val[c];
			visited[c]=1;
			q.push(c);
		}
	}
	buff.clear();
	SET(val,0);
	cursz=0;
}
int dis(int u,int v){ //u is ancestor of v
	return dist[v]-dist[u];
}
lli query(int x){ //return query of second type for node x
	lli tmp=current[x];
	int cn;
	loop(0,cursz){
		cn=buff[i].F;
		if(st[x]>=st[cn]&&fi[cn]>=fi[x]){
			//trace2(x,cn);
			//trace1(dis(cn,x));
			if(dis(cn,x)%2)tmp-=1ll*buff[i].S;
			else tmp+=1ll*buff[i].S;
		}
	}
	return tmp;
}
int main(){
	int n,m,maxsz,u,v,op,x,va;
	si(n);si(m);
	graph=vvi(n+1);
	maxsz=int(sqrt(m));
	loop(1,n+1)sll(current[i]);
	SET(val,0);
	SET(dist,-1);
	loop(0,(n-1)){
		si(u);si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	dist[1]=0;
	dfs(1,1);
	loop(0,m){
		si(op);
		if(op==1){
			si(x);si(va);
			//val[x]+=va;
			buff.PB(MP(x,va));cursz++;
		}
		else{
			si(x);
			printf("%lld\n",query(x));
		}
		if(cursz>maxsz)update_tree(1);
	}
	return 0;
}
