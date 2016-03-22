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
	lli ans,sum,p0,p1,p2,s0,s1,s2;
}node;
node tree[4*MAX];
char a[MAX];
node merge(node a,node b){
	int l=a.sum%3;
	int r=b.sum%3;
	node tmp;
	tmp.sum=a.sum+b.sum;
	tmp.ans=a.ans+b.ans+a.s0*b.p0+a.s1*b.p2+a.s2*b.p1;
	if(l==0){
		tmp.p0=a.p0+b.p0;
		tmp.p1=a.p1+b.p1;
		tmp.p2=a.p2+b.p2;
	}
	else if(l==1){
		tmp.p0=a.p0+b.p2;
		tmp.p1=a.p1+b.p0;
		tmp.p2=a.p2+b.p1;
	}
	else{
		tmp.p0=a.p0+b.p1;
		tmp.p1=a.p1+b.p2;
		tmp.p2=a.p2+b.p0;
	}
	if(r==0){
		tmp.s0=b.s0+a.s0;
		tmp.s1=b.s1+a.s1;
		tmp.s2=b.s2+a.s2;
	}
	else if(r==1){
		tmp.s0=b.s0+a.s2;
		tmp.s1=b.s1+a.s0;
		tmp.s2=b.s2+a.s1;
	}
	else{
		tmp.s0=b.s0+a.s1;
		tmp.s1=b.s1+a.s2;
		tmp.s2=b.s2+a.s0;
	}
	return tmp;
}
node leaf(int v){
	node t;
	int r=v%3;
	t.sum=v;
	if(r==0){
		t.ans=1;
		t.p0=t.s0=1;
		t.p1=t.p2=t.s1=t.s2=0;
	}
	else{
		t.ans=0;
		if(r==1){
			t.p1=t.s1=1;
			t.p0=t.s0=t.p2=t.s2=0;
		}
		else{
			t.p2=t.s2=1;
			t.p0=t.s0=t.p1=t.s1=0;
		}
	}
	return t;
}
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st]=leaf(a[l]-'0');
		return;
	}
	int m=(l+r)/2;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
void update(int st,int l,int r,int i,int v){
	if(l==r){
		tree[st]=leaf(v);
		return;
	}
	int m=(l+r)/2;
	if(i<=m)update(2*st,l,m,i,v);
	else update(2*st+1,m+1,r,i,v);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
node query(int st,int l,int r,int i,int j){
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	if(j<=m)return query(2*st,l,m,i,j);
	else if(i>m)return query(2*st+1,m+1,r,i,j);
	return merge(query(2*st,l,m,i,m),query(2*st+1,m+1,r,m+1,j));
}
int main(){
	int n,m,op;
	int x,y;
	si(n);si(m);
	scanf("%s",a);
	build(1,0,n-1);
	while(m--){
		si(op);si(x);si(y);
		if(op==1){x--;update(1,0,n-1,x,y);}
		else {x--;y--;printf("%lld\n",query(1,0,n-1,x,y).ans);}
	}
	return 0;
}
