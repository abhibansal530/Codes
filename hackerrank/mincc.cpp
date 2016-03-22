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
#define loop(i,a,b) for(int i=a;i<b;i++)
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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 200005;
int parent[MAX],Rank[MAX],wt[MAX];
int find(int u){
	if(parent[u]==u)return u;
	parent[u]=find(parent[u]);
	return parent[u];
}
void Union(int a,int b){
	int aa,bb;
	aa=find(a);
	bb=find(b);
	if(Rank[aa]<Rank[bb]){parent[aa]=bb;wt[bb]+=wt[aa];}
	else if(Rank[bb]<Rank[aa]){parent[bb]=aa;wt[aa]+=wt[bb];}
	else{
		parent[aa]=bb;
		wt[bb]+=wt[aa];
		Rank[bb]++;
	}
}
int main(){
	multiset<int> my;
	multiset<int>::iterator it,it1;
	int n,q,u,v,uu,vv;
	cin>>n>>q;
	SET(Rank,1);
	loop(i,1,n+1){
		cin>>wt[i];
		parent[i]=i;
		my.insert(wt[i]);
	}
	while(q--){
		cin>>u>>v;
		uu=find(u);
		vv=find(v);
		if(uu!=vv){
			it=my.find(wt[uu]);
			my.erase(it);
			it1=my.find(wt[vv]);
			my.erase(it1);
			Union(u,v);
			my.insert(wt[find(u)]);
		}
		printf("%d\n",*my.begin());
	}
	return 0;
}

