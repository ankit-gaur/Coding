#include<bits/stdc++.h>
using namespace std;

int cunt = 0;

int minTrial(int n, int f)
{
	cunt++;
   
   if(n==1) return f;
   
   if(f==1||f==0)
   return f;
   
   int worst  = 10e7;
   int minx = -1;
   for(int x = 1; x<=f; x++)
   {
      int ans = max(minTrial(n-1,x-1),minTrial(n,f-x));
      if(worst>ans){ 
      	worst = ans; 
      	minx = x;
      }
   }

 //  cout<<"for floors "<<f<<" drop from "<<minx; cout<<endl;
   return 1 + worst;

}

int main()
{
   int n,f;
   cin>>n>>f;
   int trials[n+1][f+1];
   int lcount = 0;

   
   for(int num = 1; num<=n; num++)
   {
   	 for(int flor = 0; flor<=f; flor++)
   	 {
   	 	if(flor==0||flor==1)
   	 	{
   	 		trials[num][flor] = flor;
   	 		continue;
   	 	}
   	 	if(num==1)
   	 	{
   	 		trials[num][flor] = flor;
   	 		continue;
   	 	}
   	 	int worst = 10e7;
   	 	for(int floor = 1; floor<=flor; floor++)
   	 	{    
   	 		lcount++;
   	 		int ans  =  max(trials[num-1][floor-1],trials[num][flor-floor]);
   	 		if(ans<worst) worst = ans;
   	 	}
   	 	trials[num][flor] = 1 + worst;

   	 }
   }

   cout<<endl<<trials[n][f];
   return 0;
}