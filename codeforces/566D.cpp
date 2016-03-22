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
//***********************************END OF TEMPLATE*********************************************************************
const int MAX=200005;
int parent[MAX],rank[MAX];
int find(int u){
	if(parent[u]==u)return u;
	parent[u]=find(parent[u]);
	return parent[u];
}
void Union(int a,int b){
	int aa,bb;
	aa=find(a);
	bb=find(b);
	if(rank[aa]<rank[bb])parent[aa]=bb;
	else if(rank[bb]<rank[aa])parent[bb]=aa;
	else{
		parent[aa]=bb;
		rank[bb]++;
	}
}
void merge(int x,int y){
	int xx,yy;
	xx=find(x);
	yy=find(y);
	if(xx!=yy)Union(xx,yy);
}
int main(){
	int n,q,op,x,y;
	si(n);si(q);
	loop(0,n+1){parent[i]=i;rank[i]=1;}
	while(q--){
		si(op);si(x);si(y);
		if(op==1)merge(x,y);
		else if(op==2){
			loop(x,y){
				merge(i,i+1);
			}
		}
		else{
			if(find(x)==find(y))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
