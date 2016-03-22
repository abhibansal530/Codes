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
lli mod = lli(1e9) + 7;
const int MAX = 100005;
int a[MAX],b[MAX];
lli fun(int a,int b,int l){
	lli tmp=0,p=1,tmp2=0;
	for(int i=0;i<l;++i){
		tmp+=9*p;
		p*=10;
	}
	lli tot=tmp/a + 1;
	tmp=b;
	for(int i=0;i<l-1;++i){
		tmp*=10;
	}
	p=1;
	for(int i=0;i<l-1;++i){
		tmp2+=9*p;
		p*=10;
	}
	tmp2+=b*p;
	lli le = ceil(double(tmp)/double(a));
	lli r = tmp2/a;
//	trace4(tmp,tmp2,le,r);
	//trace2(le,r);
	tot-=(r-le+1);
	return tot%mod;
}
int main(){
	int n,k;
	lli ans=1;
	cin>>n>>k;
	loop(i,0,n/k){
		cin>>a[i];
	}
	loop(i,0,n/k)cin>>b[i];
	loop(i,0,n/k){
//		trace1(fun(a[i],b[i],k));
		ans=(ans*fun(a[i],b[i],k))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
