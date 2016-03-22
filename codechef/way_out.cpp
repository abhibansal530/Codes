//Abhishek Bansal
#include<bits/stdc++.h>
#define get getchar_unlocked
#define put putchar_unlocked
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
const int MAX=4000009;
int n;
typedef struct node{
	lli cnt;
}node;
node tree[MAX];
int lazy[MAX];
node merge(node a,node b){
	node tmp;
	tmp.cnt=a.cnt+b.cnt;
	return tmp;
}
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st].cnt=1ll*n;
		return;
	}
	int m=(l+r)>>1;
	build(st<<1,l,m);
	build((st<<1)+1,m+1,r);
	tree[st]=merge(tree[st<<1],tree[(st<<1)+1]);
}
void upd(int st,int l,int r,int v){
	tree[st].cnt-=1ll*v*1ll*(r-l+1);   //update node st with value v
	if(l!=r){ //not a leaf
		lazy[st<<1]+=v;         //lazy propagation
		lazy[(st<<1)+1]+=v;
	}
}
void update(int st,int l,int r,int i,int j,int v){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;
	}
	if(i>r||l>j)return;
	if(l>=i&&r<=j){
		upd(st,l,r,v);
		return;
	}
	int m=(l+r)>>1;
	update(st<<1,l,m,i,j,v);
	update((st<<1)+1,m+1,r,i,j,v);
	tree[st]=merge(tree[st<<1],tree[(st<<1)+1]);
}
node query(int st,int l,int r,int i,int j){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;   //reset lazy[st]
	}
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)>>1;
	if(j<=m)return query(st<<1,l,m,i,j);
	else if(i>m)return query((st<<1)+1,m+1,r,i,j);
	return merge(query(st<<1,l,m,i,m),query((st<<1)+1,m+1,r,m+1,j));
}
void gi(int &x) {
	register int c = get(); x = 0;
	int sn=1;
	for(;(c<48 || c>57);c = get())
		if(c=='-') sn=-1;
	for(;c>47 && c<58;c = get()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
	x*=sn;
}

void gii(lli &x) {
	register lli c = get(); x = 0;
	lli sn=1;
	for(;(c<48 || c>57);c = get())
		if(c=='-') sn=-1;
	for(;c>47 && c<58;c = get()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
	x*=sn;
}

void wi(int n) {
	int sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[10];
	int i = 9;
	if(!n) buf[i--] = 48;
	while(n) {
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) put('-');
	while(++i < 10) put(buf[i]);
}
void wii(lli n)
{
	lli sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[25];
	lli i = 24;
	if(!n) buf[i--] = 48;
	while(n) {
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) put('-');
	while(++i < 25) put(buf[i]);
}
int main(){
	int t;
	int h,l,r;
	gi(t);
	while(t--){
		gi(n);
		gi(h);
		lli ans=lli(1e15);
		build(1,0,n-1);
		SET(lazy,0);
		loop(0,n){
			gi(l);
			gi(r);
			update(1,0,n-1,l,r,1);
		}
		loop(0,n){
			if(i+h-1>n-1)break;
			lli tmp=query(1,0,n-1,i,i+h-1).cnt;
			//trace1(tmp);
			ans=min(ans,tmp);
		}
		wii(ans);
		printf("\n");
	}
	return 0;
}
