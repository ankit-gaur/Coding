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

#define indexof(c) ((int)c - (int)'A')
#define charof(i) (char)(i+(int)'A')

int main(){
	string s;
	cin>>s;
	int arr[27];
	fill_n(arr,27,0);

	for(int i = 0;i<s.size();i++){

		if(i<=25){
			if(s[i]!='?')arr[indexof(s[i])]++;
			else arr[26]++;
		}
		 if(i>=25){//i>=26
		 	if(i>25){
		 		if(s[i]!='?'){
		 			if(s[i-25]!='?')
		 				arr[indexof(s[i-25])] = max(arr[indexof(s[i-25])]-1,0);
		 			else arr[26] = max(0,arr[26]-1);
		 			arr[indexof(s[i])]++;
		 		}else{
		 			
		 			if(s[i-25]!='?')
		 				arr[indexof(s[i-25])] = max(arr[indexof(s[i-25])]-1,0);
		 			else arr[26] = max(0,arr[26]-1);
		 			arr[26]++;
		 		}
		 	}
		 	int count0 = 0;
		 	bool all1 = true;
		 	rep(j,26){
		 		if(arr[j]>1){
		 			bool all1 = false; break;
		 		}
		 		if(arr[j]==0)count0++;
		 	}
		 	if(all1&&arr[26]==count0){
		 		stack<int> q; rep(i,26)if(arr[i]==0)q.push(i);
		 		for(int j = i-25;j<=i;j++){
		 			if(s[j]=='?'){
		 				s[j] = charof(q.top()); q.pop();
		 			}
		 		}
		 		fov(j,s){
		 			if(s[j]=='?')s[j]='A';
		 		}
		 		cout<<s;
		 		return 0;
		 	}

		 }
		}	
		rep(i,27)cout<<arr[i]<<endl;
		cout<<-1;
		return 0;
	}
