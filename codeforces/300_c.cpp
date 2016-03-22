
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
int a[1000];
int bs(int lo,int hi,int low,int high){
	int v1,v2;
	if(lo>hi)return -1;
	int m=(lo+hi)/2;
	cout<<m<<endl;
	printf("lo:%d hi:%d\n",lo,hi);
	v1=a[low]+m-low;
	v2=a[high]+high-m;
	cout<<v1<<" "<<v2<<endl;
	if(v1==v2)return v1;
	else if(v1<v2)return bs(m+1,hi,low,high);
	else return bs(lo,m-1,low,high);
}
int main(){
	int n,m;
	int d,h,max,val,flag=0;
	vii v;
	si(n);si(m);
	loop(0,m){
		si(d);si(h);
		v.PB(MP(d,h));
	}
	int l=SZ(v);
	max=v[0].S;
	int c1=
	loop(0,l-1){
		val=(v[i].F-v[i].S+v[i+1].F+v[i+1].S)/2;
		if(val<v[i].F||val>v[i+1].F){
			flag=1;
			break;
		}
		val+=v[i].S-v[i].F;
		if(val>max)max=val;
	}
	if(m==1) cout<<v[0].S+n-v[0].F<<endl;
	else if(flag){printf("IMPOSSIBLE\n");}
	else cout<<max<<endl;
	return 0;
}
