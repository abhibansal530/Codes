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
const int inf=INT_MAX;
typedef struct node{
	int min,max;
}node;
node tree[4*MAX];
int b[MAX],n;
node merge(node l,node r){
	node tmp;
	tmp.min=min(l.min,r.min);
	tmp.max=max(l.max,r.max);
	return tmp;
}
node mn(int a,int b){
	node t;
	t.min=a;t.max=b;
	return t;
}
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st].min=tree[st].max=b[l];
		return;
	}
	int m=(l+r)/2;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=merge(tree[2*st],tree[2*st+1]);
}
node query(int st,int l,int r,int i,int j){
	if(i>r||l>j)return mn(inf,-1*inf);
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	if(j<=m)return query(2*st,l,m,i,j);
	else if(i>m)return query(2*st+1,m+1,r,i,j);
	return merge(query(2*st,l,m,i,m),query(2*st+1,m+1,r,m+1,j));
}
double solve(int l,int r){
	int m,M,M1;
	node q=query(1,0,n-1,l,r);
	m=q.min;M=q.max;
	M1=max(query(1,0,n-1,0,l-1).max,query(1,0,n-1,r+1,n-1).max);
	double x=(double(M-m))/2.0;
	return max(double(M1),x)+double(m);
}
int main(){
	int q,l,r;
	si(n);
	loop(0,n)si(b[i]);
	build(1,0,n-1);
	si(q);
	while(q--){
		si(l);si(r);
		printf("%.1lf\n",solve(l,r));
	}
	return 0;
}
