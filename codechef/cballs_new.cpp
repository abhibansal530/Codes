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
const int MAX = 100005;
int a[MAX],sum[MAX],cnt[MAX],tot;
int findsum(int d){
	int ret = 0;
	for(int i=d,p=1;i<MAX;p=i,i+=d){
		ret+=(sum[i]-sum[p])*i;
	}
	ret+=cnt[1]*d;
	return ret-tot;
}
int main(){
	int t;
	si(t);
	while(t--){
		int n,ma=0,ans=INT_MAX;
		SET(cnt,0);
		sum[0]=0;
		tot=0;
		si(n);
		loop(i,0,n){
			si(a[i]);
			ma=max(ma,a[i]);
			tot+=a[i];
			cnt[a[i]]++;
		}
		loop(i,1,MAX)sum[i]=sum[i-1]+cnt[i];
		loop(i,2,ma+1){
			ans=min(ans,findsum(i));
		}
		if(ma==1)ans=n;
		printf("%d\n",ans);
	}
	return 0;
}