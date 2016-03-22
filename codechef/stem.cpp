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
map<string,int> cnt;
map<string,int>::reverse_iterator rit;
set<string> tmp;
int main(){
	string v[12];
	int n,t;
	si(t);
	while(t--){
		string ans="";
	si(n);
	loop(i,0,n){
		cin>>v[i];
	}
	loop(i,0,n){
		int l=SZ(v[i]);
		tmp.clear();
		loop(j,0,l){
			loop(k,1,l-j+1){
				if(tmp.find(v[i].substr(j,k))==tmp.end()){
					tmp.insert(v[i].substr(j,k));
					cnt[v[i].substr(j,k)]++;
				}
				//if(cnt[v[i].substr(j,k)]>i+1)cnt[v[i].substr(j,k)]--;
		}
	}
	}
	int le=0;
	TR(cnt,it){
		if(it->S==n)le=max(le,SZ(it->F));
	}
	TR(cnt,it)if(it->S==n&&SZ(it->F)==le){ans=it->F;break;}
	/*for(rit=cnt.rbegin();rit!=cnt.rend();++rit){
		if(rit->S==n&&SZ(rit->F)>=SZ(ans))ans=rit->F;
	}*/
	cout<< ans <<"\n";
	cnt.clear();
	}
	return 0;
}
