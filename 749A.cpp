#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n; cin>>n;
      int k = n/2;
      cout<<k<<"\n";
      for(int i = 0 ; i < k-1 ; i++) cout<<"2 ";
      if(n%2==0)cout<<"2";
      else cout<<"3";
      return 0;
}