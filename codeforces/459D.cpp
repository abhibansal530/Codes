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
int a[MAX],l[MAX],r[MAX];
map<int,int> cnt;
typedef struct BIT{
	int sz;
	lli tree[MAX];
	void init(int n){
		sz=n;
		SET(tree,0);
	}
	void update(int i,int v){
		while(i<=sz){
			//trace1(i);
			tree[i]+=1ll*v;
			i+=(i&(-i));
		}
		return;
	}
	int query(int i){
		int sum=0;
		while(i>0){
			sum+=tree[i];
			i-=(i&(-i));
		}
		return sum;
	}
}BIT;
int main(){
	int n;
	BIT b;
	si(n);
	b.init(n+1);
	lli ans=0,tmp;
	loop(i,0,n)si(a[i]);
	l[0]=1;
	cnt[a[0]]=1;
	loop(i,1,n){
		cnt[a[i]]++;
		l[i]=cnt[a[i]];
	}
	cnt.clear();
	r[n-1]=1;
	cnt[a[n-1]]=1;
	for(int i=n-2;i>=0;i--){
		cnt[a[i]]++;
		r[i]=cnt[a[i]];
	}
	for(int i=n-1;i>=0;i--){
		tmp=b.query(l[i]-1);
		ans+=tmp;
		b.update(r[i],1);
	}
	printf("%lld\n",ans);
	return 0;
}
