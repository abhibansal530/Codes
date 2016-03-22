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
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli f(lli x,lli b,lli n){
	return x*x + b*x -n;
}
lli find(int lo,int hi,lli b,lli n){
	if(lo>hi)return -1;
	lli m =(lo+hi)/2;
	if(f(m,b,n)==0)return m;
	else{
		if(f(m,b,n)<0||m<0)return find(m+1,hi,b,n);
		else return find(lo,m-1,b,n);
	}
}
int s(lli x){
	int a=0;
	while(x){a+=x%10;x/=10;}
	return a;
}
bool is_int(double x){
	return x-floor(x)==0;
}
int main(){
	lli n,ans=-1,tmp;
	scanf("%lld",&n);
	lli m=sqrt(n)+1;
	for(lli i=0;i<91;i++){
		tmp=find(0,m,i,n);
		if(tmp!=-1&&s(tmp)==i){ans=tmp;break;}
	}
	printf("%lld\n",ans);
	return 0;
}
