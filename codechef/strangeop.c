//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
int main(){
	int t,i;
	int n,k,x;
	lli sum;
	si(t);
	while(t--){
		sum=0;
		si(n);si(k);
		loop(0,n){si(x);sum+=x;}
		if(k==1&&sum%2==0)printf("odd\n");
		else printf("even\n");
	}
	return 0;
}
