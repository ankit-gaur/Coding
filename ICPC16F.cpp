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

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,d,D;
		cin>>n>>m>>d>>D;
	
		int avg = ceil((double)m/n);
		// cout<<"average"<<avg; el;
		int ne = m/n;
		if(avg>=d&&avg<=D){
			int count = 0;
			int j = 1;
			for(int i =1;i<=n; i++){
				int k = ne; 
				while(k--){
					if(j>n) j = 1;
					cout<<i<<" "<<j<<endl;
					j++;
					count++;
				}
			}
			count = m - count;
			int  i = 1; 
			while(count--){
				if(j>n) j =1;
				cout<<i<<" "<<j<<endl;
				i++; j++;
			}

		}else{
			cout<<-1<<endl; continue;
		}


	}	
	return 0;
}
