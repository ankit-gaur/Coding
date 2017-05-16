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
  
  int m,s;
  cin>>m>>s;
 
 
  if(s>m*9||(s==0&&m>1))
  {
  	 cout<<-1<<" "<<-1; return 0;
  }	

  //for max 
   vi v;
  int left = s;
  while(left>0)
  {
     if(left>=9)
     {
     	 v.pb(9);
     	 left-=9;
     }
     else{
     	v.pb(left); left = 0;
     }	

  }
  while(v.size()<=m)
  {
     v.pb(0);
  }

  //for min;
  vi lp,rp; 
  left = s;

  while(left>0)
  { 
     
     if(left>9)
     {
     	 rp.pb(9); left-=9;
     }
     else{
     	 
     	

     	 if(rp.size()==m-1)
     	 {
     	 	 lp.push_back(left);
     	 }	else{
              lp.pb(1);
              rp.pb(left-1);
     	 } 

     	 left = 0;
          
     }	
  }	

   //print min;

  for(int i = 0 ; i<lp.size(); i++)
  {
  	  cout<<lp[i];
  }	

  for(int  i =0; i<(m-lp.size()-rp.size())&&i<=m; i++)
  {
      cout<<0;
  }	
  for(int i = rp.size()-1 ; i>=0; i--)
  {
  	 cout<<rp[i]; 
  }	
  cout<<" ";

  for(int i = 0; i<m; i++) cout<<v[i];

  return 0;
}