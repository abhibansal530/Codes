#include<iostream>
#include<string>
using namespace std;
int main(){
	string curr;
	string nexc;
	cin>>curr;
	int l=curr.size();
	nexc=curr;
	//cout<<curr[0]<<endl;
	int i,maxi=0;
	string max="0";
	for(i=0;i<l;i++){
		if(curr[i]>='2' && curr[i]%2==0){
			swap(curr[i],curr[l-1]);
			if(curr>max)
				max=curr;
			curr=nexc;}
	}
	if(max=="0")
		cout<<"-1"<<endl;
	else{
	//swap(curr[l-1],curr[maxi]);
	cout<<max<<endl;}
	//cout<<"yes"<<endl;
	return 0;
}
