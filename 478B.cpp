#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

LL nc2(int n)
{
	return (LL)(n*(n-1)/2);
}

int main()
{ 
   
   int n,m;
   cin>>n>>m;
    
   int k = n/m;
   int r = n%m;

   LL min = (m-r)*nc2(k) + r*nc2(k+1);
   LL max = nc2(n-m+1);

   cout<<min<<" "<<max;

  return 0;
}