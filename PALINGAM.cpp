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
#define indexof(c) ((int)c- (int)'a')

bool uncommon(int a[],int b[]){
	
	rep(i,26){
		if(b[i]==0&&a[i]!=0)return true;
	}
	return false;
}
bool uncommon2(int a[],int b[]){
	rep(i,26){
		if(b[i]==0&&a[i]>=2)return true;
	}
	return false;
}
void decreaseCountA(int a[],int b[]){
	rep(i,26){
		if(b[i]==0&&a[i]>0){
			a[i]--;
			return;
		}
	}
}
bool uncommonB(int a[],int b[]){
	rep(i,26){
		if(a[i]==0&&b[i]>0)return true;
	}
	return  false;
}
int winner(int a[],int b[]){
	if(uncommon(a,b)){
		if(uncommon2(a,b)){
			return 0;
		}else{
			// a koi uncommon chaldega
			decreaseCountA(a,b);
			// b vo chalega jo a k pas nhi hai nhi to har jayega
			if(!uncommonB(a,b)) return 0; 
			else return 1; 

		}

	}

	return 1; // if no uncommon than 
}

int main(){
	int t;
	cin>>t;
	rep(i,t){
		string s,t;
		cin>>s>>t;
		if(s.size()==1){
			cout<<"B"<<endl;
			continue;
		}
		int a[26],b[26];
		fill_n(a,26,0);
		fill_n(b,26,0);
		fov(i,s){
			a[indexof(s[i])]++;
		}
		fov(i,t){
			b[indexof(t[i])]++;
		}
		if(winner(a,b))cout<<"B"<<endl; else cout<<"A"<<endl;

	}
	return 0;
}
