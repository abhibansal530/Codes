// karanaggarwal
//#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
 
using namespace std;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
 
 
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
 
 
long long f(long long n)
{
   if(n<2)return n;
   long long ans = 1;
   for(long long x = 2; x<=n; x*=2)
   {
      LL y = n/x; 
      while(y){ ans++; y/=3;  }
   }
   return ans;
}
 
int main()
{
   int t; si(t); while(t--)
   {
      LL l,r; cin>>l>>r; l--;
      cout<<f(r) - f(l)<<endl;
   }
	return 0;	
}
