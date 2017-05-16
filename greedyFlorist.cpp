/* Sample program illustrating input/output */
#include<bits/stdc++.h>
using namespace std;
int main(void){

 

//Helpers for input and output

   int n, k;
   cin >> n >> k;
    int C[n];
   for(int i = 0; i < n; i++){
      cin >> C[i];
   }
   
   int result = 0;
   sort(C,C+n);
   int flowerPerPerson = 0; 
   for(int i = 0; i<n; i=i+k)
   {
       for(int j = i; j<i+k&&j<n; j++)
       {
           result += ((i/k)+1)*C[j];
       }    
   }    
   cout << result << "\n";
   
   return 0;
}
