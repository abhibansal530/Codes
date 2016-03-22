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
int fun(int a,int b){
	if(a>b)swap(a,b);
	int l=b-a;
	return min(l,10-l);
}
int main(){
	string s1,s2;
	int l;
	si(l);
	cin>>s1>>s2;
	int ans=0;
	loop(0,l){ans+=fun(s1[i]-'0',s2[i]-'0');}
	cout<<ans<<endl;
	return 0;
}
