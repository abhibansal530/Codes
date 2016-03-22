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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
char a[502][502];
int n,m,k,r,cnt=0;
int visited[502][502];
void dfs(int i,int j){
	if(cnt==r)return;
	visited[i][j]=1;
	cnt++;
	if(j+1<m&&a[i][j+1]=='.'&&!visited[i][j+1])dfs(i,j+1);
	if(j-1>=0&&a[i][j-1]=='.'&&!visited[i][j-1])dfs(i,j-1);
	if(i-1>=0&&a[i-1][j]=='.'&&!visited[i-1][j])dfs(i-1,j);
	if(i+1<n&&a[i+1][j]=='.'&&!visited[i+1][j])dfs(i+1,j);
}
int main(){
	int  d=0;
	ii pos;
	si(n);si(m);si(k);
	loop(i,0,n){
		loop(j,0,m){
			cin>>a[i][j];
			visited[i][j]=0;
			if(a[i][j]=='.'){d++;pos=MP(i,j);}
		}
	}
	r=d-k;
	dfs(pos.F,pos.S);
	loop(i,0,n){
		loop(j,0,m){
			if(a[i][j]=='.'&&!visited[i][j])printf("X");
			else printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
