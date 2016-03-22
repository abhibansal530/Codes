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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 4005;
int n,board[2001][2001];
lli best[MAX],sum[MAX],rsum[MAX],oddbest=-1*lli(1e15),evenbest=-1*lli(1e15);
ii odd,even;
int diag_num(int i,int j){
	return i+j-1;
}
lli getsum(int i,int j,int f){
	i--;j--;
	lli ret=0;
	if(!f){
	while(i>=0&&j<=n-1){
		ret+=1ll*board[i][j];
		i--;j++;
	}
	}
	else{
		while(i<=n-1&&j<=n-1){
			ret+=1ll*board[i][j];
			i++;j++;
		}
	}
	return ret;
}
void process(){
	int r,c;
	loop(1,2*n){
		if(i<=n){
			sum[i]=getsum(i,1,0);
		}
		else sum[i]=getsum(n,i-n+1,0);
	//	trace2(i,sum[i]);
	}
	loop(1,2*n){
		if(i<=n)rsum[i]=getsum(1,n+1-i,1);
		else rsum[i]=getsum(i-n+1,1,1);
	//	trace2(i,rsum[i]);
	}
	loop(1,2*n){
		if(i<=n){r=0;c=n-i;}
		else{c=0;r=i-n;}
		lli temp=-1*lli(1e15);
		int fr,fc;
		while(r<=n-1&&c<=n-1){
			if(sum[diag_num(r+1,c+1)]-board[r][c]>temp){
				temp=sum[diag_num(r+1,c+1)]-board[r][c];
				fr=r;fc=c;
			}
			r++;c++;
		}
		temp+=rsum[i];
	//	trace2(i,temp);
		if(i%2==1&&temp>oddbest){
			oddbest=temp;
			odd=MP(fr,fc);
		}
		else if(i%2==0&&temp>evenbest){
			evenbest=temp;
			even=MP(fr,fc);
		}
	}
}
int main(){
	si(n);
	loop(0,n){
		for(int j=0;j<n;j++)si(board[i][j]);
	}
	process();
	lli ans=evenbest+oddbest;
	printf("%lld\n",ans);
	printf("%d %d %d %d\n",odd.F+1,odd.S+1,even.F+1,even.S+1);
	return 0;
}

