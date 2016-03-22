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
	int n,a[10000];
	int count[10000],max=0;
	SET(count,0);
	si(n);
	loop(0,n){si(a[i]);count[a[i]]++;if(a[i]>max)max=a[i];}
	for(int j=max;j>=0;j--){
		count[j]+=count[j+1];
	}
	loop(0,n)printf("%d ",count[a[i]+1]+1);
	printf("\n");
	return 0;
}
