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
#define MAX 100005
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
vvi graph;
bool isb;
int cnt,clcnt[2],color[MAX];
ii com[MAX];
lli nc3(lli n){
	return (n*(n-1)*(n-2))/6;
}
lli nc2(lli n){
	return (n*(n-1))/2;
}
void dfs(int u,int c){
	cnt++;
	clcnt[c]++;
	color[u]=c;
	int s=SZ(graph[u]);
	loop(0,s){
		int ch=graph[u][i];
		if(color[ch]==color[u])isb=false;
		else if(color[ch]==-1)dfs(ch,!c);
	}
}
int main(){
	int u,v;
	lli n,m;
	sll(n);sll(m);
	graph=vvi(n+1);
	loop(0,m){
		si(u);si(v);
		graph[u].PB(v);
		graph[v].PB(u);
	}
	if(m==0){
		printf("3 %lld\n",nc3(n));
		return 0;
	}
	int c=0,flag=0;
	SET(color,-1);
	loop(1,n+1){
		if(color[i]==-1){
			clcnt[0]=clcnt[1]=0;
			cnt=0;
			isb=true;
			dfs(i,0);
			if(!isb){flag=1;com[c].F=cnt;com[c].S=0;c++;}
			else{
				com[c].F=clcnt[0];
				com[c].S=clcnt[1];
				c++;
			}
		}
	}
	if(flag){printf("0 1\n");return 0;}
	int max=0,tmpcnt=0;
	lli fans=0;
	loop(0,c){
		if(com[i].F+com[i].S>max)max=com[i].F+com[i].S;
		if(com[i].F+com[i].S==2)tmpcnt++;
		fans+=nc2(com[i].F)+nc2(com[i].S);
	}
	if(max==2){
		printf("2 %lld\n",1ll*(n-2)*tmpcnt);
		return 0;
	}
	else{
		printf("1 %lld\n",fans);
		return 0;
	}
}
