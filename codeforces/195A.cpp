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
int a,b,c;
int valid(int t){
	int flag=1;
	loop(t,c+t+1){
		if(b*i<a*(i-t)){flag=0;break;}
	}
	return flag;
}
int bin(int lo,int hi){
	int m=(lo+hi)/2;
	if(valid(m)){
		if(m==lo||!valid(m-1))return m;
		else return bin(lo,m-1);
	}
	else return bin(m+1,hi);
}
int main(){
	si(a);si(b);si(c);
	int m=(c*a)/b + 2;
	printf("%d\n",bin(0,m));
	return 0;
}
