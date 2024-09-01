#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int> > graph;//global
int v;//no. of vertices

//now making connection
void add_edge(int src,int des,bool bi_dir=true){
    graph[src].push_back(des);//source-to -destination
    if(bi_dir){
        graph[des].push_back(src);//if grap is bidirectinal then destination to source connection
    }
}

    //dfs
void dfs(int node,unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbor:graph[node]){
        if(not visited.count(neighbor)){
            dfs(neighbor,visited);
        }
    }
}
int connected_component(){
    int result=0;
    unordered_set<int>visited;

    for(int i=0;i<v;i++){//O(V)
        //go every vertex
        //if from a vertex we initialize a dfs ,we got one more cinnectedComponent(cc)
        if(visited.count(i)==0){
            result++;
            dfs(i,visited);//ttotal O(V+E)
        }
    }
    return result;
}
int main(){
    cout<<"ENter thenumber of vertex";
    cin>>v;
     graph.resize(v, list<int> ());
    //graph.resize(v);
    int e;
    cout<<"eneter the edge";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    cout<<connected_component()<<"\n";
}