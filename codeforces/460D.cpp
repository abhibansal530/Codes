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

int main(){
	lli l,r,k,f;
	vector<lli> ans;
	sll(l);sll(r);sll(k);
	if(l==r||k==1){
		printf("%lld\n",l);
		printf("1\n");
		printf("%lld\n",l);
		return 0;
	}
	else{
		int r1=int(log2(l));
		int r2=int(log2(r));
		if(r2-r1>=2){
			lli x =1<<(r1+1);
			f=1;
			ans.PB(x);ans.PB(x+1);
		}
		else{
			if(r1!=r2&&r!=l+1){
				f=1;
				if(l%2==0){
					ans.PB(l);ans.PB(l+1);
				}
				else{
					ans.PB(r);ans.PB(r+1);
				}
			}
			else if(r1!=r2&&r-l==1){
				ans.PB(l);ans.PB(r);
				f=l^r;
			}
			else{
				if(r-l>=2){
					f=1;
					if(l%2==0){
						ans.PB(l);ans.PB(l+1);
					}
					else{
						ans.PB(l+1);ans.PB(l+2);
					}
				}
				else{
					f=l^r;
					ans.PB(l);ans.PB(r);
				}
			}
		}
		printf("%lld\n2\n",f);
		printf("%lld %lld\n",ans[0],ans[1]);
		return 0;
	}
}
