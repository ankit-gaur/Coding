#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int score[n];
    int total = k;
    int kthScore;

    for(int i = 0 ; i<n; i++ )
    {
    	int x; cin>>x;
    	if(i==0&&x==0){cout<<0; return 0;}

    	if(i==k-1)
    	{
    		kthScore = x;
            if(x==0) break;
    	}
    	if(i>k-1&&x==kthScore)
    	{
          total++;
    	}	
    }	
    cout<<total;
    return 0;
}