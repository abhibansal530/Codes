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
	int t,l;
	char s[100005];
	lli cnt[100005];
	si(t);
	while(t--){
		scanf("%s",s);
		l=strlen(s);
		lli ans=0;
		if(s[0]=='O')cnt[0]=0;
		else cnt[0]=1;
		loop(1,l){
			if(s[i]=='O')cnt[i]=cnt[i-1];
			else cnt[i]=cnt[i-1]+1;
		}
		loop(0,l){
			if(s[i]=='O')ans+=1ll*cnt[i]*(cnt[l-1]-cnt[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}