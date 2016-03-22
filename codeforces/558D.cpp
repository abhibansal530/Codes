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
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef pair<lli,lli> ll;
//***********************************END OF TEMPLATE*********************************************************************
int main(){
	int h,q,op,j;
	si(h);si(q);
	lli l,r;
	vector< vector<lli> > yes(2);
	vector<ll> no;
	while(q--){
		si(j);sll(l);sll(r);si(op);
		int m=h-j;
		lli tmp=(1<<m);
		lli low=tmp*l;
		lli hi=tmp*(r+1)-1;
		if(op){yes[0].PB(low);yes[1].PB(hi);}
		else no.PB(MP(low,hi));
	}
	if(SZ(yes[0])==0){yes[0].PB((1<<(h-1)));yes[1].PB(2*yes[0][0]-1);}
	sort(all(yes[0]),greater<lli>());
	sort(all(yes[1]));
	pair<lli,lli> ans;
	//trace2(yes[0][0],yes[1][0]);
	ans=MP(yes[0][0],yes[1][0]);
	if(ans.F>ans.S){
		printf("Game cheated!\n");
		return 0;
	}
	sort(all(no));
	int s;
	s=SZ(no);
	loop(0,s){
		if(no[i].F>=ans.F&&ans.F<=no[i].S)ans.F=no[i].S+1;
	}
	for(int j=s-1;j>=0;j--){
		if(ans.S>=no[j].F&&ans.S<=no[j].S)ans.S=no[j].F-1;
	}
	if(ans.F>ans.S){
		printf("Game cheated!\n");
	}
	else if(ans.F==ans.S)printf("%lld\n",ans.F);
	else printf("Data not sufficient!\n");
	return 0;
}
