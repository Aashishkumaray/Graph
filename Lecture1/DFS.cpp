#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;
vector<list<int> > graph;
unordered_set<int>visited;
int v;//no. of vertices

//now making connection
void add_edge(int src,int des,bool bi_dir=true){
    graph[src].push_back(des);//source-to -destination
    if(bi_dir){
        graph[des].push_back(src);//if grap is bidirectinal then destination to source connection
    }
}

//dfs
bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);//maek visited
    //corresponding to the key has not been visited yet
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){////neighbour not yet visisted ark it as visited and add it to the queue for further exploration
            bool result=dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}
bool anyPath(int src,int des){
    return dfs(src,des);
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
        add_edge(s,d,false);
    }
    cout<<"Enter the you want to check path between any vertex";
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<" \n";
    //display();
}