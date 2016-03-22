#define min(a,b) ((a)<(b)?(a):(b))
#include<stdio.h>
int minb(int n,int m){
	int i,p=1;
	if(m==n)
		return 0;
	if(m<n)
		return n-m;
	if(m==2*n||m==n-1)
		return 1;
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
		return 1+minb(4,m);
	if(n==1)
		return 1+minb(2,m);
	if(m%2==0){
		if(minb(n,m/2)==1||minb(n,m+1)==1)
			return 2;
		else
			return min(minb(n,m+1),minb(n,m/2))+1;
	}
	else
		return minb(n,m+1)+1;
}
int main(){
	int m,n;
	scanf("%d %d",&n,&m);
	printf("%d\n",minb(n,m));
	//printf("%d\n",minb(10,1));
	return 0;
}
