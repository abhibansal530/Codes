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
typedef pair<ii,int> iii;
string color[10];
vector<iii> v;
iii mp(int a,int b,int c){
	iii t;
	t.F.F=a;t.F.S=b;t.S=c;
	return t;
}
bool valid(int i){
	int a,b,c;
	a=v[i].F.F;b=v[i].F.S;c=v[i].S;
	if(color[a]==color[b]&&color[b]==color[c])return true;
	return false;
}
int main(){
	v.PB(mp(1,3,5));
	v.PB(mp(1,3,6));
	v.PB(mp(1,4,5));
	v.PB(mp(1,4,6));
	v.PB(mp(2,3,5));
	v.PB(mp(2,3,6));
	v.PB(mp(2,4,5));
	v.PB(mp(2,4,6));
	int t;
	si(t);
	while(t--){
		int flag=0;
		loop(0,6)cin>>color[i+1];
		loop(0,8){
			if(valid(i)){
				flag=1;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
