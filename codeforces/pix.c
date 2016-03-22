#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define si(a) scanf("%d",&a)
#define pi(a) printf("%d\n",a)
int a[1000][1000],n,m;
int check(){
	int i,j;
	int flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i<n-1&&j<m-1){
			if(a[i][j]==1&&a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+1]==1){
				flag=1;
			}
			}
		}
	}
	return flag;
}
int main(){
	int k;
	si(n);
	si(m);
	si(k);
	int i,j;
	/*for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a[i][j]=0;
		}
	}*/
	memset (a, 0 ,sizeof(a[0][0])*m*n);
	int p=-1,flag=0;
	int l,m;
	for(i=1;i<=k;i++){
		scanf("%d %d",&l,&m);
		a[l-1][m-1]=1;
		if(check()&&flag==0){
			p=i;
			flag=1;}
	}
	if(p==-1)
		printf("0\n");
	else
		pi(p);
	return 0;
}
