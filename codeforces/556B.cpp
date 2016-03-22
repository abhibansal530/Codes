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
int n;
int fun(int x,int y,int m){
	if(m==1){
		if(y>=x)return y-x;
		else return n-(x-y);
	}
	else if(m==0){
		if(y>x)return n-(y-x);
		else if(y<=x)return x-y;
	}
}
int main(){
	int x;
	vi moves;
	si(n);
	loop(0,n){
		si(x);
		moves.PB(fun(x,i,(i+1)%2));
	}
	sort(all(moves));
	if(moves[0]==moves[n-1])printf("Yes\n");
	else printf("No\n");
	return 0;
}
