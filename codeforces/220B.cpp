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
const int MAX = 100005;
int ans=0,f[MAX],a[MAX],sz;
int cnt[MAX],n;
typedef struct node{
	int i,l,r;
}node;
node q[MAX];
bool cmp(node a,node b){
	if(a.l/sz==b.l/sz)return a.r<b.r;
	else return a.l<b.l;
}
void add(int i){
	if(a[i]>n)return;
	cnt[a[i]]++;
	if(cnt[a[i]]==a[i])ans++;
	if(cnt[a[i]]==a[i]+1)ans--;
}
void remove(int i){
	if(a[i]>n)return;
	cnt[a[i]]--;
	if(cnt[a[i]]==a[i]-1)ans--;
	else if(cnt[a[i]]==a[i])ans++;
}
int main(){
	int m,cl=0,cr=0,l,r;
	si(n);si(m);
	sz=sqrt(n);
	SET(cnt,0);
	loop(i,0,n) si(a[i]);
	loop(i,0,m){
		si(q[i].l);
		si(q[i].r);
		q[i].i=i;
	}
	sort(q,q+m,cmp);
	loop(i,0,m){
		l=q[i].l-1;
		r=q[i].r-1;
		while(cl<l){
			remove(cl);
			cl++;
		}
		while(cl>l){
			add(cl-1);
			cl--;
		}
		while(cr<=r){
			add(cr);
			cr++;
		}
		while(cr>r+1){
			remove(cr-1);
			cr--;
		}
		f[q[i].i]=ans;
	}
	loop(i,0,m)printf("%d\n",f[i]);
	return 0;
}
