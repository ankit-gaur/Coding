#include<bits/stdc++.h>
using namespace std;

#define rep(i,a) for(int i=0; i<(a); ++i) 
const int MAXN = 10000001; 

int main()
{ 
  int k,n,w;
  cin>>k>>n>>w;
  
  int total = (k*w*(w+1))/2;
  if(total-n>=0) cout<<total-n;
  else cout<<0;
  return 0;
}