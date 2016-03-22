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
const int MAX = 10000;
int seive[MAX],rprime[MAX],pre[MAX];
int a,b;
bool check[MAX];
int div(int n){
	int r=sqrt(n),ret=0;
	loop(i,1,r+1){
		if(n%i==0){
			ret+=2;
			if(i==n/i)ret--;
		}
	}
	return ret;
}
void process(){
	int tmp,tmp2,cnt=0;
	SET(seive,1);
	loop(i,2,101){
		if(seive[i]){
			for(int j=i*i;j<MAX;j+=i)seive[j]=0;
		}
	}
	loop(i,578,721)if(seive[i])cnt++;
	trace1(cnt);
	int r=1000;
	pre[0]=pre[1]=0;
	loop(i,2,r+1){
		tmp=div(i);
		tmp2=tmp*(tmp-1)+1;
		if(seive[tmp2]){pre[i]=1;}
		pre[i]+=pre[i-1];
	}

}
int solve(){
	int x,y,j,cnt=0;
	loop(i,0,b-a+1){rprime[i]=a+i;check[i]=true;}
	int r=sqrt(b);
	loop(i,2,min(r,a)+1){
		if(seive[i]){
			x=a/i;
			y=x*i;
			if(y==a)j=0;
			else j=y+i-a;
			for(int l=j;l<=b-a;l+=i){
				check[l]=false;
			}
		}
	}
	loop(i,0,b-a+1)if(check[i])cnt++;
	x=sqrt(a);y=sqrt(b);
	trace2(cnt,pre[y]-pre[x-1]);
	return cnt+pre[y]-pre[x-1];
}
int main(){
	int t;
	process();
	cout<<div(576)<<endl;
	si(t);
	while(t--){
		si(a);si(b);
		printf("%d\n",solve());
	}
	return 0;
}
