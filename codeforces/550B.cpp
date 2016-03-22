//Abhishek Bansal
//Codeforces: Preparing Olympiad
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
int c[20],l,r,x,n,a[20];
void bin(int n,int a[]){
	SET(a,0);
	int k=0;
	while(n){
		a[k++]=n%2;
		n/=2;
	}
	return;
}
int valid(int a[]){
	int min=10000000,max=0;
	lli sum=0;
	loop(0,n){
		if(a[i]){
			sum+=c[i];
			if(c[i]<min)min=c[i];
			if(c[i]>max)max=c[i];
		}
	}
	if(max-min>=x&&sum>=l&&sum<=r)return 1;
	return 0;
}
int main(){
	//int n,l,r,x,c[20];
	si(n);si(l);si(r);si(x);
	//int a[n];
	loop(0,n)si(c[i]);
	int m=int(pow(2,n));
	//cout<<m<<endl;
	lli cnt=0;
	loop(1,m){
		bin(i,a);
		if(valid(a)){cnt++;
			//for(int j=0;j<n;j++)printf("%d ",a[j]);
		//	printf("\n");
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
