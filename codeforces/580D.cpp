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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
lli a[20],c[20][20];
int n;
lli dp[1<<20][20],ans[1<<20];
void solve(){
	loop(1,n+1)dp[0][i]=1ll*0;
	int tmp;
	lli tmp2;
	int r=(1<<n);
	loop(0,r){
		for(int j=0;j<n;j++){
			tmp=(1<<j)&i;
			if(tmp==0){
				dp[i+(1<<j)][n-j]=a[n-j];
				for(int k=1;k<=n;k++){
					if((1<<(n-k))&i){
						dp[i+(1<<j)][n-j]=max(dp[i+(1<<j)][n-j],dp[i][k]+a[n-j]+c[k][n-j]);
					}
				}
//				trace3(i+(1<<j),n-j,dp[i+(1<<j)][n-j]);
			}
		}
		tmp2=0;
		for(int l=0;l<n;l++){
			if((1<<l)&i)tmp2=max(tmp2,dp[i][n-l]);
		}
		ans[i]=tmp2;
	}
}
int main(){
	int m,k,x,y;
	lli ret=0;
	loop(0,20){
		for(int j=0;j<20;j++)c[i][j]=1ll*0;
	}
	si(n);si(m);si(k);
	loop(1,n+1)sll(a[i]);
	loop(0,k){
		si(x);si(y);
		sll(c[x][y]);
	}
	solve();
	loop(0,(1<<n)){
		if(bitcount(i)==m)ret=max(ret,ans[i]);
	}
	cout<<ret<<'\n';
	return 0;
}
