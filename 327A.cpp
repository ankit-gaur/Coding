#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  int n; cin>>n;
  int arr[n+1];
  arr[0] = -1;
  for(int i = 1; i<n+1; i++ )
  {
  	 cin>>arr[i];
  }

  int max = 0;
  for(int j = 1; j<n+1; j++)
  {
  	 for (int k = j; k<n+1; k++)
  	 {   
  	 	 int total = 0;
         for(int i = 0; i< n+1 ; i++)
         {
         	 if(i>=j&&i<=k)
         	 {
         	 	if(arr[i]==0)
                total++;
                continue;
         	 }
         	 if(arr[i]==1) total++;

         }	
         if(max<total) max = total;
  	 }	
  }
  cout<<max;	

  return 0;
}