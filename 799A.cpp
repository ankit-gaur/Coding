#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,k,t,d;
   cin>>n>>t>>k>>d;
   if(n%k==0)
   {
      int time = (n/k  - 1)*t;
      if(d<time) cout<<"YES";
      else cout<<"NO";
   }
   else{
      int time = (n/k)*t;
      if(d<time) cout<<"YES";
      else cout<<"NO";
   }
   return 0;
}