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
	int t,n,x,max=0;
	si(t);
	while(t--){
		max=0;
		si(n);
		while(n--){
			si(x);
			if(x>max)max=x;
		}
		sout(max);
	}
	return 0;
}
