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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const lli MOD = lli(1e9 +7);
lli a[100005];
lli sum(lli m,lli d){
	lli tmp;
	if(m&1){
		tmp = ((m-1)/2)%MOD;
		tmp = (tmp*(d%MOD))%MOD;
		tmp = (1 + tmp)%MOD;
		return ((m%MOD)*(tmp))%MOD;
	}
	else{
		tmp = (((m-1)%MOD)*(d%MOD))%MOD;
		tmp = (2 + tmp)%MOD;
		return (((m/2)%MOD)*tmp)%MOD;
	}
}
lli solve(int x,lli m){
	lli ret = a[x]%MOD;
	for(lli i =1;i<=x;++i){
		lli tm = sum(m,i-1);
		ret +=(tm*(a[x-i]%MOD))%MOD;
		ret%=MOD;
	}
	return ret;
}
int main(){
	int n,x,t;
	si(t);
	while(t--){
		lli m;
		si(n);si(x);sll(m);
		x--;
		loop(i,0,n){
			sll(a[i]);
		}
		printf("%lld\n",solve(x,m));
	}
	return 0;
}
