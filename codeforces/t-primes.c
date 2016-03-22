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
#include<math.h>
typedef long long int lli;
int main(){
	long long int n=1000001;
long long int i,j,c=0;
int a[1000000];
for(i=0;i<n;i++)
	a[i]=1;
for(i=2;i<n;i++){
	if(a[i]==1){
		for(j=i*i;j<n;j+=i){
			a[j]=0;
		}
	}
}
int N;
lli x;
si(N);
while(N--){
	sll(x);
	if(x==4)printf("YES\n");
	else if(x==1)printf("NO\n");
	else if(!x%2)printf("NO\n");
	else{
		double s=sqrt(x);
		double l=5.08;
		int p=s;
		if((s-p)==0&&a[p])printf("YES\n");
		else printf("NO\n");
	}
}
return 0;
}
