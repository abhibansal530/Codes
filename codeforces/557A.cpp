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
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	lli n,mi1,mi2,mi3,ma1,ma2,ma3;
	sll(n);
	sll(mi1);sll(ma1);
	sll(mi2);sll(ma2);
	sll(mi3);sll(ma3);
	lli one=mi1,to=mi2,th=mi3;
	lli r=n-(one+to+th);
	if(r>0)one+=min(r,ma1-mi1);
	r=n-(one+to+th);
	if(r>0)to+=min(r,ma2-mi2);
	r=n-(one+to+th);
	if(r>0)th+=min(r,ma3-mi3);
	printf("%lld %lld %lld\n",one,to,th);
	return 0;
}
