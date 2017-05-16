#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n,k;
      cin>>n>>k;
      int ans = (-5+sqrt(9625-40*k))/10;
      cout<<min(n,k);
      return 0;
}