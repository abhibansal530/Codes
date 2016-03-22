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
typedef vector<lli> vll;
vi::iterator it;
lli fun(int x,vi& v,vll& sum,int s){
	lli ans=0;
	it=upper_bound(all(v),x);
	int k=it-v.begin();
	k--;
	ans+=1ll*(k+1)*x-sum[k];
	if(k!=s-1){
		ans+=sum[s-1]-sum[k]-1ll*x*(s-k-1);
	}
	return ans;
}
int mod(int x){
	if(x>0)return x;
	return -1*x;
}
int main(){
	int n,x,t;
	si(t);
	lli ans=0;
	vll psum,ppsum;
	vi a,pair_sum;
	while(t--){
		ans=0;
		si(n);
		int s=(n*(n-1))/2;
		loop(0,n){
			si(x);
			a.PB(x);
		}
		loop(0,n){
			for(int j=i+1;j<n;j++){
				pair_sum.PB(a[i]+a[j]);
			}
		}
		sort(all(a));
		sort(all(pair_sum));
		psum.PB(a[0]);
		ppsum.PB(pair_sum[0]);
		loop(1,n){
			psum.PB(psum[i-1]+a[i]);
		}
		loop(1,s){
			ppsum.PB(ppsum[i-1]+pair_sum[i]);
		}
		loop(0,n){
			for(int j=i+1;j<n;j++){
				int tmp=a[i]+a[j];
				lli sum1=fun(tmp,pair_sum,ppsum,s);
				lli sum2=fun(a[i],a,psum,n)+fun(a[j],a,psum,n)-2*mod(a[i]-a[j]);
				ans+=sum1-sum2;
			}
		}
		printf("%lld\n",ans);
		psum.clear();
		ppsum.clear();
		a.clear();
		pair_sum.clear();
	}
	return 0;
}
