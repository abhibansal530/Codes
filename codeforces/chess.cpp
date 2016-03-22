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
int h,w,n;
const int MAX=200005;
const lli mod=1000000007;
lli fact[MAX],f[MAX],ans[MAX];
lli ncr(int n,int r){
	return (((fact[n]*f[r])%mod)*(f[n-r]))%mod;
}
lli pw(lli a, int b) {
	if (b==0) return 1LL;
	if (b&1) return (a*pw(a,b-1))%mod;
	long long x=pw(a,b/2);
	return (x*x)%mod;
}
lli fun(int r,int c){
	return ((ncr(r+c-2,r-1)%mod)*(ncr(h+w-r-c,h-c)%mod))%mod;
}
/*lli negmod(lli b){
	int c=-1*b;
	int n=int(ceil(double(c)/double(mod)));
	c=b+n*mod;
	return c%mod;
}*/
int main(){
	vii black;
	int r,c;
	f[0]=fact[0]=1;
	loop(1,MAX){
		fact[i]=(fact[i-1]*i)%mod;
		f[i]=pw(fact[i],mod-2);
	}
	si(h);si(w);si(n);
	loop(0,n){
		si(r);si(c);
		black.PB(MP(r,c));
	}
	sort(all(black));
	black.PB(MP(h,w));
	ans[0]=ncr(black[0].F+black[0].S-2,black[0].F-1);
	//trace1(ans[0]);
	loop(1,n+1){
		ans[i]=ncr(black[i].F+black[i].S-2,black[i].F-1);
		for(int j=0;j<i;j++){
			ans[i]=(ans[i]+mod-(ans[j]*ncr(black[i].F-black[j].F+black[i].S-black[j].S,black[i].F-black[j].F))%mod)%mod;
		}
	}
	printf("%lld\n",ans[n]);
}
