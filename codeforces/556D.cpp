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
int main(){
	lli n,m,flag=0,l,r,ans[200005]={-1};
	ii a[200005];
	set<ii> s;
	vii isl,gaps;
	sll(n);sll(m);
	loop(0,n){sll(l);sll(r);isl.PB(MP(l,r));}
	loop(0,m){sll(a[i].F);a[i].S=i+1;}
	sort(a,a+m);
	loop(0,n-1)gaps.PB(MP(isl[i+1].F-isl[i].S,i));
	sort(all(gaps));
	lli j=0;
	loop(0,m){
		while(j<n-1){
			if(gaps[j].F<=a[i].F){
				int x=gaps[j].S;
				s.insert(MP(isl[x+1].S-isl[x].F,x));
				j++;
			}
			else break;
		}
		if(!s.empty()){
			ii top=*s.begin();
			if(a[i].F>top.F){flag=1;break;}
			else {ans[top.S]=a[i].S;s.erase(top);}
		}
	}
	loop(0,n-1){if(ans[i]==-1){flag=1;break;}}
	if(flag){printf("No\n");return 0;}
	printf("Yes\n");
	loop(0,n-1)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}
