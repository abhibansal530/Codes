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
int mini(int a,int b){
	if(a<b)return a;
	return b;
}
int ab(int x){
	if(x>0)return x;
	return -1*x;
}
int diff(char a,char b){
	if(b<a)swap(a,b);
	return mini(b-a,'z'-b+a-'a'+1);
}
int main(){
	int n,p,mi,ma;
	char s[100005];
	//vi ind;
	scanf("%d %d %s",&n,&p,s);
	p--;
	lli ans=0;
	mi=n;ma=-1;
	loop(0,n/2){
		ans+=diff(s[i],s[n-1-i]);
		if(diff(s[i],s[n-1-i])){
			//printf("i %d\n",i);
			if(i<mi)mi=i;
			if(i>ma)ma=i;
		}
	}
	if(n%2&&p==n/2&&mi!=n)ans+=p-mi;
	else if(mi!=n){
		if(p>=n/2)p=n-1-p;
		//ans+=min(ab(2*(p-mi)+ma-p),ab(2*(ma-p)+p-mi));
		ans+=ab(ma-mi)+mini(ab(ma-p),ab(p-mi));
	}
	//printf("%d %d\n",mi,ma);
	printf("%lld\n",ans);
	//printf("%s\n",s);
	return 0;
}
