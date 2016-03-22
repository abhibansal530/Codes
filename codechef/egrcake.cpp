#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int tm=__gcd(m,n);
		if(n==1){
			cout<<"Yes"<<endl;
		}
		else if(m==0){
			cout<<"No 1"<<endl;
		}
		else if(tm!=1&&n%tm==0){
			cout<<"No "<<n/tm<<endl;
		}
		else cout<<"Yes"<<endl;
	}
	return 0;
}
