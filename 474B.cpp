#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  
  int n;
  cin>>n;
  vector< int > v;
  rep(i,n){
  	int x; cin>>x;
  	v.pb(x);
  }
  rep(i,n)
  {
  	 if(i>0)
  	 { 
  	 	 v[i] +=v[i-1];
  	 }	

  }

  int m; 
  cin>>m;
  rep(i,m)
  {
  	 int q; cin>>q;
     
     int x = lower_bound(v.begin(),v.end(),q) - v.begin();
     cout<<x+1; cout<<endl;
  }
 
  return 0;
}