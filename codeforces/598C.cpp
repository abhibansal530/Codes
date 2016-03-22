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
//typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
//***********************************END OF TEMPLATE*********************************************************************
typedef struct node{
	int F,S,id;
}node;
typedef vector< node > vii;
vii q1,q2,q3,q4;
node mp(int a,int b,int j){
	node tmp;
	tmp.F=a;
	tmp.S=b;
	tmp.id=j;
	return tmp;
}
bool cmp1(node a,node b){
	return a.F<b.F||(a.F==b.F&&a.S<b.S);
}
bool cmp2(node a,node b){
	return a.F<b.F ||(a.F==b.F&&a.S>b.S);
}
bool cmp3(node a,node b){
	return a.F>b.F ||(a.F==b.F&&a.S>b.S);
}
bool cmp4(node a,node b){
	return a.F>b.F ||(a.F==b.F&&a.S<b.S);
}
double mod(node a){
	double ret=double(a.F*a.F + a.S*a.S);
	ret=sqrt(ret);
	return ret;
}
double calangle(node a,node b){
	double tm=double(a.F*b.F + a.S*b.S);
	double ma=mod(a);
	double mb=mod(b);
	tm/=(ma*mb);
	return acos(tm);
}
int main(){
	trace1(acos(-1*0.5));
	int n,l,r,x,y;
	double mi=INT_MAX;
	si(n);
	loop(i,0,n){
		cin>>x>>y;
		if(y>=0){
			if(x<0)q1.PB(mp(x,y,i+1));
			else q2.PB(mp(x,y,i+1));
		}
		else {
			if(x>=0)q3.PB(mp(x,y,i+1));
			else q4.PB(mp(x,y,i+1));
		}
	}
	//printf("h\n");
	sort(all(q1),cmp1);
	sort(all(q2),cmp2);
	sort(all(q3),cmp3);
	sort(all(q4),cmp4);
	for(int i=0;i<SZ(q2);++i)q1.PB(q2[i]);
	for(int i=0;i<SZ(q3);++i)q1.PB(q3[i]);
	for(int i=0;i<SZ(q4);++i)q1.PB(q4[i]);
	/*TR(q1,it){
		cout<<it->F<<it->S<<" ";
	}
	cout<<endl;*/
	q1.PB(q1[0]);
	for(int i=0;i<SZ(q1);++i){
		double tmp=calangle(q1[i],q1[i+1]);
//		trace1(tmp);
		if(tmp<mi){
			mi=tmp;
			l=q1[i].id;
			r=q1[i+1].id;
		}
	}
	printf("%d %d\n",l,r);
	return 0;
}
