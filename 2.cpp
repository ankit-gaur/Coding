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
	int n;
	cin>>n;
	int arr[3][7];
	bool poss[1001];
	for(int i = 0;i<1001; i++) poss[i] = false;

	for(int i = 0; i<3; i++){
		for(int j = 0; j<7; j++){
			arr[i][j] = 0;
		}
	}	
	for(int i = 0; i<n; i++){
		for(int j = 1; j<7; j++){
			int x;
			cin>>x;
			arr[i][j] = x;
			poss[x] = true;
		}
	}
/*
	for(int i = 0; i<n; i++){
		for(int j = 1; j<7; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	
	for(int i = 0; i<7; i++){
		for(int j = 0; j<7; j++){
			for(int k = 0; k<7; k++){
				int a = arr[0][i];
				int b = arr[1][j];
				int c = arr[2][k];
				int num[12];
				num[0] = a + 10*b + 100*c;
				num[1] = a + 100*b + 10*c;
				num[2] = 10*a + b + 100*c;
				num[3] = 10*a + 100*b + c;
				num[4]  = 100*a + b+ 10*c;
				num[5] = 100*a + 10*b + c;
				for(int l = 0; l<6; l++){
					poss[num[l]] = true;
				}
			}
		}
	}


	for(int i = 0; i<1000;i++){
		if(poss[i]){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
