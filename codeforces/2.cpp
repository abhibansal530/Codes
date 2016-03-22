//Abhishek Bansal
#define loop(i,n) for(int i=0;i<n;i++)
#define si(n) scanf("%d",&n)
#include<bits/stdc++.h>
using namespace std;
int po(string s,char c){
	int k=s.size();
	loop(i,k){
		if(s[i]==c)
			return i;
	}
	return -1;
}
int main(){
	string s,t,a;
	cin>>s>>t;
	int l=s.size();
	int y=0,w=0,v;
	char c;
	int j=0;
	while(j<l&&!s.empty()){
		size_t found = t.find(s[j]);
		if(found!=std::string::npos){
			y++;
			t.erase(t.begin()+found);
			s.erase(s.begin()+j);
		}
		else
			j++;
	}
	l=s.size();
	//cout<<s<<endl;
	if(!s.empty()){
	loop(i,l){
			if(s[i]>='A'&&s[i]<='Z'){
				//cout<<s[i]<<endl;
				c=s[i]+32;}
				//cout<<c<<endl;
				//v=po(t,c);
				//cout<<v<<endl;
				//size_t found=t.find(c);}
			else{
				c=s[i]-32;}
				//v=po(t,c);
				//size_t found=t.find(s[i]-32);
			//cout<<found<<endl;
			v=po(t,c);
			if(v!=-1){
				//cout<<"yes"<<endl;
				w++;
				t.erase(t.begin()+v);
			}

		}
}
	cout<<y<<" "<<w<<endl;
	return 0;
}
