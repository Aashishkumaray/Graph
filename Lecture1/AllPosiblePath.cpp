#include<iostream>
#include<vector>
#include<list>
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

//dfs
void dfs(int curr,int end,vector<int>& path){
    if(curr==end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return ;
    }
    visited.insert(curr);//maek visited
    path.push_back(curr);
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return ;
}
void allPath(int src,int des){
    vector<int> v;
     dfs(src,des,v);
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
    allPath(x,y);
    //cout<<result.size();
    for(auto path:result){
        for(auto el:path){
            cout<<el<<" ";
        }
        cout<<"\n";
    }
    //display();
}