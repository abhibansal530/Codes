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
void print(string s[],int lo,int hi){
	if(lo>hi)return;
	if(lo==hi){
		printf("int");
		return;
	}
	cout<<s[lo]<<"<" ;
	if(s[lo+1]=="int"){
		printf("int,");
		print(s,lo+2,hi);
		printf(">");
	}
	else{
		print(s,lo+1,hi-1);
		printf(",int>");
	}
	return;
}
/*bool verify(string s[],int lo,int hi,int n){
	if(lo>hi)return false;
	if(lo==hi){
		if(s[lo]=="int")return true;
		else return false;
	}
}*/
int main(){
	string stl[1000];
	int n;
	si(n);
	loop(0,n)cin>>stl[i];
	print(stl,0,n-1);
	printf("\n");
	return 0;
}
