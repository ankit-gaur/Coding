#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int getPIndex(vi &v, int a, int b)
{
    int pivot  = v[b];
    int pindex = a;
    for(int i = a; i<b; i++)
    {
        if(v[i]<=pivot)
        {
            swap(v[i],v[pindex]);
            pindex++;
        }    
    }  
    swap(v[pindex],v[b]);
    return pindex;
}
void print(vi &v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }    
    cout<<endl;
}    
void QuickSort(vi &v, int a, int b)
{   
    if(a>=b) return;
    int p = getPIndex(v, a, b);
    print(v);
    QuickSort(v, a, p-1);
    QuickSort(v, p+1, b);
}    

int main() {
    int n; 
    cin>>n;
    vi v(n);
    for(int i = 0; i<n; i++)
    {
        cin>>v[i];
     }
    QuickSort(v, 0, n-1);
    
    return 0;
}
