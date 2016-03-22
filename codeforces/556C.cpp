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
	int n,k,m,a[100005],l,j;
	lli cnt=0,chains=0;
	si(n);si(k);
	while(k--){
		si(m);
		loop(0,m)si(a[i]);
		if(a[0]!=1){cnt+=m-1;chains+=m;}
		else{
			loop(0,m){
				if(i!=m-1&&a[i+1]==a[i]+1)continue;
				else{
					cnt+=m-i-1;
					chains+=m-i;
					break;
				}
			}
		}
	}
	printf("%lld\n",cnt+chains-1);
	return 0;
}
