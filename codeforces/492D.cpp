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
	int n,x,y,r,a;
	si(n);si(x);si(y);
	int van=0,vol=0;
	vector<string> ans;
	while(van<x&&vol<y){
		if(double(van+1)/double(x)<double(vol+1)/double(y)){ans.PB("Vanya");van++;}
		else if(double(van+1)/double(x)>double(vol+1)/double(y)){ans.PB("Vova");vol++;}
		else{ans.PB("Both");ans.PB("Both");van++;vol++;}
	}
	loop(0,n){
		si(a);
		cout<<ans[(a-1)%(x+y)]<<endl;
	}
	return 0;
}
