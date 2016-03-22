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
set<ii> s;
map<int,int> cnt;
int a[300005];
ii ans[300005];
int main(){
	int n,c=0;
	si(n);
	loop(i,0,n)si(a[i]);
	ans[0].F=0,ans[0].S=-1;
	loop(i,0,n){
		if(cnt[a[i]]==2)cnt[a[i]]=0;
		else if(cnt[a[i]]==1){
			auto it = s.find(MP(a[i],c));
			if(it==s.end())cnt[a[i]]=0;
		}
		cnt[a[i]]++;
		if(cnt[a[i]]==2){
			ans[c++].S=i;
			if(i!=n-1){
				ans[c].F=i+1;
				ans[c].S=-1;
			}
		}
		else if(cnt[a[i]]==1){
			s.insert(MP(a[i],c));
		}
	}
	if(c!=0&&ans[c-1].S!=n-1){
		ans[c-1].S=n-1;
	}
	if(c==0)c=-1;
	printf("%d\n",c);
	for(int i=0;i<c;++i){
		printf("%d %d\n",ans[i].F+1,ans[i].S+1);
	}
	return 0;
}

