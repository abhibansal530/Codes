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
#define bitcount(n) __builtin_popcount(n)
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
typedef pair<int,ii> node;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
bool cmp(node a,node b){
	return a.F<b.F;
}
int main(){
	int n,x;
	vi v;
	vector<node> g;
	vector<lli> ans;
	si(n);
	loop(0,n){
		si(x);v.PB(x);
	}
	if(n==1){
		printf("-1\n");return 0;
	}
	sort(all(v));
	loop(0,n-1)g.PB(MP((v[i+1]-v[i]),MP(v[i],v[i+1])));
	sort(all(g),cmp);
	if(n==2){
		ans.PB(v[0]-g[0].F);
		if(g[0].F!=0)ans.PB(v[1]+g[0].F);
		if(g[0].F!=0&&g[0].F%2==0)ans.PB(v[0]+g[0].F/2);
	}
	else{
		if(g[0].F==g[n-3].F&&g[n-2].F!=g[0].F){
			x=g[n-2].S.F+g[0].F;
			if(x+g[0].F==g[n-2].S.S)ans.PB(x);
		}
		else if(g[0].F==g[n-2].F){
			ans.PB(v[0]-g[0].F);
			if(g[0].F!=0)ans.PB(v[n-1]+g[0].F);
		}
	}
	printf("%d\n",SZ(ans));
	if(SZ(ans)>0){
		sort(all(ans));
		TR(ans,it)printf("%lld ",*it);
		printf("\n");
	}
	return 0;
}
