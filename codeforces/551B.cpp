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
	char a[100005],b[100005],c[100005];
	scanf("%s %s %s",a,b,c);
	int cnta[27]={0},cntb[27]={0},cntc[27]={0};
	int la,lb,lc;
	la=strlen(a);lb=strlen(b);lc=strlen(c);
	loop(0,la)cnta[a[i]-'a']++;
	loop(0,lb)cntb[b[i]-'a']++;
	loop(0,lc)cntc[c[i]-'a']++;
	int nc,nb;
	nc=nb=1000000;
	loop(0,26){
		if(cntb[i]){
			if(cnta[i]/cntb[i]<nb)nb=cnta[i]/cntb[i];
		}
	}
	loop(0,26){
		if(cntc[i]){
			if(cnta[i]/cntc[i]<nc)nc=cnta[i]/cntc[i];
		}
	}
	int rem[27];
	int max=0,m=1000000,fb,fc;
	for(int j=nb;j>=0;j--){
		m=1000000;
		loop(0,26)rem[i]=cnta[i]-j*cntb[i];
		loop(0,26){
			if(cntc[i]){
				if(rem[i]/cntc[i]<m)m=rem[i]/cntc[i];
			}
		}
		if(j+m>max){max=j+m;fb=j;fc=m;
	}
	}
		//printf("%d\n",max);
		//string ans="";
		//ans+=fun(fb,b);
		//ans+=fun(fc,c);
		loop(0,fb)printf("%s",b);
		loop(0,fc)printf("%s",c);
		loop(0,26){
			int cnt=cnta[i]-fb*cntb[i]-fc*cntc[i];
			if(cnt>0){
				while(cnt--)printf("%c",'a'+i);
		}
		}
		printf("\n");
		return 0;
	}
