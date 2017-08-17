#include <bits/stdc++.h>
using namespace std;

int lb(const vector<int> &v,int key){
    int l = 0, r = v.size();
    while(l<=r){
        int mid = l+(r-l)/2;
        if(v[mid]<key)l = mid+1;
        else r = mid-1;
    }
    return l;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; 
	    cin>>n;
	    vector<int> v;
	    for(int i = 0; i<n; i++){
	        int x; cin>>x;
	        v.push_back(x);
	    }
	    if(n==0){cout<<0<<endl;continue;}
	    vector<int> tail;
	    tail.push_back(v[0]);
	    for(int i = 1; i<n; i++){
	        if(v[i]<tail[0])tail[0] = v[i];
	        else if(v[i]>tail[tail.size()-1]){tail.push_back(v[i]);}
	        else {
	            int ub = lb(tail,v[i]);
	            if(ub<tail.size())
	            tail[ub] = v[i];
	        }
	    }
	    cout<<tail.size()<<endl;
	}
	
	return 0;
}