//Abhishek Bansal
//Vanya and Triangles
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
lli num(lli n){
	return (n*(n-1)*(n-2))/6;
}
double slope[2005],inf=1000.0;
lli countp[2005]={0};
double getslope(int x1,int y1,int x2,int y2){
	if(x1==x2)return inf;
	return double(y2-y1)/double(x2-x1);
}
int main(){
	lli n;
	sll(n);
	int x,y,j,k;
	lli max=0;
	lli cnt;
	vii points;
	lli ans=num(n);
	loop(0,n){
		si(x);si(y);
		points.PB(MP(x,y));
	}
	loop(0,n){
		k=0;
		x=points[i].F;
		y=points[i].S;
		for(j=0;j<n;j++){
			if(x==points[j].F&&y==points[j].S)continue;
			slope[k++]=getslope(x,y,points[j].F,points[j].S);
		}
		sort(slope,slope+n-1);
		cnt=1;
		for(int l=0;l<n-1;l++){
			if(l!=n-2&&slope[l+1]==slope[l])cnt++;
			else{
				cnt++;
				if(cnt>max)max=cnt;
				countp[cnt]++;
				cnt=1;
			}
		}
	}
	loop(0,max+1){
		if(countp[i]>0){
			//printf("i:%d cnt:%d\n",i,countp[i]);
			ans-=lli((countp[i]/i))*num(lli(i));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
