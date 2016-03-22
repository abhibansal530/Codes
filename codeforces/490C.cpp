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
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
const int MAX = 1000002;
string s;
int pre[MAX],post[MAX];
lli a,b;
void solve(){
	int l=SZ(s),tmp=0,flag=0,k;
	loop(0,l){
		pre[i]=((10%a)*tmp)%a;
		pre[i]+=(s[i]-'0')%a;
		pre[i]%=a;
		tmp=pre[i];
	}
	tmp=0;
	for(int j=l-1;j>=0;j--){
		lli tmp2=modpow(10,l-1-j,b);
		tmp2*=(s[j]-'0')%b;
		tmp2%=b;
		post[j]=tmp2+tmp;
		post[j]%=b;
		tmp=post[j];
	}
	loop(0,l-1){
		if(pre[i]==0&&post[i+1]==0&&s[i+1]!='0'){flag=1;k=i;break;}
	}
	if(s[0]=='0'||l==1)flag=0;
	if(!flag){
		printf("NO\n");return;
	}
	printf("YES\n");
	loop(0,k+1)printf("%c",s[i]);
	printf("\n");
	loop(k+1,l)printf("%c",s[i]);
	printf("\n");
	return;
}
int main(){
	cin>>s;
	cin>>a>>b;
	solve();
	return 0;
}
