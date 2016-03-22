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
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
char g[1002][1002];
int ans[1002][1002],seen[1002][1002],n,m;
vii tmp,q;
int dfs(int l,int r){
	int cnt=0;
	seen[l][r]=1;
	//trace2(l,r);
	tmp.PB(MP(l,r));
	for(int i=0;i<4;++i){
		if(l+dy[i]>=0&&l+dy[i]<n&&r+dx[i]>=0&&r+dx[i]<m){
			if(g[l+dy[i]][r+dx[i]]=='*'){
				cnt++;
			}
			else if(g[l+dy[i]][r+dx[i]]=='.'&&!seen[l+dy[i]][r+dx[i]])cnt+=dfs(l+dy[i],r+dx[i]);
		}
	}
	return cnt;
}
void start(int l,int r){
	int tm=dfs(l,r);
	TR(tmp,it){
		ans[it->F][it->S]=tm;
	}
	tmp.clear();
}
int main(){
	int k,x,y;
	si(n);si(m);si(k);
	loop(i,0,n){
		loop(j,0,m){
			cin>>g[i][j];
			ans[i][j]=-1;
			seen[i][j]=0;
		}
	}
	loop(i,0,k){
		si(x);si(y);
		x--;y--;
		q.PB(MP(x,y));
	}
	TR(q,it){
		if(ans[it->F][it->S]==-1)start(it->F,it->S);
	}
	TR(q,it)cout<<ans[it->F][it->S]<<"\n";
	return 0;
}
