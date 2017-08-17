#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i,n) for(int i = 0;i<n; i++)

int getPartitionIndex(vi &v, int l, int r){
    int pivot = v[r];
    int i = l;
    for(int j = l; j<r; j++){
        if(pivot>=v[j]){
            swap(v[i],v[j]); 
            i++;
        }    
    }
    swap(v[i],v[r]);
    return i;
}

void quicksort(vi &v, int l , int r){
    if(l<r){
        int pi = getPartitionIndex(v,l,r);
        quicksort(v,l,pi-1);
        quicksort(v,pi+1,r);
    }
    return;

}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    vi v; 
	    rep(i,n){
	        int x; cin>>x; v.push_back(x);
	    }
	    quicksort(v,0,n-1);
	    rep(i,n){
	        cout<<v[i]<<" "; 
	    }
	    cout<<endl;
	}
	return 0;
}