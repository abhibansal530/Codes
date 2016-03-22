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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mod(a) ((a)>0?(a):(-1*(a)))
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
vvi graph;
int c1=0,c2=0;
int c[1000];
void bfs(int s){
	int head=0,tail=-1,q[1000];
	c[s]=1;c1++;
	q[++tail]=s;
	while(tail>=head){
		int t=q[head];
		head++;
		int l=SZ(graph[t]);
		loop(0,l){
			if(c[graph[t][i]]==-1){
				c[graph[t][i]]=1-c[t];
				if(c[t]==1)c2++;
				else c1++;
			}
		}
	}
	return;
}
int main(){
	int n,m,u,v;
	int cnt1,cnt2;
	cnt1=cnt2=0;
	si(n);si(m);
	graph=vvi(n+1);
	while(m--){
		si(u);si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	SET(c,-1);
	loop(1,n+1){
		if(c[i]==-1){
			c1=c2=0;
			bfs(i);
			if(cnt1<=cnt2){cnt1+=max(c1,c2);cnt2+=min(c1,c2);}
			else{cnt1+=min(c1,c2);cnt2+=max(c1,c2);}
		}
	}
	int ans=mod(cnt1-cnt2);
	cout<<ans<<endl;
	return 0;
}
