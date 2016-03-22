//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
//#define max(a,b) ((a)>(b)?(a):(b))
//#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
typedef long long int lli;
void swap(char *a,char *b){
	char t=*a;
	*a=*b;
	*b=t;
	return;
}
int min(int a,int b){
	int n=a<b?a:b;
}
int diff(char a,char b){
	if(b<a)swap(&a,&b);
	return min(b-a,'z'-b+a-'a'+1);
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
		ans+=min(abs(2*(p-mi)+ma-p),abs(2*(ma-p)+p-mi));
	}
	//printf("%d %d\n",mi,ma);
	printf("%lld\n",ans);
	//printf("%s\n",s);
	return 0;
}
