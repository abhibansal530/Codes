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
	int n,flag=1;
	ii a[100005];
	si(n);
	loop(0,n){
		si(a[i].F);
		si(a[i].S);
	}
	sort(a,a+n);
	loop(0,n-1){
		if(a[i+1].S<a[i].S){
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("Poor Alex\n");
	}
	else printf("Happy Alex\n");
	return 0;
}
