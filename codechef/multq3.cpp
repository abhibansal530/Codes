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
#define MAX 100005
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef struct node{
	int cnt,cnt1,cnt2;
}node;
node tree[3*MAX];
int lazy[3*MAX];
node merge(node a,node b){
	node tmp;
	tmp.cnt=a.cnt+b.cnt;
	tmp.cnt1=a.cnt1+b.cnt1;
	tmp.cnt2=a.cnt2+b.cnt2;
	return tmp;
}
node mn(int r0,int r1,int r2){
	node tmp;
	tmp.cnt=r0;
	tmp.cnt1=r1;
	tmp.cnt2=r2;
	return tmp;
}
void upd(int st,int l,int r,int v){
	int x=v%3;
	int r0,r1,r2;
	r0=tree[st].cnt;
	r1=tree[st].cnt1;
	r2=tree[st].cnt2;
	if(x==0)tree[st]=mn(r0,r1,r2);
	else if(x==1)tree[st]=mn(r2,r0,r1);
	else if(x==2)tree[st]=mn(r1,r2,r0);
	if(l!=r){
		lazy[2*st]+=v;
		lazy[2*st+1]+=v;
	}
	return;
}
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st].cnt=1;
		tree[st].cnt1=tree[st].cnt2=0;
		return;
	}
	int m=(l+r)/2;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
void update(int st,int l,int r,int i,int j,int v){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;
	}
	if(i>r||j<l)return;
	if(l>=i&&r<=j){
		upd(st,l,r,v);
		return;
	}
	int m=(l+r)/2;
	update(2*st,l,m,i,j,v);
	update(2*st+1,m+1,r,i,j,v);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
node query(int st,int l,int r,int i,int j){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;
	}
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	if(j<=m)return query(2*st,l,m,i,j);
	else if(i>m)return query(2*st+1,m+1,r,i,j);
	return merge(query(2*st,l,m,i,m),query(2*st+1,m+1,r,m+1,j));
}
inline void readint(int &a)
{
    register int c;
    a = 0;
    do c = getchar_unlocked(); while(c < '0');
    do{
    a = (a << 1) + (a << 3) + c - '0';
    c = getchar_unlocked();
    }while(c >= '0');
}
     
inline void printint(int a)
{
    char s[11];
    int t = -1;
    do{
    s[++t] = a % 10 + '0';
    a /= 10;
    }while(a > 0);
    while(t >= 0)putchar_unlocked(s[t--]);
    putchar_unlocked('\n');
}
int  main(){
	int n,q,op,a,b;
	readint(n);
	readint(q);
	int x=int(ceil(log2(n)))+1;
	int s=(1<<x);
	loop(0,s+1)lazy[i]=0;
	build(1,0,n-1);
	while(q--){
		readint(op);
		readint(a);
		readint(b);
		if(op==0)update(1,0,n-1,a,b,1);
		else printint(query(1,0,n-1,a,b).cnt);
	}
	return 0;
}
