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
const int MAX = 100005,inf = INT_MAX;
int a[MAX],n;
int tree[4*MAX];
void build(int i,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[i]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(2*i,l,m);
	build(2*i+1,m+1,r);
	tree[i]=min(tree[2*i],tree[2*i+1]);
}
int query(int st,int l,int r,int i,int j){
	if(i>r)return inf;
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	if(j<=m)return query(2*st,l,m,i,j);
	else if(i>m)return query(2*st+1,m+1,r,i,j);
	else return min(query(2*st,l,m,i,j),query(2*st+1,m+1,r,i,j));
}
void solve(){
	si(n);
	loop(i,0,n)si(a[i]);
	build(1,0,n-1);
	int i=0,cnt=0,cmax=-1;
	while(i<n){
		cmax=max(cmax,a[i]);
		if(query(1,0,n-1,i+1,n-1)>=cmax){
			cmax=-1;
			cnt++;
		}
		++i;
	}
	printf("%d\n",cnt);
	return;
}
int main(){
	solve();
	return 0;
}
	
