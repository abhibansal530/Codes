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
int main(){
	string s;
	int m;
	cin>>s;
	si(m);
	int w1=0,w2=0,a[1005],k=0,last=0,flag=0;
	SET(a,-1);
	loop(1,m+1){
		if(i%2==1){
			for(int j=0;j<10;j++){
				if(s[j]=='1'&&j+1>w2-w1&&j+1!=last){
					w1+=j+1;
					a[k++]=j+1;
					last=j+1;
					break;
				}
			}
		}
		else{
			for(int j=0;j<10;j++){
				if(s[j]=='1'&&j+1>w1-w2&&j+1!=last){
					w2+=j+1;
					a[k++]=j+1;
					last=j+1;
					break;
				}
			}
		}
	}
	loop(0,m){
		if(a[i]==-1){
			flag=1;
			break;
		}
	}
	if(flag)printf("NO\n");
	else{
		printf("YES\n");
		loop(0,m)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
