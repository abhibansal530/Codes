#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long int ans = 0;
	cin>>s;
	int l = (int)s.size();
	for(int i=0;i<l;++i){
		if((s[i]-'0')%4==0)ans++;
	}
	for(int i=0;i<l-1;++i){
		int nu = s[i+1]-'0'+10*(s[i]-'0');
		if(nu%4==0)ans+=1ll*(i+1);
	}
	cout<<ans<<endl;
	return 0;
}
