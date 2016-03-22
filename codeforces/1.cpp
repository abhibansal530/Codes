//Abhishek Bansal
#define loop(i,n) for(int i=0;i<n;i++)
#define si(n) scanf("%d",&n)
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t,a;
	cin>>s>>t;
	int l=s.size();
	loop(i,l){
		if(s[i]==t[i])
			a+=s[i];
		else{
			
			if(s[i+1]<t[i+1]&&i!=-1){
				//if(a[i-1]>t[i-1]){
				//cout<<"No such string"<<endl;
				//return 0;}
				//else
				a+=s[i]+1;
			}
			else{
				a+=s[i];}
			//if(s[i]=='z')
			//	a+=s[i];
			//else
			//	a+=s[i];
	}
	}
	cout<<a<<endl;
	if(a!=t&&a!=s)
		cout<<a<<endl;
	else
		cout<<"No such string"<<endl;
	return 0;
}
