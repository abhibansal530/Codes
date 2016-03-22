#define e endl
#define min(a,b) ((a)<(b)?(a):(b))
#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,d;
	int s[1000000],t[1000000];
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	while((c=getchar())!='\n'){
		s[c]++;
	}
	while((d=getchar())!='\n'){
		t[d]++;
	}
	int i;
	int x,z,k;
	int y=0,w=0;
	for(i=65;i<=122;i++){
		if(s[i]>0){
			if(t[i]>0){
				x=min(s[i],t[i]);
				y+=x;
				s[i]-=x;
				t[i]-=x;
			}
		}
	}
		for(i=65;i<=122;i++){
			if(s[i]>0){
			if(t[i+32]>0){
				z=min(s[i],t[i+32]);
				w+=z;
				s[i]-=z;
				t[i+32]-=z;
			}
			if(t[i-32]>0){
				k=min(s[i],t[i-32]);
				w+=k;
				s[i]-=k;
				t[i-32]-=k;
			}
			}
		}
		cout<<y<<" "<<w<<endl;
		return 0;
	}
