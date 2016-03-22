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
//***********************************END OF TEMPLATE*********************************************************************
const int MAX=1000005;
int a[MAX],b[MAX];
lli row[MAX];
int main(){
	int t;
	int n,h,l,r;
	lli tmp;
	si(t);
	while(t--){
		si(n);si(h);
		loop(0,n)a[i]=n;
		SET(b,0);
		loop(0,n){
			si(l);si(r);
			b[l]+=-1;
			if(r!=n-1)b[r+1]+=1;
		}
		loop(1,n){
			b[i]+=b[i-1];
		}
		loop(0,n)a[i]+=b[i];
		row[0]=1ll*a[n-1];
		loop(1,n){
			row[i]=1ll*(row[i-1]+1ll*a[n-1-i]);
		}
		lli ans=lli(1e15);
		loop(0,n){
			if(i+h-1>n-1)break;
			lli tmp=row[i+h-1];
			if(i>0)tmp-=row[i-1];
			ans=min(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
