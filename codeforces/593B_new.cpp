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
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
vii p;
lli inf = lli(1e15);
int main(){
	int flag=0;
	lli n,x1,x2,k,b;
	cin>>n;
	cin>>x1>>x2;
	loop(i,0,n){
		cin>>k>>b;
		lli t1=k*x1+b;
		lli t2=k*x2+b;
		if(t1>t2)swap(t1,t2);
		p.PB(MP(t1,t2));
	}
	sort(all(p));
	int flag2=0,flag3=0;
	loop(i,0,n-1){
		if(p[i].F!=p[i+1].F){
			flag2=1;
			break;
		}
	}
	if(flag2==0&&p[0].S!=p[n-1].S){
		cout<<"NO"<<endl;
		return 0;
	}
	else if(flag2==0&&p[0].S==p[n-1].S){
		cout<<"YES"<<endl;
		return 0;
	}
	loop(i,0,n){
		auto it=lower_bound(p.begin()+i+1,p.end(),MP(p[i].S,1LL*(-1)));
		if(it==p.begin()+i+1)continue;
		else{
			flag=1;
			break;
		}
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
