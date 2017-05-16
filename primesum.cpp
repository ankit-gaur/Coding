#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int primes[1000001];
    fill_n(primes, 1000001, 1);
   long long  int sum[1000001];
    fill_n(sum,1000001, 0);
    for(int i = 2; i<=sqrt(1000000); i++)
    {
        if(primes[i]==1)
        {
            int limJ = (1000000 - i*i)/i;
            for(int j = 0 ; j <=limJ ;  j++)
            {
                int x = i*i + j*i;
                primes[x] = 0;
            }    
        }    
    }
   
    for(int i = 2 ; i < 1000001 ; i++)
    {
        if(primes[i]==1)
        {
            sum[i] = sum [i-1] + i;
        }else{ sum[i] = sum[i-1]; }    
    }    
    int t; cin>>t; 
    for(int i = 0 ; i < t ; i++)
    {
        int n; cin>>n;
        
        cout<<sum[n]<<"\n";
    }    
    return 0;
}
