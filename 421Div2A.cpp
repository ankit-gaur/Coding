#include<bits/stdc++.h>
using namespace std;


int main(){
	float c, v0, v1, a,l;
	cin>>c>>v0>>v1>>a>>l;
	if(a==0){
	cout<<ceil(c/v0);
	 return 0;
	}
	int x = floor((v1-v0)/a)+1;
	int k  = x*v0 + ((x*(x-1))*a)/2;
	int n  = ceil((k-v1*x+l-c)/(l-v1));
	cout<<n;
}