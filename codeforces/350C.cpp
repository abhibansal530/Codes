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
typedef struct pt{
	int x,y;
}pt;
int ab(int x){
	if(x>=0)return x;
	return -1*x;
}
pt mp(int x,int y){
	pt p;
	p.x=x;p.y=y;
	return p;
}
bool q1(pt a,pt b){
	return a.x<b.x||((a.x==b.x)&&(a.y<b.y));
}
bool q2(pt a,pt b){
	return a.x>b.x||((a.x==b.x)&&(a.y<b.y));
}
bool q3(pt a,pt b){
	return a.x>b.x||((a.x==b.x)&&(a.y>b.y));
}
bool q4(pt a,pt b){
	return a.x<b.x||((a.x==b.x)&&(a.y>b.y));
}
int cal(pt p){
	int ret=0;
	if(p.x!=0)ret++;
	if(p.y!=0)ret++;
	return 2*ret+2;
}
void solve(pt p){
	char xdir,ydir;
	if(p.x!=0){
		if(p.x<0)xdir='L';
		else xdir='R';
	}
	if(p.y!=0){
		if(p.y>0)ydir='U';
		else ydir='D';
	}
	if(p.x!=0)printf("1 %d %c\n",ab(p.x),xdir);
	if(p.y!=0)printf("1 %d %c\n",ab(p.y),ydir);
	printf("2\n");
	xdir=xdir=='L'?'R':'L';
	ydir=ydir=='U'?'D':'U';
	if(p.x!=0)printf("1 %d %c\n",ab(p.x),xdir);
	if(p.y!=0)printf("1 %d %c\n",ab(p.y),ydir);
	printf("3\n");
}
int main(){
	int n,x,y;
	vector<pt> v1,v2,v3,v4;
	lli steps=0;
	si(n);
	loop(0,n){
		si(x);si(y);
		steps+=1ll*cal(mp(x,y));
		if(x>=0&&y>=0)v1.PB(mp(x,y));
		else if(x<0&&y>=0)v2.PB(mp(x,y));
		else if(x<=0&&y<0)v3.PB(mp(x,y));
		else v4.PB(mp(x,y));
	}
	sort(all(v1),q1);
	sort(all(v2),q2);
	sort(all(v3),q3);
	sort(all(v4),q4);
	printf("%lld\n",steps);
	TR(v1,it)solve(*it);
	TR(v2,it)solve(*it);
	TR(v3,it)solve(*it);
	TR(v4,it)solve(*it);
	return 0;
}
