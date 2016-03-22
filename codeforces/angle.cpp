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
#define PI 3.14159265
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef vector<double> vd;
const double inf=(double)1e18;
double slope(int x,int y){
	if(x==0)return y>0?inf:(double)-1*inf;
	if(y==0)return 0;
	return double(y)/double(x);
}
double fun(double x){
	if(abs(x-inf)<=double(1e-18))return 90;
	else return (double)atan(x)*180/PI;
}
double angle(double m1,double m2){
	double tmp;
	if(1+m1*m2==0){
		if(m1>=m2)tmp=inf;
		else tmp=(double)-1*inf;
	}
	else tmp=(m1-m2)/(1+m1*m2);
	/*if(tmp>=0){
	  if(abs(tmp-inf)<=double(-1e18))return double(90);
	  else return (double)atan(tmp)*180/PI;
	  }*/
	if(tmp>=0)return fun(tmp);
	else return 360 - fun(-1*tmp);
}
int main(){
	int n,x,y;
	double ans=0;
	vd lt,rt,al;
	vd::iterator it;
	si(n);
	loop(0,n){
		si(x);si(y);
		if(x>=0)rt.PB(slope(x,y));
		else lt.PB(slope(x,y));
	}
	sort(all(rt),greater<double>());
	sort(all(lt));
	al.reserve(lt.size() + rt.size() );
	al.insert(al.end(),rt.begin(),rt.end() );
	al.insert(al.end(),lt.begin(),lt.end() );
	TR(al,it)printf("%lf ",*it);
	printf("\n");
	TR(al,it){
		if(it!=al.end()-1){ans=max(ans,angle(*it,*(it+1)));cout<<ans<<endl;}
		else {ans=max(ans,angle(*it,*al.begin()));cout<<ans<<endl;}
	}
	printf("%.6lf\n",360-ans);
	return 0;
}
