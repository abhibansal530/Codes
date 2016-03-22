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
int flip[4*MAX],tree[4*MAX];
void upd(int st,int l,int r,int flag){
	if(!flag)return;
	else{
		tree[st]=(r-l+1)-tree[st];
		if(l!=r){
			flip[2*st]=!flip[2*st];
			flip[2*st+1]=!flip[2*st+1];
		}
	}
	return;
}
void update(int st,int l,int r,int i,int j){
	upd(st,l,r,flip[st]);
	flip[st]=0;
	if(l>j||i>r)return;
	if(l>=i&&r<=j){
		upd(st,l,r,1);
		return;
	}
	int m=(l+r)/2;
	update(2*st,l,m,i,j);
	update(2*st+1,m+1,r,i,j);
	tree[st]=tree[2*st]+tree[2*st+1];
}
int query(int st,int l,int r,int i,int j){
	upd(st,l,r,flip[st]);
	flip[st]=0;
	if(l>j||i>r)return 0;
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	return query(2*st,l,m,i,j)+query(2*st+1,m+1,r,i,j);
}
int main(){
	int n,q,op,a,b;
	si(n);si(q);
	int x=int(ceil(log2(n)))+1;
	int size=(1<<x);
	loop(0,size+1){tree[i]=0;flip[i]=0;}
	while(q--){
		si(op);si(a);si(b);
		if(op)printf("%d\n",query(1,0,n-1,a,b));
		else update(1,0,n-1,a,b);
	}
	return 0;
}
