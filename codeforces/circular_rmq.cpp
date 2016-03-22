//Abhishek Bansal
#include<bits/stdc++.h>
//#define endl '\n'
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
#define MAX 200005
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli a[MAX];
lli tree[4*MAX],lazy[4*MAX];
const lli inf=lli(1e17);
void build(int st,int l,int r){
	if(l>r)return;
	if(l==r){
		tree[st]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=min(tree[2*st],tree[2*st+1]);
}
void upd(int st,int l,int r,lli v){
	tree[st]+=v;
	if(l!=r){
		lazy[2*st]+=v;
		lazy[2*st+1]+=v;
	}
	return;
}
void update(int st,int l,int r,int i,int j,lli v){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;
	}
	if(i>r||l>j)return;
	if(l>=i&&r<=j){
		upd(st,l,r,v);
		return;
	}
	int m=(l+r)/2;
	update(2*st,l,m,i,j,v);
	update(2*st+1,m+1,r,i,j,v);
	tree[st]=min(tree[2*st],tree[2*st+1]);
}
lli query(int st,int l,int r,int i,int j){
	if(lazy[st]!=0){
		upd(st,l,r,lazy[st]);
		lazy[st]=0;
	}
	if(i>r||l>j)return inf;
	if(l>=i&&r<=j)return tree[st];
	int m=(l+r)/2;
	return min(query(2*st,l,m,i,j),query(2*st+1,m+1,r,i,j));
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,k,m,l,r;
	lli q,v;
	char s[10],c;
	si(n);
	loop(0,n)scanf("%lld",&a[i]);
	lli x=int(ceil(log2(n)))+1;
	int size=(1<<x);
	loop(0,size+1)lazy[i]=0;
	build(1,0,n-1);
	si(m);
	loop(0,m){
		scanf("%*c");
		scanf("%[^\n]s",s);
		k=strlen(s);
		if(k==3){
			l=s[0]-'0';
			r=s[2]-'0';
			if(l<=r)q=query(1,0,n-1,l,r);
			else q=min(query(1,0,n-1,0,r),query(1,0,n-1,l,n-1));
			//cout<<q<<endl;
			printf("%lld\n",q);
		}
		else{
			l=s[0]-'0';
			r=s[2]-'0';
			if(k==5)v=1ll*(s[4]-'0');
			else v=-1*1ll*(s[5]-'0');
			if(l<=r)update(1,0,n-1,l,r,v);
			else{
				update(1,0,n-1,0,r,v);
				update(1,0,n-1,l,n-1,v);
			}
		}
	}
	return 0;
}
