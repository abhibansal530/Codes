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
set<ii> s;   //first element is row no. of query,and second==1 for UP query else 0
map<int,int> mp; // maps row no. to its answer
int main(){
	int n,q,x,y;
	si(n);si(q);
	char c;
	s.insert(MP(n+1,0));
	s.insert(MP(0,1));
	mp[0]=0;
	mp[n+1]=0;
	while(q--){
		scanf("%d %d %c",&y,&x,&c);
		if(mp.count(x)){
			printf("0\n");
			continue;
		}
		if(c=='U'){
			set<ii>::iterator it=s.upper_bound(MP(x,-1));
			it--;
			ii p=*it;
//			cout<<p.F<<endl;
			if(p.S==1){
				mp[x]=x-p.F+mp[p.F];
			}
			else mp[x]=x-p.F;
			s.insert(MP(x,1));
		}
		else{
			ii p=*s.upper_bound(MP(x,-1));
//			cout<<p.F<<endl;
			if(p.S==0) mp[x]=p.F-x+mp[p.F];
			else mp[x]=p.F-x;
			s.insert(MP(x,0));
		}
		printf("%d\n",mp[x]);
	}
	return 0;
}
