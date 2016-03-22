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
	char s[1005];
	lli k,a[27],max=0;
	scanf("%s",s);
	sll(k);
	loop(0,26){sll(a[i]);if(a[i]>max)max=a[i];}
	lli val=0;
	lli l=lli(strlen(s));
	loop(0,l)val+=(i+1)*a[s[i]-'a'];
	//cout<<val<<endl;
	val+=((2*l+k+1)*k*max)/2;
	printf("%lld\n",val);
	return 0;
}
