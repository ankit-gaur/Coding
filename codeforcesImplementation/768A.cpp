#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long int LL;

#define pb push_back
#define rep(i,a) for(int i=0; i<(a); ++i) 
const int inf = numeric_limits<int>::max();
const int MAXN = 10000001; 

int main()
{ 
  
  int n;
  cin>>n;
  int arr[n];
  rep(i,n)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int min = arr[0];
  int max = arr[n-1];
  int count = 0;
  for(int i = 1; i<n-1; i++)
  {
      if(arr[i]>min && arr[i]< max)
      { 
      	  count ++;
      }	
  }
  cout<<count;
  return 0;
}