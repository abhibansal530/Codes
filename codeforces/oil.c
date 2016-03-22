#define si(a) scanf("%d",&a)
#define pi(a) printf("%d\n",a)
#include<stdio.h>
int k,n;
int oil(int v){
	long long int s=0,i=1;
	while(v/i){
		s+=(v/i);
		i*=k;
	}
	if(s<n)
		return 0;
	else
		return 1;
}
int bin(int low,int high){
	int mid;
	mid=(low+high)/2;
	if(!oil(mid)){
		return bin(mid+1,high);
	}
	else{
		if(mid==low)
			return mid;
		else if(!oil(mid-1))
			return mid;
		else
			return bin(low,mid-1);
	}
}
int main(){
	si(n);
	si(k);
	int v;
	v=bin(1,n);
	pi(v);
	return 0;
}
