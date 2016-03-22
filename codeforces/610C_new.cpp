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
vvi v(600);
vi mul(vi v,int k){
	vi ret;
	int l = SZ(v);
	loop(i,0,l){
		ret.PB(k*v[i]);
	}
	return ret;
}
void print(int k){
	int l = 1<<k;
	loop(i,0,l){
		loop(j,0,l){
			if(v[i][j]==1)printf("+");
			else printf("*");
		}
		printf("\n");
	}
}
int main(){
	int k,l;
	vi tmp;
	si(k);
	if(k==0){
		printf("+\n");
		return 0;
	}
	v[0].PB(1);
	v[0].PB(1);
	v[1].PB(1);
	v[1].PB(-1);
	for(int i = 2;i<=k;++i){
		l = 1<<(i-1);
		for(int j=l;j<2*l;++j){
			TR(v[j-l],it)v[j].PB(*it);
		}
		for(int j=0;j<l;++j){
			tmp = mul(v[j],1);
			int l = SZ(v[j]);
			TR(tmp,it)v[j].PB(*it);
		}
		for(int j = l;j<2*l;++j){
			tmp = mul(v[j],-1);
			TR(tmp,it){
				v[j].PB(*it);
			}
		}
	}
	print(k);
	return 0;
}
