#include<bits/stdc++.h>
using namespace std;

#define rep(i,a) for(int i=0; i<(a); ++i) 
const int MAXN = 10000001; 

int main()
{ 

	int count[5]; 
	int left[5];
	fill_n(left,5,0);
	fill_n(count,5,0);
	int n; cin>>n;
	rep(i,n)
	{
		int s; cin>>s;
		count[s]++;
	}

	int total = 0; 

	total+= count[2]/2; 
	left[2] = count[2]%2;

	total += count[4];

	total += count[3];
    
    count[1] = count[1] - count[3];
    
    if(count[1]>0)
    { 
       
       if(left[2]==1)
       {
       	  total+=1; count[1]  -= 2;
       }

      
       if(count[1]>0){ 
       	total+=count[1]/4;
       	if(count[1]%4!=0) total++;
        //cout<<total<<" ";
       }


    }else{
    	total+=left[2];
    }	

	cout<<total;
	return 0;
}