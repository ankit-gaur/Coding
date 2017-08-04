#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  int n,x;
  cin>>n>>x;
  int count = 0; 
  for(int i = 1 ; i<sqrt(x)&&i<=n; i++)
  {
  	  if(x%i==0&&x/i<=n)
  	  {
          count+=2;
  	  }	
  }	
  int root = sqrt(x);
  if(root*root ==x&&root<=n) count++;
  cout<<count;
  return 0;
}