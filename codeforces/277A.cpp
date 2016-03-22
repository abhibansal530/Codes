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
typedef pair<int,ii> edge;
vector<edge> edges;
const int MAX=100005;
vvi lang,person;
//***********************************END OF TEMPLATE*********************************************************************
int visited[105];
void print(int n){
	int s=(n*(n-1))/2;
	loop(0,s){
		printf("%d %d %d\n",edges[i].F,edges[i].S.F,edges[i].S.S);
	}
}
void dfs(int u){
	visited[u]=1;
	int s=SZ(person[u]);
	loop(0,s){
		int cl=person[u][i];
		int s1=SZ(lang[cl]);
		for(int j=0;j<s1;j++){
			int cp=lang[cl][j];
			if(!visited[cp])dfs(cp);
		}
	}
}
int main(){
	int n,m,nl,x,cnt=0;
	si(n);si(m);
	lang=vvi(m+1);
	person=vvi(n+1);
	loop(0,n){
		si(nl);
		if(nl==0)cnt++;
		while(nl--){
			si(x);
			person[i+1].PB(x);
			lang[x].PB(i+1);
		}
	}
	int ans=0;
	SET(visited,0);
	loop(1,n+1){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}
	if(ans!=cnt)printf("%d\n",ans-1);
	else printf("%d\n",ans);
	return 0;
}
