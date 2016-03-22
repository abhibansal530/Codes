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
vector< vii > graph;
int visited[102];
bool dfs(int u,int v,int c){
	visited[u]=1;
	if(u==v)
		return true;
	loop(0,SZ(graph[u])){
		if(graph[u][i].S==c&&!visited[graph[u][i].F]){
			if(dfs(graph[u][i].F,v,c)) return true;
	}
	}
	return false;
}
int main(){
	int n,m,ans;
	int u,v,c,q;
	SET(visited,0);
	si(n);
	si(m);
	graph=vector< vii >(n+1);
	loop(0,m){
		cin>>u>>v>>c;
		graph[u].PB(MP(v,c));
		graph[v].PB(MP(u,c));
	}
	cin>>q;
	while(q--){
		ans=0;
		cin>>u>>v;
		loop(1,m+1){
			if(dfs(u,v,i)){
				ans++;
			}
			SET(visited,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
