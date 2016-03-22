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
int fun(int n,int a){
	int ans;
	ans=n/(a+1);
	int r=n%(a+1);
	if(r>=a)ans++;
	return ans;
}
int main(){
	set<int> s;
	set<int>::iterator it,it1;
	int n,k,a,flag=0,x;
	vi moves;
	si(n);si(k);si(a);
	s.insert(0);
	s.insert(n+1);
	int ans=fun(n,a);
	int m;
	si(m);
	loop(0,m){
		si(x);
		moves.PB(x);
	}
	int ANS;
	loop(0,m){
		it1=s.upper_bound(moves[i]);
		it=it1;
		it--;
		//trace2(*it,*it1);
		int num=fun((*it1-*it-1),a);
		ans-=num;
		int num1=fun((moves[i]-*it-1),a);
		int num2=fun((*it1-moves[i]-1),a);
		ans+=num1+num2;
		s.insert(moves[i]);
		if(ans<k){
			flag=1;
			ANS=i;
			break;
		}
	}
	if(flag)printf("%d\n",ANS+1);
	else printf("-1\n");
	return 0;
}
