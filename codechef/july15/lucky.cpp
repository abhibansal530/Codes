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
#define MAX 100005
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int ecnt(int a,int b){
	int cnt=0;
	while(a%b==0){
		cnt++;
		a/=b;
	}
	return cnt;
}
lli solve(int x){
	int cnt1,cnt2;
	cnt1=ecnt(x,2);
	cnt2=ecnt(x,5);
	if(cnt2<cnt1)return x;
	int cnt=cnt2-cnt1;
	lli ans=x;
	loop(0,cnt)ans*=4;
	return ans;
}
int main(){
	int a[MAX],n;
	si(n);
	loop(0,n)si(a[i]);
	loop(0,n){
		printf("%lld\n",solve(a[i]));
	}
	return 0;
}
