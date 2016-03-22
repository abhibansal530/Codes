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
	int n,a[1005][2];
	si(n);
	loop(0,n){si(a[i][0]);si(a[i][1]);}
	int cntp=1,cntc=n;
	lli ans=0;
	while(cntp&&cntc){
		int max=0,k;
		loop(0,n){
			if(a[i][1]>max)k=i;
			else if(max==a[i][1])k=a[i][0]>a[k][0]?i:k;
		}
		cntc--;
		cntp+=a[k][1]-1;
		ans+=a[k][0];
		a[k][0]=a[k][1]=0;
	}
	printf("%lld\n",ans);
	return 0;
}
