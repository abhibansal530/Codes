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
const int MAX = 1000005;
const lli inf=lli(1e15);
int a[MAX],l[MAX],r[MAX];
void fun1(int n){
	stack<int> s;
	l[0]=-1;
	s.push(0);
	loop(1,n){
		while(!s.empty()&&a[s.top()]<=a[i])s.pop();
		if(s.empty())l[i]=-1;
		else l[i]=s.top();
		s.push(i);
	}
}
void fun2(int n){
	stack<int> s;
	r[n-1]=n;
	s.push(n-1);
	for(int j=n-2;j>=0;j--){
		while(!s.empty()&&a[s.top()]<=a[j])s.pop();
		if(s.empty())r[j]=n;
		else r[j]=s.top();
		s.push(j);
	}
}
void print(int a[],int n){
	loop(0,n)printf("%d ",a[i]);
	printf("\n");
}
int main(){
	int n,m,k,last;
	char c,d,w;
	lli num,cnt,cnt1;
	pair<int,lli> p;
	vector<pair<int,lli> > v;
	vector<pair<int,lli> >::iterator it,it1;
	vector<lli> f;
	map<int,int> index;
	map<int,int>::iterator it2;
	string ans="";
	si(n);si(m);
	loop(0,n){si(a[i]);}
	fun1(n);fun2(n);
	//print(l,n);
	//print(r,n);
	loop(0,n){
		lli cnt=1ll*(i-l[i])*1ll*(r[i]-i);
		it2=index.find(a[i]);
		if(it2!=index.end()){
			last=it2->S;
			if(l[i]<=last){
				cnt1=1ll*(last-l[last])*1ll*(r[i]-i);
				cnt-=cnt1;
			}
		}
		index[a[i]]=i;
		v.PB(MP(a[i],cnt));
	}
	/*TR(v,it){
		trace2(it->F,it->S);
	}*/
	sort(all(v));
	loop(0,n){
		if(i==0)f.PB(v[i].S);
		else f.PB(v[i].S+f[i-1]);
	}
	int j;
	while(m--){
		cin>>c>>k>>d;
		//trace3(c,k,d);
		if(c=='<'){
			p=MP(k,-1*inf);
			it=lower_bound(all(v),p);
			if(it==v.end())num=f[n-1];
			else if(it==v.begin())num=0;
			else {
				j=it-v.begin();
				num=f[j-1];
			}
			//trace1(num);
			//cout<<num<<endl;
			if(num%2==0){
				if(d=='C')w='D';
				else w='C';
			}
			else{
				if(d=='D')w='D';
				else w='C';
			}
			printf("%c",w);
			//ans+=w;
		}
		else if(c=='='){
			p=MP(k,-1*inf);
			it=lower_bound(all(v),p);
			p=MP(k,inf);
			it1=upper_bound(all(v),p);
			if(it==v.end())num=0;
			else if(it==it1)num=0;
			else {
				j=it1-v.begin();j--;
				lli tmp=f[j];
				j=it-v.begin();j--;
				if(j>=0)tmp-=f[j];
				num=tmp;
			}
			//trace1(num);
			//cout<<num<<endl;
			if(num%2==0){
				if(d=='C')w='D';
				else w='C';
			}
			else{
				if(d=='D')w='D';
				else w='C';
			}
			printf("%c",w);
			//ans+=w;
		}
		else{
			p=MP(k,inf);
			it=upper_bound(all(v),p);
			if(it==v.end())num=0;
			else if(it==v.begin())num=f[n-1];
			else {
				j=it-v.begin();
				num=f[n-1]-f[j-1];
			}
			//trace1(num);
			//cout<<num<<endl;
			if(num%2==0){
				if(d=='C')w='D';
				else w='C';
			}
			else{
				if(d=='D')w='D';
				else w='C';
			}
			printf("%c",w);
			//ans+=w;
		}
	}
	printf("\n");
	return 0;
}
