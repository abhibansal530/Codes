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
typedef struct node{
	struct node* a[27];
	int leave,w,l;
}node;
node* init(node* head){
	head->leave=0;
	loop(0,26)head->a[i]=NULL;
	return head;
}
node* insert(node* root,char s[],int i,int l){
	if(i==l)return root;
	if(root->a[s[i]-'a']==NULL){
		root->a[s[i]-'a']=(node*)malloc(sizeof(node));
		root->a[s[i]-'a']=init(root->a[s[i]-'a']);
	}
	if(i==l-1)(root->a[s[i]-'a'])->leave=1;
	root->a[s[i]-'a']=insert(root->a[s[i]-'a'],s,i+1,l);
	return root;
}
node* process(node* root){
	if(root->leave==1){
		root->w=1;
		root->l=0;
		return root;
	}
	int tmp=0,tmp2=0;
	loop(0,26){
		if(root->a[i]!=NULL){
			root->a[i]=process(root->a[i]);
			tmp=tmp||root->a[i]->w;
			tmp2=tmp2||root->a[i]->l;
		}
		root->w=!tmp;
		root->l=!tmp2;
	}
	return root;
}
int main(){
	int n,k,l;
	char s[100005];
	si(n);si(k);
	node* root=(node*)malloc(sizeof(node));
	root=init(root);
	while(n--){
		scanf("%s",s);
		l=strlen(s);
		root=insert(root,s,0,l);
	}
	root=process(root);
	if(root->w){
		printf("Second\n");
	}
	else{
		if(root->l){
			if(k%2)printf("First\n");
			else printf("Second\n");
		}
		else printf("First\n");
	}
	return 0;
}
