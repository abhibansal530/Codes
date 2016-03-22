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
	int n,k;
	lli x;
	map<lli,lli> cnt,cnt1,pre,post;
	vector<lli> a;
	si(n);si(k);
	loop(0,n){
		sll(x);
		cnt[x]=0;
		cnt1[x]=0;
		a.PB(x);
	}
	pre[0]=0;
	post[n-1]=0;
	cnt[a[0]]++;
	cnt1[a[n-1]]++;
	loop(1,n){
		if(a[i]%k==0){
			if(cnt.find(a[i]/k)!=cnt.end()){
			pre[i]=cnt[a[i]/k];
			}
			else pre[i]=0;
		}
		cnt[a[i]]++;
	}
	for(int i=n-2;i>=0;i--){
		if(cnt1.find(a[i]*k)!=cnt1.end()){
		post[i]=cnt1[a[i]*k];
		}
		else post[i]=0;
		cnt1[a[i]]++;
	}
	lli ans=0;
	loop(0,n){
		//trace2(pre[i],post[i]);
		ans+=1ll*pre[i]*1ll*post[i];
	}
	printf("%lld\n",ans);
	return 0;
}
