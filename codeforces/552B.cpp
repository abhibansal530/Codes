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
lli sum(int l){
	lli p=1;
	lli a=0;
	loop(1,l){
		a+=9*i*p;
		p*=10;
	}
	return a;
}
lli po(int j){
	lli a=1;
	loop(0,j)a*=10;
	return a;
}
lli ans(lli n){
	int p=10;
	int i,l;
	for(i=1;i<=12;i++){
		if(n/p==0){
			l=i;
			//cout<<i<<endl;
			break;
		}
		//cout<<n/p<<endl;
		p*=10;
	}
	//cout<<l<<endl;
	lli s =po(l-1);
	//cout<<s<<endl;
	lli a =(n-s+1)*l;
	if(l>1)a+=sum(l);
	return a;
}
int main(){
	lli n;
	sll(n);
	lli a =ans(n);
	printf("%lld\n",a);
	return 0;
}
