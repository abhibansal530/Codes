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
typedef multiset<int,greater<int> > my;
int main(){
	int n,cnt[MAX],checked[MAX];
	ii a[MAX];
	lli sum[MAX],ans=INT_MAX,total=0;
	my s;
	my::iterator it;
	si(n);
	SET(sum,0);
	SET(cnt,0);
	SET(checked,0);
	loop(0,n){
		si(a[i].F);
		cnt[a[i].F]++;
	}
	loop(0,n){
		si(a[i].S);
		total+=a[i].S;
		sum[a[i].F]+=a[i].S;
	}
	sort(a,a+n);
	loop(0,n){
		if(checked[a[i].F]){
			s.insert(a[i].S);
			continue;
		}
		checked[a[i].F]=1;
		it=s.begin();
		int k=0;
		lli tmp=0;
		while(k<cnt[a[i].F]-1&&it!=s.end()){
			tmp+=*it;
			k++;it++;
		}
		//printf("cans. %lld\n",total-tmp-sum[a[i].F]);
		ans=min(ans,total-sum[a[i].F]-tmp);
		s.insert(a[i].S);
	}
	printf("%lld\n",ans);
	return 0;
}
