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
typedef struct node{
	lli sum;
}node;
node tree[MAX];
int lazy[MAX],a[MAX];
const lli MOD=lli(1e9 + 9);
lli fn,fn1,f2n,f2n1;
lli f[2];
void fib(lli n,lli a[]){
	if(n==0){
		a[0]=1;
		a[1]=1;
		return;
	}
	fib(n/2,a);
	fn=a[0]%MOD;
	fn1=a[1]%MOD;
	f2n=((fn%MOD)*((2*fn1-fn)%MOD))%MOD;
	f2n1=((fn*fn)%MOD+(fn1*fn1)%MOD)%MOD;
	if(n%2==0){
		a[0]=f2n%MOD;
		a[1]=f2n1%MOD;
	}
	else{
		a[0]=f2n1%MOD;
		a[1]=(f2n+f2n1)%MOD;
	}
}
lli get_fibo(lli n){   //return nth fibonacci number
	fib(n,f);
	return f[0]%MOD;
}
lli fibsum(lli n){    //return sum of first n fibo numbers(starting from 0th)
	return ((get_fibo(n+1))%MOD-1+MOD)%MOD;
}
lli rangesum(lli l,lli r){  //return sum(Fibo(l)+.......Fibo(r)
	return (fibsum(r)+MOD-fibsum(l-1))%MOD;
}
node merge(node a,node b){
	node tmp;
	tmp.sum=(a.sum+b.sum)%MOD;
	return tmp;
}
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st]=a[l]%MOD;   //leaf node condition
		return;
	}
	int m=(l+r)/2;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
void upd(int st,int l,int r,lli v){
	tree[st]+=rangesum(v,v+r-l);   //update node st with value v
	tree[st]%=MOD;
	if(l!=r){ //not a leaf
		lazy[2*st]=;         //lazy propagation
		lazy[2*st+1]=;
	}
}
void update(int st,int l,int r,int i,int j,int v){
	if(!lazy[st]){
		upd(st,l,r,lazy[st]);
		//reset lazy[st]
	}
	if(i>r||l>j)return;
	if(l>=i&&r<=j){
		upd(st,l,r,i,j,v);
		return;
	}
	int m=(l+r)/2;
	update(2*st,l,m,i,j,v);
	update(2*st+1,m+1,r,i,j,v);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
node query(int st,int l,int r,int i,int j){
	if(!lazy[st]){
		upd(st,l,r,lazy[st]);
		//reset lazy[st]
	}
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	if(j<=m)return query(2*st,l,m,i,j);
	else if(i>m)return query(2*st+1,m+1,r,i,j);
	return merge(query(2*st,l,m,i,m),query(2*st+1,m+1,r,m+1,j));
}
