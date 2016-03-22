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
	int count[100005];
	int x;
	SET(count,0);
	string s;
	cin>>s;
	int m;
	si(m);
	loop(0,m){
		si(x);
		count[--x]++;
	}
	int l=s.size();
	loop(1,l/2){
		count[i]+=count[i-1];
	}
	loop(0,l/2){
		if(count[i]%2==1)
			swap(s[i],s[l-i-1]);
	}
	cout<<s<<endl;
	return 0;
}
