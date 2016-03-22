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
#define loop(i,a,b) for(int i=a;i<b;i++)
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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 100005 + 1005;
char t[MAX],p[MAX];
int lp,lt,z[MAX];
void calz(){
	strcat(p,t);
	int L=-1,R=-1,l=lp+lt;
	for(int i=1;i<lp+lt;i++){
		int x=0,y=i;
		z[i]=0;
		if(i>=L&&i<=R){
			z[i]=min(z[i-L],R-i+1);
			x=z[i];
			y=i+z[i];
		}
		while(x<l&&y<l&&p[x]==p[y]){
			x++;y++;z[i]++;
		}
		if(i+z[i]-1>R){
			L=i;
			R=i+z[i]-1;
		}
	}
}
bool match(){
	for(int i=lp;i<lp+lt;i++){
		if(z[i]>=lp)return true;
	}
	return false;
}
int main(){
	int k,q;
	si(k);
	while(k--){
		scanf("%s",t);
		lt=strlen(t);
		si(q);
		while(q--){
			scanf("%s",p);
			lp=strlen(p);
			calz();
			bool res = match();
			if(res)printf("y\n");
			else printf("n\n");
		}
	}
	return 0;
}
