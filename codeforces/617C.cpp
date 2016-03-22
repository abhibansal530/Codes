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
#define sq(x) ((x)*(x))
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
ii a[2005],p1,p2;
vector<lli> v1,v2;
lli dist(lli x,lli y,ii p){
	return (sq(x-p.F)+sq(y-p.S));
}
int main(){
	lli n,x1,y1,x2,y2;
	lli ans = lli(1e16),r1,r2;
	sll(n);
	sll(x1);sll(y1);
	sll(x2);sll(y2);
	loop(i,0,n){
		sll(a[i].F);
		sll(a[i].S);
	}
	loop(i,0,n){
		v1.PB(dist(x1,y1,a[i]));
		v2.PB(dist(x2,y2,a[i]));
	}
	for(int i=0;i<=n;++i){
		if(i!=n)r1=v1[i];
		else r1=0;
		r2=0;
		for(int j=0;j<n;++j){
			if(v1[j]>r1)
				r2=max(r2,v2[j]);
		}
		ans=min(ans,r1+r2);
	}
	printf("%lld\n",ans);
	return 0;
}
