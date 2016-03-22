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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int main(){
	vii exam;
	int n,r,avg,a,b;
	lli sum=0;
	si(n);si(r);si(avg);
	loop(0,n){si(a);si(b);sum+=a;exam.PB(MP(b,a));}
	sort(all(exam));
	lli ans=0;
	lli req=1ll*n*avg-sum;
	int k=0;
	while(req>0){
		lli s=req<r-exam[k].S?req:r-exam[k].S;
		ans+=s*exam[k].F;
		req-=s;
		k++;
	}
	printf("%lld\n",ans);
	return 0;
}

