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
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int main(){
	string get="",need="",s;
	//char s[100000];
	//char need[1000],get[1000];
	int n;
	int have[27];
	SET(have,0);
	si(n);
	cin>>s;
	int k=2*(n-1);
	int j=0,j1=0;
	/*loop(0,k){
		scanf("%c",&s[i]);
		if(i%2==0)
			get[j++]=s[i];
		else
			need[j1++]=s[i]+32;
	}*/
	loop(0,k){
		if(i%2==0)
			get+=s[i];
		else
			need+=s[i]+32;
	}
	//cout<<need<<endl;
	//cout<<get<<endl;
	int l=(n-1);
	lli ans=0;
	loop(0,l){
		have[get[i]-'a'+1]++;
		if(have[need[i]-'a'+1]>0){
			have[need[i]-'a'+1]--;
		}
		else{
			ans++;
			//have[need[i]-'a'+1]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
