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
#define MAX 30005
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
vvi graph;
int vis[MAX];
int par[MAX],rank[MAX],ans[MAX],dist[MAX],mo,last,c;
void bfs(int u){
	queue<int> q;
	dist[u]=0;
	par[u]=u;
	if(vis[u]==0)vis[u]=1;
	last=u;
	q.push(u);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		int s=SZ(graph[top]);
		loop(0,s){
			c=graph[top][i];
			if(dist[c]==-1){
				q.push(c);
				if(vis[c]==0)vis[c]=1;
				dist[c]=dist[top]+1;
				if(mo==1){par[c]=u;}
				printf("c: %d p: %d\n",c,par[c]);
				last=c;
			}
		}
	}
	return;
}
int diameter(int u,int n){
	mo=1;
	bfs(u);
	int tmp=last;
	loop(0,n+1){
		if(vis[i]==1){dist[i]=-1;vis[i]=2;}
	}
	//SET(dist,-1);
	mo=-1;
	bfs(tmp);
	return dist[last];
}
int find(int x){
	if(par[x]==x)return x;
	par[x]=find(par[x]);
	return par[x];
}
void merge(int x,int y){
	int p1=find(x);
	int p2=find(y);
	if(p1==p2)return;
	if(rank[p1]<rank[p2])par[p1]=p2;
	else par[p2]=p1;
	if(rank[p1]==rank[p2])rank[p1]++;
	int tmp1,tmp2;
	tmp1=ans[p1]>0?(ans[p1]-1)/2 +1:0;
	tmp2=ans[p2]>0?(ans[p2]-1)/2+1:0;
	int tmp=tmp1+tmp2+1;
	ans[p1]=ans[p2]=max(max(ans[p1],ans[p2]),tmp);
	return;
}
int main(){
	int n,m,q,op,x,y,u,v,tmp;
	si(n);si(m);si(q);
	graph=vvi(n+1);
	loop(0,n+1){dist[i]=-1;rank[i]=1;par[i]=-1;vis[i]=0;}
	while(m--){
		si(u);si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	loop(1,n+1){
		if(dist[i]==-1){
			//bfs(i);
			//mo=1;
			//bfs(i);
			//tmp=last;
			//for(int j=0;j<=n;j++)dist[j]=-1;
			//mo=-1;
			//bfs(tmp);
			//ans[i]=dist[last];
			ans[i]=diameter(i,n);
			//printf("i:%d d:%d\n",i,ans[i]);
		}
	}
	//assert(par[7]!=7);
	loop(1,n+1)printf("i %d p %d\n",i,par[i]);
	while(q--){
		si(op);
		if(op==1){
			si(x);
			int p=find(x);
			printf("%d\n",ans[p]);
		}
		else{
			si(x);si(y);
			merge(x,y);
		}
	}
	return 0;
}
