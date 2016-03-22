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
vi v;
void conv(lli n,int b){
	v.clear();
	while(n>0){
		//	trace1(n);
		v.PB(n%b);
		n/=b;
	}
	//printf("h\n");
}
int check(){
	int s=SZ(v),flag=1;
	loop(0,s/2){
		if(v[i]!=v[s-1-i]){
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	int t;
	vector<lli> ans;
	si(t);
	while(t--){
		ans.clear();
		int b1,b2,cnt=0,c1,c2;
		si(b1);si(b2);
		for(lli i=1;i<lli(2e60);i++){
			conv(i,b1);
			c1=check();
			conv(i,b2);
			c2=check();
			if(c1&&c2){
				if(cnt<1000){ans.PB(i);cnt++;}
				else break;
			}
		}
		TR(ans,it)printf("%lld",*it);
		if(SZ(ans)>0)printf("\n");
	}
	return 0;
}
