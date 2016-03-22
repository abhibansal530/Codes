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
	int n,a[100001];
	lli s[3];
	si(n);
	loop(0,n)
		si(a[i]);
	sort(a,a+n);
	/*loop(0,n)
		cout<<a[i]<<" ";
	cout<<endl;*/
	int j=n-1,k=0;
	lli ans=0;
	while(1){
		if(k==2){
			ans+=s[0]*s[1];
			k=0;
		}
		if(j<=0)
			break;
		if(a[j]==a[j-1]){
			s[k++]=a[j];
			j-=2;
		}
		else if(a[j-1]==a[j]-1){
			s[k++]=a[j-1];
			j-=2;
		}
		else
			j--;
	}
	cout<<ans<<endl;
	return 0;
}
