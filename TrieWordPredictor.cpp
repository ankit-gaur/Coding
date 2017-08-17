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

const int alphasize = 26;

#define indexof(c) ((int)c-(int)'a')

struct TrieNode{
	bool isLeaf = false;	
	TrieNode *children[alphasize];
};

TrieNode* getNode(){
	TrieNode* temp = (TrieNode*)malloc(sizeof(TrieNode));
	for(int i =0;i<alphasize;i++){
		temp->children[i] = NULL;
	}
	return temp;
}

void insert(TrieNode *root, const string key){

	TrieNode *crawler = root;
	for(int level =0;level<key.size(); level++){
		int ind = indexof(key[level]);
		if(crawler->children[ind]==NULL) crawler->children[ind] = getNode();
		crawler = crawler->children[ind];
	}
	crawler->isLeaf = true;//last char is leaf;

}

bool search(TrieNode * root, const string key){
	TrieNode *crawler = root;
	for(int level = 0; level<key.size(); level++){
		int ind = indexof(key[level]);
		if(crawler->children[ind]==NULL)return false;

		crawler = crawler->children[ind];
	}
	return(crawler->isLeaf);
}	
string predict(TrieNode* root, const string key){

	return "todo";
}
int main(){
	TrieNode * root = getNode();
	ifstream ir("words.txt");
	string str;
	int count = 0;
	V<string> v;
	while(ir>>str){
		insert(root,str);
		v.push_back(str);
		count++;
	}
	cout<<count<<endl;

	fov(i,v){
		if(search(root,v[i]))cout<<"Exist"<<endl; else cout<<"Doesn't exist"<<endl;
	}
	return 0;
}
