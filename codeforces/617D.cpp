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
int main(){
	int ans;
	ii a[5];
	loop(i,0,3){
		si(a[i].F);
		si(a[i].S);
	}
	sort(a,a+3);
	if((a[0].F==a[1].F&&a[1].F==a[2].F)||(a[0].S==a[1].S&&a[1].S==a[2].S)){
		ans=1;
	}
	else if(a[0].F==a[1].F){
		if(a[2].S<=a[0].S|a[2].S>=a[1].S)ans=2;
		else ans=3;
	}
	else if(a[1].F==a[2].F){
		if(a[0].S<=a[1].S||a[0].S>=a[2].S)ans=2;
		else ans=3;
	}
	else if(a[0].S==a[1].S){
		if(a[2].F<=a[0].F||a[2].F>=a[1].F)ans=2;
		else ans=3;
	}
	else if(a[1].S==a[2].S){
		if(a[0].F<=a[1].F||a[0].F>=a[2].F)ans=2;
		else ans=3;
	}
	else ans=3;
	cout<<ans<<endl;
	return 0;
}
