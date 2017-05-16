#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  int arr[4001];
  fill_n(arr,4001,0);
  arr[a] = 1; 
  arr[b] = 1;
  arr[c] = 1;

  for(int i = 0 ; i< 4001; i++)
  {   
  	  int leftN;
  	  int x,y,z;
  	  
  	  if(i<a)
  	  {
  	  	 x = 0;
  	  }	else{
  	  	x  = arr[i-a];
  	  }
  	  if(i<b)
  	  {
          y = 0;
  	  }else{
          y = arr[i-b];
  	  }
  	  if(i<c)
      {
      	 z = 0;
      }else{
      	z = arr[i-c];
      }

    leftN = max(max(x,y),z);

       if(leftN!=0)
       { 
              arr[i] = leftN + 1;
       }	
      
  }

 cout<<arr[n];
 // rep(i,n+1) cout<<arr[i]<<" ";

  

   
  return 0;
}