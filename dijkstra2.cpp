#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
typedef long long int LL;
class Comp{
public:    
    bool operator()(pair<LL,LL> p1, pair<LL,LL> p2){
        return p1.second>p2.second;
    }
};
int main(){
    LL p = 1000*1000*1000;
    LL n,s;
    cin>>n>>s;
    vector<pair<LL,LL>> graph[n+1];
    while(true){
        LL x,y,r;
        cin>>x;
        if(x==0)break;
        cin>>y>>r;
        graph[x].push_back(make_pair(y,r));
        graph[y].push_back(make_pair(x,r));
    }
    LL cost[n+1];
    fill_n(cost,n+1,-1);
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,Comp> q;
    q.push(make_pair(s,0));
    LL total = 0;
    while(!q.empty()){
        pair<LL,LL> top = q.top();
           // cout<<top.sc<<endl;
        q.pop();
        LL dist = top.sc;
        LL p = top.fs;
        if(cost[p]==-1){
            cost[p] = top.sc;
            cout<<cost[p]<<" ";
            total += cost[p];
        }
        else continue;
        for(int i = 0; i<graph[p].size(); i++){
            top = graph[p][i];
            if(cost[top.fs]==-1){
                q.push(make_pair(top.fs,dist+top.sc));
            }
        }  
    }
        /*for(int i = 1;i<=n;i++){
            if(i!=s)cout<<cost[i]<<" ";
        }*/
    cout<<endl;
    cout<<total;
    
    return 0;
}