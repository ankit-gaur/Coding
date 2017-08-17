#include<bits/stdc++.h>
#include<sys/time.h>
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

long long int curTimeMilli()
{
	timeval curTime;
	gettimeofday(&curTime, NULL);
	long long int ms = curTime.tv_sec * 1000 + curTime.tv_usec / 1000;
	return ms;
}

int main(){
	ofstream off("teststrings.txt");
	
	rep(i,1000){
		string s="";
		for(int i=0;i<100000; i++){
			int random = 97+rand()%26;
			//s = s+(char)random;
			char c = (char)random;
			off<<c;
		}
		// s+="\n";
		// off<<s;
	}
	off.close();
	return 0;
}
