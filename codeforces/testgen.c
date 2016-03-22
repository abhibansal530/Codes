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
int N=100001,M=10001,Y=1e9;
int main(){
	int i;
	printf("%d %d\n",N,M);
	loop(2,N+1){
		printf("1 %d\n",i);
	}
	loop(0,M-1)printf("1 1 %d\n",Y);
	printf("2 1\n");
	return 0;
}
