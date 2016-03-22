#include<stdio.h>
#include<string.h>
int main(){
	int n,i;
	char a[101],c;
	int s[27],flag=1;
	memset(s,0,sizeof(s));
	scanf("%d",&n);
	scanf("%s",a);
	if(n<26){
		printf("NO\n");
		return 0;
	}
	else{
		for(i=0;i<n;i++){
			if(islower(a[i])){
				c=toupper(a[i]);
				s[c-'A']=1;
			}
			else{
				s[a[i]-'A']=1;
			}
		}
		for(i=0;i<26;i++){
			if(s[i]==0){
				flag=0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
}
