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

int getNext(bool clockwise,int i){
	if(clockwise){
		if(i==3){
			return 0;
		}else{
			return i+1;
		}
	}else{
		if(i==0)return 3;
		else return i-1;
	}
}
bool check(int arr[]){

	cout<<endl;
	int p = 0;
	for(int i = 1; i<25;i++){
		if(i%4==1){
			p = arr[i];
		}else if(arr[i]!=p){
			return false;
		}
	}
	return true;
}

int main(){
	int moves[6][2][4] = { { {1,5,9,24},{3,7,11,22} },
	{{2,6,10,23}, {4,8,12,21}},
	{{13,5,17,21},{14,6,18,22}},
	{{15,7,19,23},{16,8,20,24}},
	{{3,16,10,17},{4,14,9,19}},
	{{2,13,11,20},{1,5,12,18}}
};

int arr[25];
for(int i =1;i<25;i++){
	cin>>arr[i];
}

for(int i = 0; i<6;i++){
	int my[25];
	for(int t = 1; t<25; t++){
		my[t] = arr[t];
	}
	for(int j= 0; j<2; j++){
		for(int k = 0; k<4; k++){
			my[moves[i][j][k]] = arr[moves[i][j][getNext(false,k)]];
		}
	}
	if(check(my)){
		cout<<"YES";
		return 0;
	}
}
for(int i = 0; i<6;i++){
	int my[25];
	for(int t = 1; t<25; t++){
		my[t] = arr[t];
	}
	for(int j= 0; j<2; j++){
		for(int k = 0; k<4; k++){
			my[moves[i][j][k]] = arr[moves[i][j][getNext(true,k)]];
		}
	}
	if(check(my)){
		cout<<"YES";
		return 0;
	}
}

cout<<"NO";

return 0;
}
