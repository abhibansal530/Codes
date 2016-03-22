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

bool cmp(ii a,ii b){
	return a.S-a.F+1<b.S-b.F+1;
}
void bal(int l,int r){
	int flag=0;
	loop(l,r+1){
		if(s[i]!='\0')continue;
		if(flag==0){
			s[i]='(';
			flag=1;
		}
		else{
			s[i]=')';
			flag=0;
		}
	}
}
int main(){
	int t;
	int n,k,l,r;
	vii q;
	char s[3000];
	si(t);
	while(t--){
		si(n);si(k);
		loop(0,n+1)s[i]='\0';
		loop(0,k){
			si(l);si(r);
			q.PB(MP(l,r));
		}
		loop(0,k){
			s[q[i].F]='(';
			s[q[i].S]=')';
			for(int j=i+1;j<k;j++){
				if(q[j].F>q[i].S||q[j].S<q[i].F)continue;
				else if(q[j].F>=q[i].F&&q[j].S<q[i].S&&q[j].S<=q[i].S&&q[j].S>q[i].F)continue;
				else if(q[i].F>=q[j].F&&q[i].S<q[j].S&&q[i].S<=q[j].S&&q[i].S>q[j].F)continue;
				else if(q[j].F>=q[i].F&&q[j].F<q[i].S){
					//trace2(i,j);
					if(s[q[i].S+1]=='\0')s[q[i].S+1]='(';
					if(q[i].F!=q[j].F&&s[q[j].F-1]=='\0')s[q[j].F-1]=')';
				}
				else if(q[j].S<=q[i].S&&q[j].S>q[i].F){
					//trace2(i,j);
					if(s[q[i].F-1]=='\0')s[q[i].F-1]=')';
					if(q[i].S!=q[j].S&&s[q[j].S+1]=='\0')s[q[j].S+1]='(';
				}
			}
		}
		sort(all(q),cmp);
		int cnt=0;
		loop(0,n){
			if(s[i]=='\0')cnt++;
		}
		loop(
		s[n]='\0';
		printf("%s\n",s);
		q.clear();
	}
	return 0;
}
