#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef vector<int> vi;
#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  int n; 
  cin>>n;
  vi g;
  rep(i,n) 
  { 
  	int x; cin>>x; g.pb(x);
  }
  int m; cin>>m;
  vi b;
  rep(i,m)
  {
    int x; cin>>x;
    b.pb(x);
  }

  sort(g.begin(),g.end());

  sort(b.begin(),b.end());

  int ptr = 0;
  int count = 0;
  for(int i = 0; i<n; i++)
  {
     for(int j = ptr; j<m; j++)
     {
        int diff = abs(g[i]-b[j]);

        if(diff<=1)
        {
        	ptr = j+1;
        	count++;
        	break;
        }	
     }
     if(ptr==m) break;
  }	
  cout<<count;
 
  return 0;
}