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
//***********************************END OF TEMPLATE*********************************************************************
const int inf=INT_MAX;
int main(){
	int t;
	int cl,c1,c2,i,l;
	string s1,s2;
	si(t);
	while(t--){
		cin>>s1;
		cin>>s2;
		l=SZ(s1);
		if(s1[0]=='#'&&s2[0]=='#'){
			printf("No\n");
			return 0;
		}
		int j=0,flag=-1,ans=0;
		cl=1;
		if(s1[0]=='.'){
			while(j<l){
			if(j==l-1){flag=1;break;}
			if(cl==1){
				if(s1[j+1]=='.')j++;
				else{
					if(s2[j+1]=='#'){flag=0;break;}
					else{cl=2;j++;ans++;}
				}
			}
			else{
				if(s2[j+1]=='.')j++;
				else{
					if(s1[j+1]=='#'){flag=0;break;}
					else{cl=1;j++;ans++;
					}
				}
			}
		}
		}
		else ans=inf;
		int tmp=ans;
		if(!flag)printf("No\n");
		else{
			j=0;cl=2;ans=0;
			if(s2[0]=='.'){while(j<l){
				if(j==l-1){flag=1;break;}
				if(cl==1){
					if(s1[j+1]=='.')j++;
					else{
						if(s2[j+1]=='#'){flag=0;break;}
						else{cl=2;j++;ans++;}
					}
				}
				else{
					if(s2[j+1]=='.')j++;
					else{
						if(s1[j+1]=='#'){flag=0;break;}
						else{cl=1;j++;ans++;
						}
					}
				}
			}
			}
			else ans=inf;
			printf("Yes\n%d\n",min(tmp,ans));
		}

	}
	return 0;
}
