#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int dist(char a,char b){
	if(b>a)return b-a;
	return a-b;
}
char get(char c,int d){
	if(c+d>'z')return c-d;
	return c+d;
}
int main(){
	int n,k,val[100005];
	int range[100005];
	string s,res="";
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;++i){
		range[i]=max(dist('a',s[i]),dist('z',s[i]));
		//		printf("%d\n",range[i]);
	}
	int cnt=k;
	for(int i=0;i<n;++i)val[i]=0;
	for(int i=0;i<n&&cnt>0;++i){
		while(val[i]<range[i]&&cnt>0){
			val[i]++;
			cnt--;
		}
	}
	if(cnt>0){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;++i){
		if(val[i]>range[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=0;i<n;++i)
		res+=get(s[i],val[i]);
	cout<<res<<endl;
	return 0;
}
