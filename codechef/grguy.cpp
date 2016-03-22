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
const int MAX=200005;
int a1[MAX]={-1},a2[MAX]={-1},l;
void fun(string s1,int a1[]){
	int i=0,last=-1,cnt=0;
	while(i<l){
		if(s1[i]=='#'){
			//trace1(last);
			if(last>=0)a1[last]=cnt;
			last=-1;cnt=0;
			a1[i]=0;
			i++;
		}
		else{
			if(last==-1){last=i;}
			cnt++;i++;
		}
	}
	if(s1[l-1]!='#')a1[last]=cnt;
}
int main(){
	int cl;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	l=SZ(s1);
	fun(s1,a1);fun(s2,a2);
	//trace1(a1[0]);
	//loop(0,l){
	//	trace1(a1[i]);
	//}
	if(s1[0]=='#'&&s2[0]=='#'){
		printf("No\n");return 0;
	}
	if(a1[0]>a2[0])cl=1;
	else cl=2;
	trace1(cl);
	int j=0,ans=0,flag=-1;
	while(j<l){
		if(j==l-1){flag=1;break;}
		if(cl==1)j=j+a1[j]-1;
		else j=j+a2[j]-1;
		if(j==l-1){flag=1;break;}
		if(cl==1){
			if(s2[j+1]=='#'){flag=0;break;}
			else{
				cl=2;j++;ans++;}
		}
		else{
			if(s1[j+1]=='#'){flag=0;break;}
			else{cl=1;j++;ans++;}
		}
	}
	if(flag==0)printf("No\n");
	else printf("Yes\n%d\n",ans);
	return 0;
}
