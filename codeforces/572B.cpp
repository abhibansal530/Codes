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
#define bitcount(n) __builtin_popcount(n)
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
//***********************************END OF TEMPLATE*********************************************************************
const int MAX=100004;
int buy[MAX],sell[MAX];
int main(){
	SET(buy,0);
	SET(sell,0);
	int n,s,p,v;
	char c;
	vii fs,fb,my;
	si(n);si(s);
	loop(0,n){
		cin>>c>>p>>v;
		if(c=='B')buy[p]+=v;
		else sell[p]+=v;
	}
	loop(0,MAX){
		if(buy[i]!=0)fb.PB(MP(i,buy[i]));
		if(sell[i]!=0)fs.PB(MP(i,sell[i]));
	}
	sort(all(fb),greater<ii>());
	sort(all(fs));
	int sb=SZ(fb);
	int ss=SZ(fs);
	loop(0,min(s,ss)){
		//printf("S %d %d\n",fs[j].F,fs[j].S);
		my.PB(fs[i]);
	}
	sort(all(my),greater<ii>());
	int ne=SZ(my);
	loop(0,ne)printf("S %d %d\n",my[i].F,my[i].S);
	loop(0,min(s,sb)){
		printf("B %d %d\n",fb[i].F,fb[i].S);
	}
	return 0;
}
