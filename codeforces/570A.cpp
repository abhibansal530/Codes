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
int main(){
	lli votes[105][105],x;
	int n,m,win[105],j;
	si(n);si(m);
	loop(0,m){
		for(j=0;j<n;j++)votes[i][j]=0;
	}
	loop(0,m){
		for(j=0;j<n;j++){
			sll(x);
			votes[i][j]+=x;
		}
	}
	loop(0,m){
		lli max=0;
		for(j=0;j<n;j++){
			if(votes[i][j]>max){
				max=votes[i][j];
				win[i]=j;
			}
			if(votes[i][j]==max){
				if(j<win[i])win[i]=j;
			}
		}
	}
	int cnt[105],k;
	SET(cnt,0);
	loop(0,m){
		cnt[win[i]]++;
	}
	lli max=0;
	loop(0,n){
		if(cnt[i]>max){
			max=cnt[i];k=i;
		}
		if(cnt[i]==max){
			if(i<k)k=i;
		}
	}
	cout<<k+1<<endl;
	return 0;
}
