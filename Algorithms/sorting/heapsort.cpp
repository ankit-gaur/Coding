#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

void heapify(vi &v, int n,int i){

	int li = 2*i+1;
	int ri = 2*i+2;
	int mi = i; //maximum index = current child
	if(li<n&&v[li]>v[i]){ //maximum index = left child index;
		mi = li;
	}
	if(ri<n&&v[mi]<v[ri]){ //give maximum index to right child;
		mi = ri;
	}
	if(mi!=i){
		swap(v[mi],v[i]);
		heapify(v,n,mi);
	}
	return;

}
void heapsort(vi &v){
	int n = v.size();
	for(int  i = n/2-1; i>=0; i--){
		heapify(v,n,i);
	}
	for(int i = 0; i<n; i++){
		swap(v[0],v[n-1-i]);
		heapify(v,n-1-i,0);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	vi v;
	rep(i,n){
		int x; 
		cin>>x;
		v.pb(x);
	}
	heapsort(v);	
	rep(i,v.size())cout<<v[i]<<" ";
	return 0;
}
