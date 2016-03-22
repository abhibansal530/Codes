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
#define MAX 100005
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
//***********************************END OF TEMPLATE*********************************************************************
typedef struct node{
	int cnt,lazy;
}node;
node tree[27][MAX];
char s[MAX];
node merge(node a,node b){
	node tmp;
	tmp.cnt=a.cnt+b.cnt;
	tmp.lazy=-1;
	return tmp;
}
void build(int j,int st,int l,int r){
	if(l>r)return;
	if(l==r){
		if(s[l]=='a'+j)tree[j][l].cnt=1;
		else tree[j][l].cnt=0;
		tree[j][l].lazy=-1;
		return;
	}
	int m=(l+r)/2;
	build(j,2*st,l,m);
	build(j,2*st+1,m+1,r);
	tree[j][st]=merge(tree[j][2*st],tree[j][2*st+1]);
}
void upd(int j,int st,int l,int r,int v){
	tree[j][st].cnt=v*(r-l+1);
	if(l!=r){ //not a leaf
		tree[j][2*st].lazy=v;         //lazy propagation
		tree[j][2*st+1].lazy=v;
	}
}
void update(int k,int st,int l,int r,int i,int j,int v){
	if(tree[k][st].lazy!=-1){
		upd(k,st,l,r,tree[k][st].lazy);
		tree[k][st].lazy=-1;
	}
	if(i>r||l>j)return;
	if(l>=i&&r<=j){
		upd(k,st,l,r,v);
		return;
	}
	int m=(l+r)/2;
	update(k,2*st,l,m,i,j,v);
	update(k,2*st+1,m+1,r,i,j,v);
	tree[k][st]=merge(tree[k][2*st],tree[k][2*st+1]);
}
node query(int k,int st,int l,int r,int i,int j){
	if(tree[k][st].lazy!=-1){
		upd(k,st,l,r,tree[k][st].lazy);
		tree[k][st].lazy=-1;
	}
	if(l>=i&&r<=j)return tree[k][st];
	int m=(l+r)/2;
	if(j<=m)return query(k,2*st,l,m,i,j);
	else if(i>m)return query(k,2*st+1,m+1,r,i,j);
	return merge(query(k,2*st,l,m,i,m),query(k,2*st+1,m+1,r,m+1,j));
}
int main(){
	int le,q;
	int l,r,op,cntr;
	si(le);
	scanf("%s",s);
	//loop(0,26)build(i,1,0,le-1);
	build(0,1,0,le-1);
	printf("%d\n",query(0,1,0,le-1,0,le-1).cnt);
	/*loop(0,26){
		printf("%c:%d\n",'a'+i,query(i,1,0,le-1,0,le-1).cnt);
	}*/
	si(q);
	while(q--){
		si(l);si(r);si(op);
		if(op==1){
			cntr=l;
			loop(0,26){
				int tmp=query(i,1,0,le-1,l,r).cnt;
				update(i,1,0,le-1,0,le-1,0);
				//trace1(tmp);
				update(i,1,0,le-1,cntr,cntr+tmp-1,1);
				cntr+=tmp;
			}
		}
		else{
			cntr=r;
			loop(0,26){
				int tmp=query(i,1,0,le-1,l,r).cnt;
				update(i,1,0,le-1,0,le-1,0);
				//trace1(tmp);
				update(i,1,0,le-1,cntr-tmp+1,cntr,1);
				cntr-=tmp;
			}
		}
	}
	loop(0,le){
		for(int j=0;j<26;j++){
			if(query(j,1,0,le-1,i,i).cnt==1){
				s[i]='a'+j;
				break;
			}
		}
	}
	printf("%s\n",s);
	return 0;
}
