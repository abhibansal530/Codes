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
vi block;
int n,cnt[26];
const int MAX=100005;
char st[MAX];
void cntsort(int l,int r,int flag){  //flag=1 asc. else desc.
	SET(cnt,0);
	int k;
	for(int i=l;i<=r;i++){
		//trace1(i);
		cnt[st[i]-'a']++;
	}
	if(flag=1){
		k=0;
		loop(l,r+1){
			while(cnt[k]==0)k++;
			st[i]='a'+k;
			cnt[k]--;
		}
	}
	else{
		k=25;
		loop(l,r+1){
			while(cnt[k]==0)k--;
			st[i]='a'+k;
			cnt[k]--;
		}
	}
}
void process(){
	int s=int(sqrt(n));
	int numblocks=int(ceil(double(n)/double(s)));
	trace1(numblocks);
	loop(0,numblocks)block.PB(-1);
}
void query(int i,int j,int flag){
	int l,r,k;
	int s=int(sqrt(n));
	l=int(ceil(double(i)/double(s)));
	r=int(ceil(double(j)/double(s)));
	if(flag!=block[l]){
		k=l*s+s-1;
		if(block[l]==-1){
			trace2(i,k);
			cntsort(i,k,flag);
		}
		else{
			cntsort(l*s,k,block[l]);
			cntsort(i,k,flag);
			block[l]=-1;
		}
	}
	if(flag!=block[r]){
		k=r*s+s-1;
		trace1(k);
		if(block[r]==-1){
			cntsort(i,r*s+s-1,flag);
		}
		else{
			cntsort(r*s,r*s+s-1,block[r]);
			cntsort(i,r*s+s-1,flag);
			block[r]=-1;
		}
	}
	loop(l+1,r)block[i]=flag;
}
void update(){
	int s=int(sqrt(n));
	int numblocks=int(ceil(double(n)/double(s)));
	loop(0,numblocks){
		if(block[i]!=-1)cntsort(i*s,i*s+s-1,block[i]);
	}
}
int main(){
	char st[MAX];
	int q,l,r,flag;
	si(n);si(q);
	scanf("%s",st);
	process();
	while(q--){
		si(l);si(r);si(flag);
		l--;r--;
		query(l,r,flag);
	}
	update();
	printf("%s\n",st);
	return 0;
}
