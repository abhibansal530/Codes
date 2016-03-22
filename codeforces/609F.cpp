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
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 200005;
typedef struct node{
	int i;
	lli x,l;
}node;
bool cmp(node a,node b){
	return (a.x<b.x)||((a.x==b.x)&&a.l<b.l);
}
int pos[MAX],n;
lli tree[MAX<<2];
node frog[MAX];
ii ans[MAX];
multiset<ii> s;
void build(int st,int l,int r){
	if(l>r)return;
	else if(l==r){
		tree[st]=frog[l].l;
		pos[st]=l;
		return;
	}
	int m = (l+r)>>1;
	build(2*st,l,m);
	build(2*st+1,m+1,r);
	tree[st]=max(tree[2*st],tree[2*st+1]);
}
void update(int st,int l,int r,int i,int v){
	if(l==r){
		tree[st]=v;
		pos[st]=l;
		return;
	}
	int m = (l+r)>>1;
	if(i<=m)update(2*st,l,m,i,v);
	else update(2*st+1,m+1,r,i,v);
	tree[st]=max(tree[2*st],tree[2*st+1]);
}
int find(int st,int l,int r,int x){
	if(l>r)return -1;
	else if(l==r){
		if(tree[st]>=x){
			if(frog[pos[st]].x<=x)return pos[st];
			else return -1;
		}
		else return -1;
	}
	int m =(l+r)>>1;
	if(tree[2*st]>=x)return find(2*st,l,m,x);
	else return find(2*st+1,m+1,r,x);
}
int query(int x,int l){
	int a = find(1,0,n-1,x);
	if(a!=-1){
		frog[a].l+=l;
		update(1,0,n-1,a,frog[a].l);
		ans[frog[a].i].F+=l;
		ans[frog[a].i].S++;
		while(!s.empty()){
			auto it = s.lower_bound(MP(frog[a].x,-1));
			if(it!=s.end()&&it->F<=frog[a].l)
			{
				frog[a].l+=it->S;
				update(1,0,n-1,a,frog[a].l);
				ans[frog[a].i].F+=it->S;
				ans[frog[a].i].S++;
				s.erase(it);
			}
			else break;
		}
	}
	else s.insert(MP(x,l));
}
int main(){
	int m,x;
	lli l;
	si(n);si(m);
	loop(i,0,n){
		sll(frog[i].x);
		sll(frog[i].l);
		ans[i] = MP(frog[i].l,0);
		frog[i].l+=frog[i].x;
		frog[i].i=i;
	}
	sort(frog,frog+n,cmp);
	build(1,0,n-1);
	loop(i,0,m){
		si(x);sll(l);
		query(x,l);
	}
	loop(i,0,n){
		printf("%lld %lld\n",ans[i].S,ans[i].F);
	}
	return 0;
}
