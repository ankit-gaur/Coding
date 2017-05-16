#include<bits/stdc++.h>
using namespace std;

#define rep(i,a) for(int i=0; i<(a); ++i) 
const int MAXN = 10000001; 
const int inf = numeric_limits<int>::max();

int main()
{ 

  int n,m;
  cin>>n>>m;
  vector< int > v;
  rep(i,m)
  {
  	 int f;
  	 cin>>f; v.push_back(f);
  }	
  sort(v.begin(),v.end());
  
  int min = inf;

  for(int i= 0 ; i<m-n+1 ; i++)
  {
  	  int diff = v[i+n-1] - v[i];
  	  if(diff<min) min = diff;
  }	
  
  cout<<min;

  return 0;
}