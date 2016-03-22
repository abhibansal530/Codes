//Abhishek Bansal
#include<bits/stdc++.h>
#define endl '\n'
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
#define bitcount(n) __builtin_popcount(n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
const int MAX = 400002;
int L[MAX],R[MAX];
typedef struct node{
	node* a[2];
}node;
node* init(node* r){
	r->a[0]=r->a[1]=NULL;
	return r;
}
node* insert(node* r,int n,int pos){
	if(pos<0)return r;
	int bit=(1<<pos)&n;
	if(bit!=0)bit=1;
	if(r->a[bit]==NULL){
		r->a[bit]=(node*)malloc(sizeof(node));
		r->a[bit]=init(r->a[bit]);
	}
	r->a[bit]=insert(r->a[bit],n,pos-1);
	return r;
}
int maxxor(node* r,int n,int pos){
	if(pos<0)return 0;
	int bit=(1<<pos)&n;
	if(bit!=0)bit=1;
	if(bit==0){
		if(r->a[1]!=NULL){
			int tmp=1<<(pos);
			//trace1(tmp);
			return tmp + maxxor(r->a[1],n,pos-1);
		}
		else return maxxor(r->a[0],n,pos-1);
	}
	else{
		if(r->a[0]!=NULL){
			int tmp2=1<<(pos);
			//trace1(tmp2);
			return tmp2 + maxxor(r->a[0],n,pos-1);
		}
		else return maxxor(r->a[1],n,pos-1);
	}
}
int main(){
	fast_io;
	int n,a[MAX];
	int ans=0,curr=0;
	readint(n);
	loop(0,n)readint(a[i]);
	node* root=(node*)malloc(sizeof(node));
	node* root2=(node*)malloc(sizeof(node));
	root=init(root);
	root2=init(root2);
	root=insert(root,0,31);
	loop(0,n){
		curr^=a[i];
		ans=max(ans,maxxor(root,curr,31));
		L[i]=ans;
		//trace1(ans);
		root=insert(root,curr,31);
	}
	curr=ans=0;
	root2=insert(root2,0,31);
	for(int j=n-1;j>=0;j--){
		curr^=a[j];
		ans=max(ans,maxxor(root2,curr,31));
		R[j]=ans;
		root2=insert(root2,curr,31);
	}
	int fans=0;
	loop(0,n-1){
		fans=max(fans,L[i]+R[i+1]);
	}
	printint(fans);
	return 0;
}