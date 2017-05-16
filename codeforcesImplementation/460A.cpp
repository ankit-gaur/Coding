#include<bits/stdc++.h>
using namespace std;

#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  int n,m;
  cin>>n>>m;
  int left = n;
  int day = 0;
  while(left>0)
  {
  	 day+=left;
  	 left = day/m - (day-left)/m;
  }	

  cout<<day;
  return 0;
}