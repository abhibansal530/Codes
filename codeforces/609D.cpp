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
typedef pair<int,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 200005;
lli d[MAX],p[MAX],pmin[MAX],dmin[MAX],m,k;
ii g[MAX];
lli val(int day){
	lli ret=0;
	vector<lli> v;
	loop(i,0,m){
		if(g[i].F==1)v.PB(dmin[day]*g[i].S);
		else v.PB(pmin[day]*g[i].S);
	}
	sort(all(v));
	loop(i,0,k)ret+=1ll*v[i];
	return ret;
}
void solve(int day){
	int pi,di;
	loop(i,0,day){
		if(d[i]==dmin[day-1])di=i;
		if(p[i]==pmin[day-1])pi=i;
	}
	pi++;di++;
	vector<pair<lli,int> > v;
	loop(i,0,m){
		if(g[i].F==1)v.PB(MP(dmin[day]*g[i].S,i));
		else v.PB(MP(pmin[day]*g[i].S,i));
	}
	sort(all(v));
	loop(i,0,k){
		printf("%d ",v[i].S+1);
		if(g[v[i].S].F==1)printf("%d\n",di);
		else printf("%d\n",pi);
	}
}

int bs(int lo,int hi,lli s){
	if(lo>hi)return -1;
	if(lo==hi){
		if(val(lo)<=s)
			return lo;
		else return -1;
	}
	int day = (lo+hi)/2;
	lli mn = val(day);
	if(mn>s)return bs(day+1,hi,s);
	else return bs(lo,day,s);
}
int main(){
	int n;
	lli s;
	cin>>n>>m>>k>>s;
	loop(i,0,n)cin>>d[i];
	loop(i,0,n)cin>>p[i];
	loop(i,0,m){
		si(g[i].F);
		cin>>g[i].S;
	}
	dmin[0]=d[0];
	loop(i,1,n)dmin[i]=min(dmin[i-1],d[i]);
	pmin[0]=p[0];
	loop(i,1,n)pmin[i]=min(pmin[i-1],p[i]);
	int ans = bs(0,n-1,s);
	if(ans!=-1){
		ans++;
		cout<<ans<<endl;
		solve(ans);
	}
	else cout<<ans<<endl;
	return 0;
}
