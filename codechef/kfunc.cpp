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
lli fun(lli a,lli c){
	lli tm=int(ceil(double(-1*a)/double(c)));
	return a+tm*c;
}
lli scale(lli a,lli c){
	lli tm=a/c;
	return a-c*tm;
}
lli gcd (lli a, lli b, lli & x, lli & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	lli x1, y1;
	lli d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
bool find_any_solution (lli a, lli b, lli c, lli & x0, lli & y0, lli & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	if(y0<0)y0=fun(y0,a/g);
	else y0=scale(y0,a/g);
	y0++;
	return true;
}
lli find(int r,lli a,lli d,lli L,lli R){
	lli x,y,g,k;
	lli ret;
	bool re=find_any_solution(9,-1*d,a-r,x,y,g);
//	trace3(r,x,y);
	if(!re||y>R)return 0;
//	trace1(y);
	if(d%9==0)k=1;
	else if(d%3==0)k=3;
	else k=9;
	if(y>=L){
		ret=(R-y)/k;
		ret++;
	}
	else{
		ret=(R-y)/k - (L-1-y)/k;
		//find till R - till L-1
	}
//	trace2(r,ret);
	return ret;
}
lli solve(lli a,lli d,lli L,lli R){
	lli ret=0,tmp;
	for(int i=0;i<9;++i){
		tmp=(i+8)%9;
		tmp*=find(i,a,d,L,R);
		ret+=tmp;
	}
	return ret+(R-L+1);
}
int main(){
	int t;
	lli a,d,l,r;
	si(t);
	while(t--){
		cin>>a>>d>>l>>r;
		cout<<solve(a,d,l,r)<<endl;
	}
	return 0;
}
