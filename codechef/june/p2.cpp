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
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
vector<vii> p;
int vert[10005];
pair<double,int> ar[100005];
bool cmp(const pair<double,int>& p1,const pair<double,int>& p2){
	return p1.F<p2.F;
}
double area(int k){
	double ans=0;
	int n=vert[k];
	loop(1,n-1){
		lli x1=p[k][i].F-p[k][0].F;
		lli y1=p[k][i].S-p[k][0].S;
		lli x2=p[k][i+1].F-p[k][0].F;
		lli y2=p[k][i+1].S-p[k][0].S;
		lli pro=x1*y2-x2*y1;
		ans+=pro;
	}
	return abs(ans/2.0);
}
int main(){
	int n,x,y;
	int t;
	int out[100005];
	si(t);
	while(t--){
		si(n);
		p=vector<vii>(n+1);
		loop(0,n){
			si(vert[i]);
			for(int j=0;j<vert[i];j++){
				si(x);si(y);
				p[i].PB(MP(x,y));
			}
			ar[i]=MP(area(i),i);
		}
		sort(ar,ar+n,cmp);
		//loop(0,n)printf("%lf %d",ar[i].F,ar[i].S);
		//printf("\n");
		loop(0,n)out[ar[i].S]=i;
		loop(0,n)printf("%d ",out[i]);
		printf("\n");
	}
	return 0;
}
