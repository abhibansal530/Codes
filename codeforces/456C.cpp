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
#define MAX 100002
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int main(){
	int n,cnt[MAX],x;
	set<ii,greater<ii> >s;
	set<ii,greater<ii> >::iterator it;
	SET(cnt,0);
	si(n);
	loop(0,n){
		si(x);
		cnt[x]++;
	}
	loop(0,MAX){
		if(cnt[i]>0){
			s.insert(MP(cnt[i],i));
		}
	}
	lli ans=0;
	TR(s,it){
		cout<<(*it).F<<" "<<(*it).S<<" ";
	}
	cout<<endl;
	while(!s.empty()){
		ii top=*s.begin();
		ans+=1ll*(top.F)*(top.S);
		if(cnt[top.S-1]>0){s.erase(MP(cnt[top.S-1],top.S-1));}
		if(cnt[top.S+1]>0){s.erase(MP(cnt[top.S+1],top.S+1));}
		s.erase(top);
	}
	printf("%lld\n",ans);
	return 0;
}
