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
const int MAX = 1000005;
int tree[MAX];
ii a[MAX],ans[MAX];
void build(int st,int l,int r){
	if(l>r)return;
	else if(l==r){
		tree[st]=a[l].S;
		return;
	}
	int m=(l+r)>>1;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=min(tree[2*st],tree[2*st+1]);
}
int query(int st,int i,int j,int l,int r){
	if(i>=l&&j<=r)return tree[st];
	int m=(i+j)>>1;
	if(l>m)return query(2*st+1,m+1,j,l,r);
	else if(r<=m)return query(2*st,i,m,l,r);
	else return min(query(2*st,i,m,l,r),query(2*st+1,m+1,j,l,r));
}
int main(){
	int n,k,ind=-1;
	si(n);si(k);
	loop(i,0,n){
		si(a[i].F);
		si(a[i].S);
	}
	sort(a,a+n);
	build(1,0,n-1);
	for(int i=0;i+k<=n;++i){
		int l=a[i+k-1].F;
		int r=query(1,0,n-1,i,i+k-1);
		if(l>r)continue;
		trace2(l,r);
		if(ind==-1)ans[++ind]=MP(l,r);
		else{
			if(l>ans[ind].S)ans[++ind]=MP(l,r);
			else ans[ind].S=max(ans[ind].S,r);
		}
	}
	printf("%d\n",ind+1);
	loop(i,0,ind+1)printf("%d %d\n",ans[i].F,ans[i].S);
	return 0;
}
