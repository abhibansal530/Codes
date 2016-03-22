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
char a[1005][1005],ans[1005][1005];
int n,m;
int dx[] = {0,0,-1,1};
int dy[] ={-1,1,0,0};
int parent[MAX],rrank[MAX]={1},size[MAX];
int find(int u){
	if(parent[u]==u)return u;
	parent[u]=find(parent[u]);
	return parent[u];
}
void Union(int a,int b){
	int aa,bb;
	aa=find(a);
	bb=find(b);
	if(rrank[aa]<rrank[bb]){
		parent[aa]=bb;
		size[bb]+=size[aa];
	}
	else if(rrank[bb]<rrank[aa]){
		parent[bb]=aa;
		size[aa]+=size[bb];
	}
	else{
		parent[aa]=bb;
		size[bb]+=size[aa];
		rrank[bb]++;
	}
}
int get(int i,int j){
	return (m)*i + j;
}
void process(){
	loop(i,0,n){
		loop(j,0,m){
			if(a[i][j]=='*')continue;
			loop(k,0,4){
				if(j+dx[k]>=0&&j+dx[k]<m&&i+dy[k]>=0&&i+dy[k]<n){
					if(a[i+dy[k]][j+dx[k]]=='.'){
						int po = find(get(i,j));
						int pf = find(get(i+dy[k],j+dx[k]));
						if(po!=pf){
							Union(po,pf);
						}
					}
				}
			}
		}
	}
}
int solve(){
	set<int> s;
	loop(i,0,n){
		loop(j,0,m){
			if(a[i][j]=='.'){
				ans[i][j]='.';
				continue;
			}
			s.clear();
			for(int k=0;k<4;++k){
				if(j+dx[k]>=0&&j+dx[k]<m&&i+dy[k]>=0&&i+dy[k]<n){
					if(a[i+dy[k]][j+dx[k]]=='.')s.insert(find(get(i+dy[k],j+dx[k])));
				}
			}
			if(s.empty())ans[i][j]='1';
			else{
				int tmp=1;
				TR(s,it){
					tmp+=size[*it];
				}
				ans[i][j]='0' + (tmp)%10;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	loop(i,0,n){
		loop(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='.'){
				parent[get(i,j)]=get(i,j);
				size[get(i,j)]=1;
			}
		}
	}
	process();
	solve();
	loop(i,0,n)printf("%s\n",ans[i]);
	return 0;
}
