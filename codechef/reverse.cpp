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
#define inf 100000
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef vector<vii> vvii;
vvii graph;
int visit[100005],dist[100005];
void dij(int s,int n){
	SET(visit,0);
	loop(1,n+1)dist[i]=inf;
	priority_queue< ii,vii,greater<ii> > pq;
	dist[s]=0;
	pq.push(MP(dist[s],s));
	while(!pq.empty()){
		ii t=pq.top();
		pq.pop();
		if(!visit[t.S]){
			visit[t.S]=1;
			int s=SZ(graph[t.S]);
			loop(0,s){
				if(dist[graph[t.S][i].F]>dist[t.S]+graph[t.S][i].S){
					dist[graph[t.S][i].F]=dist[t.S]+graph[t.S][i].S;
					pq.push(MP(dist[graph[t.S][i].F],graph[t.S][i].F));
				}
			}
		}
	}
	return;
}
int main(){
	int n,m,u,v,w;
	si(n);si(m);
	graph=vvii(n+1);
	while(m--){
		si(u);si(v);
		graph[u].PB(MP(v,0));
		if(u!=v)graph[v].PB(MP(u,1));
	}
	dij(1,n);
	if(dist[n]==inf)printf("-1\n");
	else printf("%d\n",dist[n]);
	return 0;
}
