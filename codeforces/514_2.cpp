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
#define MAX 666666
using namespace std;
typedef long long lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
const lli mod=1000000000000000003;
lli powmod(lli a,lli b) {lli res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//const lli MOD=99999999999973;
set<lli> h;
lli hash(char s[]){
	lli sum=0,tmp;
	int l=strlen(s);
	loop(0,l){
		tmp=(s[i]-'a'+1)%mod;
		tmp*=powmod(5,i+1);
		tmp%=mod;
		sum+=tmp;
		sum%=mod;
	}
	return sum;
}
lli posh(char s[],int i,char a){
	lli tmp;
	tmp=(a-'a'+1);
	tmp*=powmod(5,i+1);
	return tmp;
}
int main(){
	int n,m,flag,l;
	lli tmph,tmp;
	char s[MAX];
	si(n);si(m);
	while(n--){
		scanf("%s",s);
		h.insert(hash(s));
	}
	while(m--){
		scanf("%s",s);
		l=strlen(s);
		tmph=hash(s);
		flag=0;
		loop(0,l){
			if(flag)break;
			for(int j=0;j<3;j++){
				tmp=(tmph-posh(s,i,s[i]))%mod;
				if(tmp<0)tmp+=mod;
				tmp=(tmp+posh(s,i,'a'+j))%mod;
				if(h.count(tmp)>0){
					flag=1;
					break;
				}
			}
		}
		if(!flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
