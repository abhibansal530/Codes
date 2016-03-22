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
int n,a[1005],l;
double min(double a,double b){
	return a<b?a:b;
}
int main(){
	si(n);si(l);
	loop(0,n)si(a[i]);
	sort(a,a+n);
	int max=0;
	loop(0,n-1)if(a[i+1]-a[i]>max)max=a[i+1]-a[i];
	double d=double(max)/2;
	d=min(d,double(a[0]));
	d=min(d,double(l-a[n-1]));
	printf("%.9lf\n",d);
	return 0;
}
