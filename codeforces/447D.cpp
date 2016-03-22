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
lli ansr[1000002],ansc[1000002];
int main(){
	priority_queue<int> row;
	priority_queue<int> col;
	int n,m,k,p,x,rsum[1005]={0},csum[1005]={0};
	lli max=lli(-1e18);
	si(n);si(m);si(k);si(p);
	loop(0,n){
		for(int j=0;j<m;j++){
			si(x);rsum[i]+=x;csum[j]+=x;
		}
	}
	loop(0,n)row.push(rsum[i]);
	loop(0,m)col.push(csum[i]);
	ansr[0]=0;
	loop(1,k+1){
		int t=row.top();
		ansr[i]=ansr[i-1]+t;
		row.pop();
		row.push(t-p*m);
	}
	ansc[0]=0;
	loop(1,k+1){
		int t=col.top();
		ansc[i]=ansc[i-1]+t;
		col.pop();
		col.push(t-p*n);
	}
	loop(0,k+1){
		lli t=ansr[i]+ansc[k-i]-1ll*p*i*(k-i);
		if(t>max)max=t;
	}
	printf("%lld\n",max);
	return 0;
}
