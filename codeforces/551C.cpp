//Abhishek Bansal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define loop(a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int n,m,a[100005];
int b[100005];
void copy(int a[],int b[],int n){
	loop(0,n)b[i]=a[i];
	return;
}
int valid(lli t){
	copy(b,a,n);
	int j;
	for(j=n-1;j>=0;j--)if(a[j]>0){break;}
	lli cur=0;
	loop(0,m){
		if(j==-1)break;
		cur=t;
		cur-=j+1;
		//if(cur<0)break;
		while(cur>=0){
			if(j==-1)break;
			if(a[j]==0)j--;
			if(j==-1)break;
			if(a[j]<=cur){cur-=a[j];a[j]=0;}
			else{a[j]-=cur;cur=-1;}
		}
	}
	if(j==-1&&cur==-1)return 1;
	else if(j==-1&&cur!=-1)return 2;
	else return 0;
}
lli bsearch(){
	lli l=0,r=10;
	while(l<=r){
		lli m=(l+r)/2;
		if(valid(m)==1)return m;
		else if(valid(m)==2)r=m-1;
		else l=m+1;
	}
	//return l;
}
lli bin(lli lo,lli hi){
	lli m=(lo+hi)/2;
	//cout<<"m = "<<m<<endl;
	if(lo>hi)return -1;
	if(valid(m)==0)return bin(m+1,hi);
	else{
		if(valid(m)==1)return m;
		else{
			//printf(" %lld valid==2\n",m);
			//printf("%lld:valid=%d\n",m-1,valid(m-1));
			//printf("4 %d\n",valid(4));
			if(m==lo||valid(m-1)==0){
				//printf("YES\n");
				//printf("valid=%d %lld\n",valid(m-1),m);
				return m;
			}
			else return bin(lo,m-1);
		}
	}
}
int main(){
	si(n);si(m);
	loop(0,n)si(b[i]);
	//printf(" valid(4)=%d\n",valid(4));
	printf("%lld\n",bin(0,1e15));
	//printf("%lld\n",bsearch());
	return 0;
}
