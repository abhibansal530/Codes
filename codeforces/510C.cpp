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
vvi graph(27);
vii f;
int ti=0,visited[27]={0};
bool is_cycle=false;
int min(int a,int b){
	return a<b?a:b;
}
void dfs(int u){
	visited[u]=-1;
	int s=SZ(graph[u]);
	loop(0,s){
		int c=graph[u][i];
		if(visited[c]==-1){is_cycle=true;return;}
		else if(visited[c]==0)dfs(c);
	}
	visited[u]=1;
	ti++;
	f.PB(MP(ti,u));
}
void print(){
	loop(1,27){
		printf("%c: ",i+'a'-1);
		int s=SZ(graph[i]);
		for(int j=0;j<s;j++)printf("%c ",'a'+graph[i][j]-1);
		printf("\n");
	}
}
int main(){
	int n,FLAG=0;
	char s[105][105];
	si(n);
	loop(0,n)scanf("%s",s[i]);
	loop(0,n-1){
		if(s[i][0]!=s[i+1][0])graph[s[i][0]-'a'+1].PB(s[i+1][0]-'a'+1);
		else{
			int j=1,flag=0;
			int l=min(strlen(s[i]),strlen(s[i+1]));
			while(j<l){
				if(s[i][j]!=s[i+1][j]){graph[s[i][j]-'a'+1].PB(s[i+1][j]-'a'+1);flag=1;break;}
				else j++;
			}
			if(!flag&&strlen(s[i])>strlen(s[i+1])){FLAG=1;break;}
		}
	}
	//print();
	loop(1,27){
		if(!visited[i])dfs(i);
		if(is_cycle)break;
	}
	if(is_cycle||FLAG)printf("Impossible");
	else{
		sort(all(f),greater<ii>());
		int m=SZ(f);
		loop(0,m)printf("%c",'a'+f[i].S-1);
	}
	printf("\n");
	return 0;
}
