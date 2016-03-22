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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
//***********************************END OF TEMPLATE*********************************************************************
lli fn,fn1,f2n,f2n1;
lli f[2];
void fib(lli n,lli a[]){
	if(n==0){
		a[0]=0;
		a[1]=1;
		return;
	}
	fib(n/2,a);
	fn=a[0];
	fn1=a[1];
	f2n=fn*(2*fn1-fn);
	f2n1=fn*fn+fn1*fn1;
	if(n%2==0){
		a[0]=f2n;
		a[1]=f2n1;
	}
	else{
		a[0]=f2n1;
		a[1]=f2n+f2n1;
	}
}
lli bin(lli lo,lli hi,lli k){  //finds index of fibo. no. just <=k
	lli m=(lo+hi)/2;
	fib(m,f);
	//trace1(f[0]);
	if(f[0]>k)return bin(lo,m-1,k);
	else if(f[0]==k) return m;
	else{
		if(m==hi)return m;
		else{
			//lli tmp=f[0];
			fib(m+1,f);
			//trace1(f[0]);
			if(f[0]>k)return m;
			else return bin(m+1,hi,k);
		}
	}
}
int main(){
	int t;
	lli n;
	si(t);
	while(t--){
		sll(n);
		lli ans=bin(2,100,n)-1;
		cout<<ans<<endl;
	}
	return 0;
}
