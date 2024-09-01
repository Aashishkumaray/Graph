#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>

using namespace std;
vector<list<int> > graph;
unordered_set<int>visited;
vector<vector<int>> result;
int v;//no. of vertices

//now making connection
void add_edge(int src,int des,bool bi_dir=true){
    graph[src].push_back(des);//source-to -destination
    if(bi_dir){
        graph[des].push_back(src);//if grap is bidirectinal then destination to source connection
    }
}

//bfs
void bfs(int src,int des,vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    q.push(src);
    while(not q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(not visited.count(neighbour)){//if visited.count=0 then condition is true
            q.push(neighbour);
            visited.insert(neighbour);
            dist[neighbour]=dist[curr]+1;
            }
        }
    }
}

//for printing
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" → ";
        for(auto ele:graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
    
}
int main(){
    cout<<"ENter thenumber of vertex";
    cin>>v;
    // graph.size(v, list<int> ());
    graph.resize(v);
    int e;
    cout<<"eneter the edge";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    cout<<"Enter the you want to check path between any vertex";
    int x,y;
    cin>>x>>y;
    vector<int> dist;
    bfs(x,y,dist);
    //cout<<result.size();
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<dist.size();
    //display();
}