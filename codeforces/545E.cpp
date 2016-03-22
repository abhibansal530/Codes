//Abhishek Bansal
//Paths and Trees
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
typedef pair<lli,int> llii;
typedef vector<vii>vvii;
const lli inf=lli(1e16);
const int size=300001;
vvii graph;
lli d[size];
int visited[size];
map<ii,int> edges;
bool present[size];
int parent[size];
int wt[size];
void keep(int u,int v){
	if(v<u)swap(u,v);
	int j=edges[MP(u,v)];
	present[j]=true;
	return;
}
void del(int u,int v){
	if(v<u)swap(u,v);
	int j=edges[MP(u,v)];
	present[j]=false;
	return;
}
//typedef std::priority_queue<llii,std::vector<llii>,order> my;
void dij(int s,int n){
	priority_queue<llii,vector<llii>,greater<llii> > q;
	SET(visited,0);
	loop(0,n+1){d[i]=inf;}
	d[s]=0;
	//cnt[s]=1;
	q.push(MP(d[s],s));
	while(!q.empty()){
		//ti++;
		llii t=q.top();
		q.pop();
		int v=t.S;
		lli di=t.F;
		if(!visited[v]){
			visited[v]=1;
			int sz=SZ(graph[v]);
			loop(0,sz){
				int ch=graph[v][i].F;
				int cd=graph[v][i].S;
				if(visited[ch])continue;
				if(d[v]+cd<d[ch]){
					d[ch]=d[v]+cd;
					//cnt[ch]=cnt[v]+1;
					q.push(MP(d[ch],ch));
					if(parent[ch]!=-1){
						del(ch,parent[ch]);
					}
					parent[ch]=v;
					keep(ch,v);
				}
				else if(d[v]+cd==d[ch]&&d[ch]!=inf){
					/*if(cnt[v]+1>cnt[ch]){
					  del(ch,parent[ch]);
					  keep(ch,v);
					//parent[ch]=v;
					cnt[ch]=cnt[v]+1;
					}*/
					//else if(cnt[v]+1==cnt[ch]){
					//printf("v:%d ch:%d\n",v,ch);
					int a,b;
					a=v;b=parent[ch];
					if(d[b]>d[a])swap(a,b);
					del(ch,b);
					keep(a,ch);
					parent[ch]=a;
					//cnt[ch]=cnt[a]+1;
					//}
				}
			}
		}
	}
	return;
}
int main(){
	int n,m,u,v,w,s;
	si(n);si(m);
	graph=vvii(n+1);
	loop(1,m+1){
		si(u);si(v);si(w);
		if(u<v)edges[MP(u,v)]=i;
		else edges[MP(v,u)]=i;
		wt[i]=w;
		graph[u].PB(MP(v,w));
		graph[v].PB(MP(u,w));
		present[i]=false;
	}
	SET(parent,-1);
	lli sum=0;
	si(s);
	dij(s,n);
	loop(1,m+1){
		if(present[i]){
			//printf("%d ",i);
			sum+=wt[i];
		}
	}
	printf("%lld\n",sum);
	loop(1,m+1){
		if(present[i]){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
