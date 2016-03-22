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
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 2000005;
int up[MAX],down[MAX];
lli downpre[MAX][2];  //prefix sum of active down diagonals(0-even 1-odd)
void process(int n){
	int l=2*(n-1);
	downpre[l][1]=0;
	if(down[l]>0)downpre[l][0]=1;
	else downpre[l][0]=0;
	for(int i=l-1;i>=0;i--){
		if(i&1){
			downpre[i][0]=downpre[i+1][0];
			downpre[i][1]=downpre[i+1][1];
			if(down[i]>0)downpre[i][1]++;
		}
		else{
			downpre[i][1]=downpre[i+1][1];
			downpre[i][0]=downpre[i+1][0];
			if(down[i]>0)downpre[i][0]++;
		}
	}
}
int main(){
	int n,k,x,y,t;
	si(t);
	while(t--){
		lli cnt=0;
		si(n);si(k);
		SET(up,0);
		SET(down,0);
		loop(0,k){
			si(x);si(y);
			x--;y--;
			up[x+y]=1;
			down[x-y+n-1]=1;
		}
		process(n);
		loop(0,2*(n-1)+1){
			if(down[i]){
				if(i<=n-1)cnt+=i+1;
				else cnt+=2*n-(i+1);
			}
			if(up[i]){
				if(i<=n-1)cnt+=i+1;
				else cnt+=2*n-(i+1);
			}
		}
		//trace1(cnt);
		loop(0,2*(n-1)+1){
			if(up[i]){
				int k=i;
				if(k>n-1)k=2*(n-1)-k;
				int l=k+n-1;
				int r=n-k-1;
				int b=i&1;
				//trace2(l,r);
				if(n%2==0)b=1-b;
				lli num=downpre[r][b];
				if(l<2*(n-1))num-=downpre[l+1][b];
				//trace2(i,num);
				cnt-=num;
			}
		}
		printf("%lld\n",1ll*n*n-cnt);
	}
	return 0;
}
