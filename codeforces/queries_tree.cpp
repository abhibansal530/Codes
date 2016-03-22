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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
const int MAX=100005;
vvi graph,level;
vii upquery; //stores update queries
int visited[MAX];
int dist[MAX];
int assign[MAX];
ii range[MAX];
int cnt=1;
lli crntsum[MAX]={0},ans[MAX]={0};
int lvlcnt[MAX]={0}; //stores number of nodes  at level i
lli lvlcoins[MAX]={0};  //store total coins to be added at level i
void bfs(int u){
	int q[MAX],head=0,tail=-1;
	dist[u]=0;
	q[++tail]=u;
	level[dist[u]].PB(u);lvlcnt[dist[u]]++;
	while(head<=tail){
		int t=q[head++];
		visited[t]=1;
		//printf("%d\n",t);
		int s=SZ(graph[t]);
		loop(0,s){
			int c=graph[t][i];
			if(!visited[c]){q[++tail]=c;dist[c]=dist[t]+1;level[dist[c]].PB(assign[c]);lvlcnt[dist[c]]++;}
		}
	}
}
void dfs(int u){
	visited[u]=1;
	//printf("v %d\n",u);
	assign[u]=cnt++;
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(!visited[c])dfs(c);
	}
	range[u]=MP(assign[u],cnt-1);
	return;
}
void updfs1(int u){    //updates crntsum for every node
	visited[u]=1;
	int l=dist[u];
	lli t=lvlcoins[l];
	crntsum[u]+=t;
	int s=SZ(graph[u]);
	loop(0,s){int c=graph[u][i];if(!visited[c])updfs1(c);}
	return;
}
void updfs2(int u){   //updates ans array(sum of nodes in every subtree)
	visited[u]=1;
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(!visited[c]){updfs2(c);ans[u]+=ans[c];}
	}
	ans[u]+=crntsum[u];
	return;
}
int bless(int x,int l,int lo,int hi){   //returns index of element just less than 'x' in vector level[l]
	if(lo>hi)return -1;
	int m=(lo+hi)/2;
	if(level[l][m]<x){
		if(m==hi||level[l][m+1]>=x)return m;
		else return bless(x,l,m+1,hi);
	}
	else return bless(x,l,lo,m-1);
}
int bmore(int x,int l,int lo,int hi){  //return index of element just greater than 'x' in vector level[l]
	if(lo>hi)return hi+1;
	int m=(lo+hi)/2;
	if(level[l][m]>x){
		if(m==lo||level[l][m-1]<=x)return m;
		else return bmore(x,l,lo,m-1);
	}
	else return bmore(x,l,m+1,hi);
}
int ncount(int x,int l){ //gives count of nodes in subtree of 'x' at level 'l'(meaured from root)
	int i=bless(range[x].F,l,0,lvlcnt[l]-1);
	int j=bmore(range[x].S,l,0,lvlcnt[l]-1);
	//printf("i:%d j:%d\n",i,j);
	return j-i-1;
}
void update(){  //if buffer size exceeds sqrt(M) then this will update whole tree and answers for each node(i.e. ans array)
	int s=SZ(upquery);
	loop(0,s){
		int l=upquery[i].F;
		int y=upquery[i].S;
		lvlcoins[l]+=1ll*y;
	}
	SET(visited,0);updfs1(1);
	SET(visited,0);SET(ans,0);updfs2(1);
	SET(lvlcoins,0);
	upquery.clear();
	return;
}
void chkdfs(int u){
	visited[u]=1;
	printf("crt:%lld ans:%lld\n",crntsum[u],ans[u]);
	int s=SZ(graph[u]);
	loop(0,s){int c=graph[u][i];if(!visited[c])chkdfs(c);}
}
int main(){
	int n,m,u,v,q,op,x,l,y;
	si(n);si(q);
	int max=sqrt(q);
	graph=vvi(n+1);
	m=n-1;
	while(m--){
		si(u);si(v);
		graph[u].PB(v);
		//graph[v].PB(u);
	}
	SET(visited,0);
	dfs(1);
	SET(visited,0);
	level=vvi(n+1);
	bfs(1);
	//loop(1,n+1)printf("%d:%d %d\n",i,range[i].F,range[i].S);
	while(q--){
		si(op);
		if(op==1){si(l);si(y);upquery.PB(MP(l,y));}
		else if(op==2){
			si(x);
			lli temp=ans[x];
			int s=SZ(upquery);
			loop(0,s){
				//printf("%d  %d\n",x,ncount(x,upquery[i].F));
				temp+=1ll*upquery[i].S*(1ll*ncount(x,upquery[i].F));
			}
			printf("%lld\n",temp);
		}
		if(SZ(upquery)>max){
			update();}
	}
	return 0;
}
