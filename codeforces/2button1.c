#define min(a,b) ((a)<(b)?(a):(b))
#include<stdio.h>
#include<string.h>
int sol[10000][10000];
int minb(int n,int m){
	//int i,p=1;
	if(sol[n][m]!=-1)
		return sol[n][m];
	if(m==n){
		sol[n][m]=0;
		return 0;
	}
	if(m<n){
		sol[n][m]=n-m;
		return n-m;
	}
	if(m==2*n||m==n-1){
		sol[n][m]=1;
		return 1;
	}
	/*if(n==1){
		if(m==3)
			return 3;
		else{
			for(i=1;i<15;i++){
				p=p*i;
				if(m==p)
					return i;
			}
		}
	}*/
	if(n==2)
		return sol[n][m]=1+minb(4,m);
	if(n==1)
		return sol[n][m]=1+minb(2,m);
	if(m%2==0){
		if(m/2==n-1||m/2==2*n||m+1==n-1||m+1==2*n)
			return sol[n][m]=2;
		else
			return sol[n][m]=min(minb(n,m+1),minb(n,m/2))+1;
	}
	else
		return sol[n][m]=minb(n,m+1)+1;
}
int main(){
	memset(sol,-1,sizeof(sol));
	int m,n;
	scanf("%d %d",&n,&m);
	printf("%d\n",minb(n,m));
	//printf("%d\n",minb(10,1));
	return 0;
}
