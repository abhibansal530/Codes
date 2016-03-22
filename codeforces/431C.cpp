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
//***********************************END OF TEMPLATE*********************************************************************
const int MOD = int(1e9 + 7);
int dp[101][101],dp2[101][101];
int k,d;
void process(){
	loop(1,k+1)dp[1][i]=1;
	for(int i=2;i<101;i++){
		for(int j=0;j<=100;j++){
			if(dp[i-1][j]!=0){
				for(int l=1;l<=k;l++){
					if(j+l<=100){
						dp[i][j+l]+=dp[i-1][j];
						dp[i][j+l]%=MOD;
					}
				}
			}
		}
	}
	loop(1,d)dp2[1][i]=1;
	for(int i=2;i<101;i++){
		for(int j=0;j<=100;j++){
			if(dp2[i-1][j]!=0){
				for(int l=1;l<=d-1;l++){
					if(j+l<=100){
						dp2[i][j+l]+=dp2[i-1][j];
						dp2[i][j+l]%=MOD;
					}
				}
			}
		}
	}
}
int main(){
	int ans=0,n;
	si(n);si(k);si(d);
	loop(0,101){
		for(int j=0;j<101;j++)dp[i][j]=dp2[i][j]=0;
	}
	process();
	loop(1,n+1){
		ans+=(dp[i][n]+MOD-dp2[i][n])%MOD;
		ans%=MOD;
	}
	printf("%d\n",ans);
}
