//Abhishek Bansal
//Divisibility By 8
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
	char s[105];
	scanf("%s",s);
	int l=strlen(s);
	int i,j,k;
	int num;
	loop(0,l){
		if((s[i]-'0')%8==0){printf("YES\n");printf("%c\n",s[i]);return 0;}
	}
	loop(0,l){
		for(int p=i+1;p<l;p++){
			num=s[p]-'0'+10*(s[i]-'0');
			if(num%8==0){
				printf("YES\n");
				printf("%c%c\n",s[i],s[p]);
				return 0;
			}
		}
	}
	for(i=0;i<l;i++){
		for(j=i+1;j<l;j++){
			for(k=j+1;k<l;k++){
				num=s[k]-'0'+10*(s[j]-'0')+100*(s[i]-'0');
				if(num%8==0){
					printf("YES\n");
					for(int m=0;m<i;m++)printf("%c",s[m]);
					printf("%c%c%c\n",s[i],s[j],s[k]);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
