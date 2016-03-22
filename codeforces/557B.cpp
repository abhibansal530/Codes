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
	int n,w,min=int(1e9),x;
	int a[200005];
	si(n);si(w);
	loop(0,2*n){si(a[i]);}
	sort(a,a+2*n);
	double ans;
	if(a[n]>2*a[0])ans=(double)3*n*a[0];
	else ans=(double)1.5*n*a[n];
	if(ans>w)ans=(double)w;
	printf("%.6lf\n",ans);
	return 0;
}
