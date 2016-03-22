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
char a[20][20];
int n,m;
typedef struct Plus{
	ii ce,row,col;
	int getarea(){
		return abs(row.S-row.F)+1+abs(col.S-col.F);
	}
}Plus;
Plus make(ii ce,ii r,ii c){
	Plus ret;
	ret.ce=ce;
	ret.row=r;
	ret.col=c;
	return ret;
}
bool checkIntersection(Plus a,Plus b){  //true if not intersects
	//b in first quad.w.r.t a
	if(b.ce.F<a.ce.F&&b.ce.S>a.ce.S){
		return (b.row.F>a.ce.S||(b.row.F<=a.ce.S&&b.ce.F<a.col.F))&&(b.col.S<a.ce.F||(b.col.S>=a.ce.F&&b.ce.S>a.row.S));
	}
	//b in second quad. w.r.t a
	else if(b.ce.F<a.ce.F&&b.ce.S<a.ce.S){
		return (b.row.S<a.ce.S||(b.row.S>=a.ce.S&&b.ce.F<a.col.F))&&(b.col.S<a.ce.F||(b.col.S>=a.ce.F&&b.ce.S<a.row.F));
	}
	//b in third quad. w.r.t a
	else if(b.ce.F>a.ce.F&&b.ce.S<a.ce.S){
		return (b.col.F>a.ce.F||(b.col.F<=a.ce.F&&b.ce.S<a.row.F))&&(b.row.S<a.ce.S||(b.row.S>=a.ce.S&&b.ce.F>a.col.S));
	}
	//b in fourth quad. w.r.t a
	else if(b.ce.F>a.ce.F&&b.ce.S>a.ce.S){
		return (b.row.F>a.ce.S||(b.row.F<=a.ce.S&&b.ce.F>a.col.S))&&(b.col.F>a.ce.F||(b.col.F<=a.ce.F&&b.ce.S>a.row.S));
	}
	//b on +x axis w.r.t a
	else if(b.ce.F==a.ce.F&&b.ce.S>a.ce.S){
		return b.row.F>a.row.S;
	}
	//b on -x axis w.r.t a
	else if(b.ce.F==a.ce.F&&b.ce.S<a.ce.S){
		return b.row.S<a.row.F;
	}
	//b on +y axis w.r.t a
	else if(b.ce.F<a.ce.F&&b.ce.S==a.ce.S){
		return b.col.S<a.col.F;
	}
	//b on -y axis w.r.t. a
	else if(b.ce.F>a.ce.F&&b.ce.S==a.ce.S){
		return b.col.F>a.col.S;
	}
	//both centres coincide
	else return false;
}
vector<Plus> get(int i,int j){
	vector<Plus> ret;
	int up=0,left=0,down=0,right=0,l=100;
	int k  = i-1;
	while(k>=0&&a[k][j]=='G'){
		up++;k--;
	}
	k=i+1;
	l=min(l,up);
	while(k<n&&a[k][j]=='G'){
		down++;k++;
	}
	k=j-1;
	l=min(l,down);
	while(k>=0&&a[i][k]=='G'){
		left++;k--;
	}
	k=j+1;
	l=min(l,left);
	while(k<m&&a[i][k]=='G'){
		right++;k++;
	}
	l=min(l,right);
	for(int t = 0;t<=l;++t){
		Plus tmp = make(MP(i,j),MP(j-t,j+t),MP(i-t,i+t));
		ret.PB(tmp);
	}
	return ret;
}
int findmax(vector<Plus> a,vector<Plus> b){
	int ret = 0;
	loop(i,0,SZ(a)){
		loop(j,0,SZ(b)){
			if(checkIntersection(a[i],b[j])){
				ret=max(ret,a[i].getarea()*b[j].getarea());
			}
		}
	}
	return ret;
}					
int solve(){
	int ans = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='B')continue;
			vector<Plus> v1 = get(i,j);
			for(int k = i;k<n;++k){
				for(int l = j+1;l<m;++l){
					if(a[k][l]=='G'){
						vector<Plus> v2 = get(k,l);
						ans=max(ans,findmax(v1,v2));
					}
				}
			}
		}
	}
	return ans;
}
int main(){
	cin>>n>>m;
	loop(i,0,n){
		loop(j,0,m){
			cin>>a[i][j];
		}
	}
	printf("%d\n",solve());
	return 0;
}
