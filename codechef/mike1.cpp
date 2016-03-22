//Abhishek Bansal
//December lunchtime 2013
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
lli max(lli a,lli b){
	return a>b?a:b;
}
int main(){
	int n,m,x,y;
	int a[505][505];
	si(n);si(m);
	loop(0,n){
		for(int j=0;j<m;j++)si(a[i][j]);
	}
	lli s1=0,s2=0;
	int l;
	si(l);
	while(l--){
		si(x);si(y);
		x--;y--;
		if(x<n&&y<m)s1+=a[x][y];
		else s1=-1;
		if(y<n&&x<m)s2+=a[y][x];
		else s2=-1;
	}
	printf("%lld\n",max(s1,s2));
	return 0;
}
