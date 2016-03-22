#include<bits/stdc++.h>
using namespace std;
string next(string s){
	int l=s.size();
	int i,j;
	for(i=l-1;i>=0;i--){
		if(s[i]!='z'){
			s[i]+=1;
			for(j=i+1;j<l;j++){
				s[j]='a';
			}
			return s;
		}
	}
}
int main(){
	string s,t;
	cin>>s>>t;
	string a;
	a=next(s);
	//cout<<a<<endl;
	if(a<t)
		cout<<a<<endl;
	else
		cout<<"No such string"<<endl;
	return 0;
}
