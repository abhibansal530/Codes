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
	const int MAX=int(1e9);
	int maxl[100005],a[100004],maxr[100005];
	int n;
	si(n);
	loop(0,n)si(a[i]);
	loop(0,n){
		if(i!=0&&a[i]>a[i-1])maxl[i]=maxl[i-1]+1;
		else maxl[i]=1;
	}
	for(int j=n-1;j>=0;j--){
		if(j!=n-1&&a[j]<a[j+1])maxr[j]=maxr[j+1]+1;
		else maxr[j]=1;
	}
	int ans=1;
	if(n==1)ans=1;
	else{
		loop(0,n){
			if(!i){if(maxr[1]+1>ans)ans=maxr[1]+1;}
			if(i!=0&&i!=n-1){
				if(a[i+1]-a[i-1]>=2){
					if(maxl[i-1]+maxr[i+1]+1>ans)ans=maxl[i-1]+maxr[i+1]+1;}
				else{
					if(maxl[i-1]+1>ans)ans=maxl[i-1]+1;
					if(maxr[i+1]+1>ans)ans=maxr[i+1]+1;
				}
			}
			if(i==n-1){if(maxl[i-1]+1>ans)ans=maxl[i-1]+1;}
		}
	}
	printf("%d\n",ans);
	return 0;
}

