#include<bits/stdc++.h>
using namespace std;

int main()
{
  double inside = 0;
  double total = 1000000;
  int l = 8000;

  for(int i = 0; i<total ; i++)
  {
      double x = rand()%(l+1) - l/2;
      double y = rand()%(l+1)- l/2;
      double dist = sqrt(x*x + y*y);
      cout<<x<<" "<<y<<" "<<dist<<endl;
      if(dist<=l/2) inside++;
  }
  cout<<4*(inside/total);
}