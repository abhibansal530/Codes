#define loop(i,n) for(int i=0;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int main(){
	typedef long long int lli;
	int n,m,k;
	int app[100000+1];
	int pos[100000+1];
	int b[100000+1];
	cin>>n>>m>>k;
	//scanf("%d %d %d",&n,&m,&k);
	loop(i,n){
		cin>>app[i+1];
		pos[app[i+1]]=i+1;
	}
	loop(i,m){
		cin>>b[i];
	}
	lli ans=0,t,cp,tmp,tmp2;
	double f;
	loop(i,m){
		f=ceil(float(pos[b[i]])/float(k));
		t=lli(f);
		ans+=t;
		cp=pos[b[i]];
		if(cp>1){
			tmp=app[cp];
			tmp2=app[cp-1];
			app[cp]=app[cp-1];
			app[cp-1]=tmp;
			pos[tmp]-=1;
			pos[tmp2]+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
