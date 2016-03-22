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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int a[1000005],tree[1000005],n;
int lg(int x){
	int cnt=0;
	while(x!=1){cnt++;x=x>>1;}
	return cnt;
}
int lvl(int x){
	return n-lg(x);

}
void build(int st,int l,int r,int lo,int hi){
	if(l>r||lo>hi)return;
	if(lo==hi){
		tree[st]=a[lo];return;
	}
	int m=(lo+hi)/2;
	build(2*st,l,m,lo,m);
	build(2*st+1,m+1,r,m+1,hi);
	if(lvl(st)%2)tree[st]=tree[2*st]|tree[2*st+1];
	else tree[st]=tree[2*st]^tree[2*st+1];
	return;
}
void upd(int st,int l,int r,int p,int b){
	int m=(l+r)/2;
	if(l==r){tree[st]=b;return;}
	else if(p<=m)upd(2*st,l,m,p,b);
	else upd(2*st+1,m+1,r,p,b);
	if(lvl(st)%2)tree[st]=tree[2*st]|tree[2*st+1];
	else tree[st]=tree[2*st]^tree[2*st+1];
}
int main(){
	int m,p,b;
	si(n);si(m);
	int l=1<<n;
	loop(0,l)si(a[i]);
	build(1,0,l-1,0,l-1);
	while(m--){
		si(p);si(b);
		p--;
		upd(1,0,l-1,p,b);
		printf("%d\n",tree[1]);
	}
	return 0;
}
