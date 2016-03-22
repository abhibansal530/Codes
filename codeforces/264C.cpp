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
typedef pair<lli,int> lii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 100005;
lli inf= lli(1e15);
int n,flag[MAX];
lli dp[MAX];
ii ball[MAX];
lii v[3];
bool cmp(lii a,lii b){
	return (a.F>b.F||(a.F==b.F)&&(a.S>b.S));
}
lli solve(int a,int b){
	lli tmp,ans=0;
	SET(flag,0);
	int l=0,r=0;
	loop(i,0,n){
		if(l!=ball[i].S&&r!=ball[i].S)tmp=max(dp[l],dp[r]);
		else {
			if(l==ball[i].S)tmp=dp[r];
			else tmp=dp[l];
		}
		//	trace1(tmp);
		if(!flag[ball[i].S]) {flag[ball[i].S]=1;dp[ball[i].S]=tmp+1ll*b*ball[i].F;}
		else dp[ball[i].S]=max(dp[ball[i].S],max(dp[ball[i].S]+1ll*a*ball[i].F,tmp+1ll*b*ball[i].F));
		//	trace2(i,dp[ball[i].S]);
		if(dp[ball[i].S]>dp[r]){
			if(ball[i].S!=r){
				l=r;
				r=ball[i].S;
			}
		}
		else if(dp[ball[i].S]>dp[l]){
			if(r!=ball[i].S){
				l=ball[i].S;
			}
		}
		//		trace2(l,r);
		ans=max(ans,dp[ball[i].S]);
	}
	return ans;
}
int main(){
	int a,b,q;
	si(n);si(q);
	loop(i,0,n)si(ball[i].F);
	loop(i,0,n)si(ball[i].S);
	while(q--){
		si(a);si(b);
		cout<<solve(a,b)<<'\n';
	}
	return 0;
}
