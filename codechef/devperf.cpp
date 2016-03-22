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
const int MAX = 1000005;
int n,m,depth[MAX];
char a[1002][1002];
int dx[]={0,0,-1,-1,-1,1,1,1};
int dy[]={-1,1,0,-1,1,0,-1,1};
vvi graph;
int cm,node;
void bfs(int u){
	cm=depth[u]=0;
	node = u;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		loop(i,0,SZ(graph[top])){
			int c = graph[top][i];
			if(depth[c]==-1){
				depth[c]=depth[top]+1;
				if(depth[c]>cm){
					cm=depth[c];
					node=c;
				}
				q.push(c);
			}
		}
	}
}
int get(int i,int j){
	i++;
	return (i-1)*m+j;
}
int cal(int r,int c){
	int u = get(r,c);
	bfs(u);
	SET(depth,-1);
	bfs(node);
	int dia = cm;
	int ret = dia/2;
	if(dia%2)ret++;
	return ret;
}

void addtograph(int r,int c){
	loop(i,0,8){
		if(c+dx[i]<m&&r+dy[i]<n&&a[r+dy[i]][c+dx[i]]=='*'){
			graph[get(r,c)].PB(get(r+dy[i],c+dx[i]));
		}
	}
}

int main(){
	int t;
	si(t);
	while(t--){
		int ans=0,k=0;
		si(n);si(m);
		graph = vvi(m*n+1);
		loop(i,0,n){
			loop(j,0,m)cin>>a[i][j];
		}
		loop(i,0,n){
			loop(j,0,m){
				if(a[i][j]=='*'){
					addtograph(i,j);
				}
			}
		}
		SET(depth,-1);
		loop(i,0,n){
			loop(j,0,m){
				if(a[i][j]=='*'&&depth[get(i,j)]==-1){
					ans=max(ans,++k + cal(i,j));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
