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
int pos[100]={-1},val[100]={-1},a[100][100];
int main(){
	vii found;
	int n;
	si(n);
	loop(i,0,n){
		loop(j,0,n){
			si(a[i][j]);
			pos[i]=val[i]=-1;
		}
	}
	int cnt=0,last,flag;
	int r,c;
	while(cnt!=n){
		for(r=0;r<n;++r){
			flag=1;last=-1;
			for(c=0;c<n;++c){
				if(r==c)continue;
				//trace1(pos[1]);
				if(pos[c]!=-1){
			//		trace3(r,c,pos[c]);
					if(a[r][c]!=val[c]){
						flag=0;
						break;
					}
				}
				if(pos[c]==-1){
					//trace2(r,c);
					if(last==-1)last=a[r][c];
					else if(last!=-1){
						if(last!=a[r][c]){
							flag=0;
							break;
						}
					}
				}
			}
	//		trace2(flag,last);
			if(flag){
	//			trace2(r,last);
				cnt++;
				pos[r]=1;
				val[r]=last;
				last=-1;
			}
		}
		//if(flag)cnt++;
	}
	int tmp=0;
	loop(i,0,n){
		if(val[i]!=-1)tmp+=val[i];
	}
	last = (n*(n+1))/2 - tmp;
	loop(i,0,n){
		if(val[i]==-1)val[i]=last;
	}
	for(int i=0;i<n;++i)printf("%d ",val[i]);
	printf("\n");
	return 0;
}
