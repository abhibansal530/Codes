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
int A,B;
lli t;
lli f(int i){
	return A + (i-1)*B;
}
lli numop(int l,int r){
	return ((r-l+1)*(f(l)+f(r)))/2;
}
int bin(int lo,int hi,int l,int m){
	if(lo>hi)return -1;
	int mi;
	lli num;
	mi=(lo+hi)/2;
	if(numop(l,mi)>m*t)return bin(lo,mi-1,l,m);
	else{
		//printf("mi %d\n",mi);
	if(f(mi)>t)return bin(lo,mi-1,l,m);
	else{
		if(mi==hi||f(mi+1)>t)return mi;
		else {
			if(numop(l,mi+1)<=m*t)return bin(mi+1,hi,l,m);
			else return mi;
	}
	}
}
}
int main(){
	int n,l,m;
	si(A);si(B);si(n);
	while(n--){
		si(l);sll(t);si(m);
		int h = int(ceil(float(t-A)/float(B)))+1;
		//printf("%lld %lld\n",numop(l,8,m),numop(l,9,m));
		printf("%d\n",bin(l,h,l,m));
	}
	return 0;
}
