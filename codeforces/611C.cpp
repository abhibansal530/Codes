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
char a[505][505];
int dp[505][505],dp2[505][505];
void pre(int w,int h){
	for(int r=0;r<h;++r){
		for(int c=1;c<w;++c){
			dp[r][c]=dp[r][c-1];
			if(a[r][c-1]=='.'&&a[r][c]=='.')dp[r][c]++;
		}
	}
	for(int c=0;c<w;++c){
		for(int r=1;r<h;++r){
			dp2[c][r]=dp2[c][r-1];
			if(a[r-1][c]=='.'&&a[r][c]=='.')dp2[c][r]++;
		}
	}
}
int query(int r1,int c1,int r2,int c2){
	int ret=0;
	r1--;r2--;c1--;c2--;
	for(int r=r1;r<=r2;++r)ret+=dp[r][c2]-dp[r][c1];
	for(int c=c1;c<=c2;++c)ret+=dp2[c][r2]-dp2[c][r1];
	return ret;
}
int main(){
	int h,w,r1,r2,c1,c2,q;
	si(h);si(w);
	loop(i,0,h){
		loop(j,0,w){
			cin>>a[i][j];
		}
	}
	pre(w,h);
	cin>>q;
	while(q--){
		cin>>r1>>c1>>r2>>c2;
		cout<<query(r1,c1,r2,c2)<<endl;
	}
	return 0;
}
