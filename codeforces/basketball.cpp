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
const int size=200001;
lli MAX(lli a,lli b){
	lli m=a>b?a:b;
	return m;
}
int bin(lli a[],int lo,int hi,lli d){
	if(lo>hi)return -1;
	int m;
	m=(lo+hi)/2;
	if(a[m]>d){
		if(m==lo||a[m-1]<=d)return m;
		else return bin(a,lo,m-1,d);
	}
	else{
		if(m==hi||a[m+1]>d)return m+1;
		else return bin(a,m+1,hi,d);
	}
}
int main(){
	int n,m;
	vector<lli> vals;
	lli a[size],b[size];
	lli max=-1e7,fa,fb,d;
	si(n);
	loop(0,n)sll(a[i]);
	si(m);
	loop(0,m)sll(b[i]);
	sort(a,a+n);
	sort(b,b+m);
	lli ma=MAX(a[n-1],b[m-1]);
	lli k;
	loop(-1,n+m){
		if(i<0)k=0;
		else if(i<n)k=a[i];
		else k=b[i-n];
		int na=bin(a,0,n-1,k);
		if(na==-1)na=n;
		int nb=bin(b,0,m-1,k);
		if(nb==-1)nb=m;
		lli pa=2*na+3*(n-na);
		lli pb=2*nb+3*(m-nb);
		if(pa-pb>max){
			max=pa-pb;
			d=k;
			fa=pa;fb=pb;}
		if(pa-pb==max&&pa>fa){fa=pa;fb=pb;}
	}
	//printf("%d\n",bin(b,0,4,5));
	//printf("%lld\n",d);
	printf("%lld:%lld\n",fa,fb);
	return 0;
}

